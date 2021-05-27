#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../user.h"
#include "huffman.h"

int alphabets;
int active;
unsigned int original_size;

int *frequency;
Node *nodes;
int *leaves;
int *parents;

int *stack;
int stack_top;

int free_index;
unsigned char buffer[MAX_BUFFER_SIZE];
int nodes_size;
int bits_in_buffer;
int current;
int eof_input;

int huffman_encode(const char *input, const char *output)
{
    FILE *fin, *fout;
    int i;

    if ((fin = fopen(input, "rb")) == NULL)
    {
        perror("  Error: No matching file\n");
        return -1;
    }

    if ((fout = fopen(output, "wb")) == NULL)
    {
        perror("  Error: No matching file\n");
        fclose(fin);
        return -1;
    }

    initialize();

    determine_frequency(fin);
    stack = (int *)calloc(active - 1, sizeof(int));
    allocate_tree();
    add_leaves();
    write_header(fout);
    build_tree();
    fseek(fin, 0, SEEK_SET);

    while ((i = fgetc(fin)) != EOF)
        encode_alphabet(fout, i);

    flush_buffer(fout);
    free(stack);
    fclose(fin);
    fclose(fout);

    nodes_size = 0;
    bits_in_buffer = 0;
    current = 0;
    eof_input = 0;
    free_index = 1;
    
    finalize();

    return 0;
}

int huffman_decode(const char *input, const char *output)
{
    FILE *fin, *fout;
    if ((fin = fopen(input, "rb")) == NULL)
    {
        perror("  Error: No matching file");
        return -1;
    }
    if ((fout = fopen(output, "wb")) == NULL)
    {
        perror("  Error: No matching file");
        fclose(fin);
        return -1;
    }

    initialize();

    if (read_header(fin) == 0)
    {
        build_tree();
        decode_bit_stream(fin, fout);
    }
    fclose(fin);
    fclose(fout);

    nodes_size = 0;
    bits_in_buffer = 0;
    current = 0;
    eof_input = 0;
    free_index = 1;

    finalize();
    
    return 0;
}

void determine_frequency(FILE *file)
{
    int i;

    while ((i = fgetc(file)) != EOF)
    {
        ++frequency[i];
        ++original_size;
    }

    for (i = 0; i < alphabets; ++i)
        if (frequency[i] > 0)
            ++active;
}

void allocate_tree()
{
    nodes = (Node *)
        calloc(2 * active, sizeof(Node));
    parents = (int *)
        calloc(active, sizeof(int));
}

void add_leaves()
{
    int i, freq;
    for (i = 0; i < alphabets; ++i)
    {
        freq = frequency[i];
        if (freq > 0)
            add_node(-(i + 1), freq);
    }
}

void build_tree()
{
    int a, b, index;
    while (free_index < nodes_size)
    {
        a = free_index++;
        b = free_index++;
        index = add_node(b / 2, nodes[a].weight + nodes[b].weight);
        parents[b / 2] = index;
    }
}

int add_node(int index, int weight)
{
    int i = nodes_size++;
    while (i > 0 && nodes[i].weight > weight)
    {
        memcpy(&nodes[i + 1], &nodes[i], sizeof(Node));
        if (nodes[i].index < 0)
            ++leaves[-nodes[i].index];
        else
            ++parents[nodes[i].index];
        --i;
    }

    ++i;
    nodes[i].index = index;
    nodes[i].weight = weight;

    if (index < 0)
        leaves[-index] = i;
    else
        parents[index] = i;

    return i;
}

void encode_alphabet(FILE *output, int character)
{
    int node_index;
    stack_top = 0;
    node_index = leaves[character + 1];
    while (node_index < nodes_size)
    {
        stack[stack_top++] = node_index % 2;
        node_index = parents[(node_index + 1) / 2];
    }
    while (--stack_top > -1)
        write_bit(output, stack[stack_top]);
}

void decode_bit_stream(FILE *input, FILE *output)
{
    int i = 0, bit, node_index = nodes[nodes_size].index;
    while (1)
    {
        bit = read_bit(input);
        if (bit == -1)
            break;
        node_index = nodes[node_index * 2 - bit].index;
        if (node_index < 0)
        {
            char c = -node_index - 1;
            fwrite(&c, 1, 1, output);
            if (++i == original_size)
                break;
            node_index = nodes[nodes_size].index;
        }
    }
}

int write_bit(FILE *file, int bit)
{
    if (bits_in_buffer == MAX_BUFFER_SIZE << 3)
    {
        size_t bytes_written =
            fwrite(buffer, 1, MAX_BUFFER_SIZE, file);
        if (bytes_written < MAX_BUFFER_SIZE && ferror(file))
            return -1;
        bits_in_buffer = 0;
        memset(buffer, 0, MAX_BUFFER_SIZE);
    }
    if (bit)
        buffer[bits_in_buffer >> 3] |=
            (0x1 << (7 - bits_in_buffer % 8));
    ++bits_in_buffer;
    return 0;
}

int read_bit(FILE *file)
{
    if (current == bits_in_buffer)
    {
        if (eof_input)
            return -1;
        else
        {
            size_t bytes_read =
                fread(buffer, 1, MAX_BUFFER_SIZE, file);
            if (bytes_read < MAX_BUFFER_SIZE)
            {
                if (feof(file))
                    eof_input = 1;
            }
            bits_in_buffer = bytes_read << 3;
            current = 0;
        }
    }

    if (bits_in_buffer == 0)
        return -1;
    int bit = (buffer[current >> 3] >>
               (7 - current % 8)) &
              0x1;
    ++current;
    return bit;
}

int write_header(FILE *file)
{
    int i, j, byte = 0,
              size = sizeof(unsigned int) + 1 +
                     active * (1 + sizeof(int));
    unsigned int weight;
    char *buffer = (char *)calloc(size, 1);
    if (buffer == NULL)
        return -1;

    j = sizeof(int);
    while (j--)
        buffer[byte++] =
            (original_size >> (j << 3)) & 0xff;
    buffer[byte++] = (char)active;
    for (i = 1; i <= active; ++i)
    {
        weight = nodes[i].weight;
        buffer[byte++] =
            (char)(-nodes[i].index - 1);
        j = sizeof(int);
        while (j--)
            buffer[byte++] =
                (weight >> (j << 3)) & 0xff;
    }
    fwrite(buffer, 1, size, file);
    free(buffer);
    return 0;
}

int read_header(FILE *file)
{
    int i, j, byte = 0, size;
    size_t bytes_read;
    unsigned char buff[4];

    bytes_read = fread(&buff, 1, sizeof(int), file);
    if (bytes_read < 1)
        return -1;
    byte = 0;
    original_size = buff[byte++];
    while (byte < sizeof(int))
        original_size =
            (original_size << (1 << 3)) | buff[byte++];

    bytes_read = fread(&active, 1, 1, file);
    if (bytes_read < 1)
        return -1;

    allocate_tree();

    size = active * (1 + sizeof(int));
    unsigned int weight;
    char *buffer = (char *)calloc(size, 1);
    if (buffer == NULL)
        return -1;
    fread(buffer, 1, size, file);
    byte = 0;
    for (i = 1; i <= active; ++i)
    {
        nodes[i].index = -(buffer[byte++] + 1);
        j = 0;
        weight = (unsigned char)buffer[byte++];
        while (++j < sizeof(int))
        {
            weight = (weight << (1 << 3)) |
                     (unsigned char)buffer[byte++];
        }
        nodes[i].weight = weight;
    }
    nodes_size = (int)active;
    free(buffer);
    return 0;
}

int flush_buffer(FILE *file)
{
    if (bits_in_buffer)
    {
        size_t bytes_written =
            fwrite(buffer, 1,
                   (bits_in_buffer + 7) >> 3, file);
        if (bytes_written < MAX_BUFFER_SIZE && ferror(file))
            return -1;
        bits_in_buffer = 0;
    }
    return 0;
}

void initialize()
{
     alphabets = 256;
 active = 0;
 original_size = 0;
 free_index = 1;
 nodes_size = 0;
 bits_in_buffer = 0;
 current = 0;
 eof_input = 0;
    frequency = (int *)
        calloc(2 * alphabets, sizeof(int));
    leaves = frequency + alphabets - 1;
}

void finalize()
{
    free(frequency);
    free(nodes);
    free(leaves);
    free(parents);
}