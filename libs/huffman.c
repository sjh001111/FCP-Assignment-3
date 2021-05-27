#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../user.h"
#include "huffman.h"

int num_alphabets = 256;
int num_active = 0;
int *frequency = NULL;
unsigned int original_size = 0;
Node *nodes = NULL;
int num_nodes = 0;
int *leaf_index = NULL;
int *parent_index = NULL;
int free_index = 1;
int *stack;
int stack_top;
unsigned char buffer[MAX_BUFFER_SIZE];
int bits_in_buffer = 0;
int current_bit = 0;
int eof_input = 0;

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

    determine_frequency(fin);
    stack = (int *)calloc(num_active - 1, sizeof(int));
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

    if (read_header(fin) == 0)
    {
        build_tree();
        decode_bit_stream(fin, fout);
    }
    fclose(fin);
    fclose(fout);

    return 0;
}

void determine_frequency(FILE *f)
{
    int i;

    while ((i = fgetc(f)) != EOF)
    {
        ++frequency[i];
        ++original_size;
    }

    for (i = 0; i < num_alphabets; ++i)
        if (frequency[i] > 0)
            ++num_active;
}

void allocate_tree()
{
    nodes = (Node *)
        calloc(2 * num_active, sizeof(Node));
    parent_index = (int *)
        calloc(num_active, sizeof(int));
}

void add_leaves()
{
    int i, freq;
    for (i = 0; i < num_alphabets; ++i)
    {
        freq = frequency[i];
        if (freq > 0)
            add_node(-(i + 1), freq);
    }
}

void build_tree()
{
    int a, b, index;
    while (free_index < num_nodes)
    {
        a = free_index++;
        b = free_index++;
        index = add_node(b / 2, nodes[a].weight + nodes[b].weight);
        parent_index[b / 2] = index;
    }
}

int add_node(int index, int weight)
{
    int i = num_nodes++;
    while (i > 0 && nodes[i].weight > weight)
    {
        memcpy(&nodes[i + 1], &nodes[i], sizeof(Node));
        if (nodes[i].index < 0)
            ++leaf_index[-nodes[i].index];
        else
            ++parent_index[nodes[i].index];
        --i;
    }

    ++i;
    nodes[i].index = index;
    nodes[i].weight = weight;
    if (index < 0)
        leaf_index[-index] = i;
    else
        parent_index[index] = i;

    return i;
}

void encode_alphabet(FILE *fout, int character)
{
    int node_index;
    stack_top = 0;
    node_index = leaf_index[character + 1];
    while (node_index < num_nodes)
    {
        stack[stack_top++] = node_index % 2;
        node_index = parent_index[(node_index + 1) / 2];
    }
    while (--stack_top > -1)
        write_bit(fout, stack[stack_top]);
}

void decode_bit_stream(FILE *fin, FILE *fout)
{
    int i = 0, bit, node_index = nodes[num_nodes].index;
    while (1)
    {
        bit = read_bit(fin);
        if (bit == -1)
            break;
        node_index = nodes[node_index * 2 - bit].index;
        if (node_index < 0)
        {
            char c = -node_index - 1;
            fwrite(&c, 1, 1, fout);
            if (++i == original_size)
                break;
            node_index = nodes[num_nodes].index;
        }
    }
}

int write_bit(FILE *f, int bit)
{
    if (bits_in_buffer == MAX_BUFFER_SIZE << 3)
    {
        size_t bytes_written =
            fwrite(buffer, 1, MAX_BUFFER_SIZE, f);
        if (bytes_written < MAX_BUFFER_SIZE && ferror(f))
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

int read_bit(FILE *f)
{
    if (current_bit == bits_in_buffer)
    {
        if (eof_input)
            return -1;
        else
        {
            size_t bytes_read =
                fread(buffer, 1, MAX_BUFFER_SIZE, f);
            if (bytes_read < MAX_BUFFER_SIZE)
            {
                if (feof(f))
                    eof_input = 1;
            }
            bits_in_buffer = bytes_read << 3;
            current_bit = 0;
        }
    }

    if (bits_in_buffer == 0)
        return -1;
    int bit = (buffer[current_bit >> 3] >>
               (7 - current_bit % 8)) &
              0x1;
    ++current_bit;
    return bit;
}

int write_header(FILE *f)
{
    int i, j, byte = 0,
              size = sizeof(unsigned int) + 1 +
                     num_active * (1 + sizeof(int));
    unsigned int weight;
    char *buffer = (char *)calloc(size, 1);
    if (buffer == NULL)
        return -1;

    j = sizeof(int);
    while (j--)
        buffer[byte++] =
            (original_size >> (j << 3)) & 0xff;
    buffer[byte++] = (char)num_active;
    for (i = 1; i <= num_active; ++i)
    {
        weight = nodes[i].weight;
        buffer[byte++] =
            (char)(-nodes[i].index - 1);
        j = sizeof(int);
        while (j--)
            buffer[byte++] =
                (weight >> (j << 3)) & 0xff;
    }
    fwrite(buffer, 1, size, f);
    free(buffer);
    return 0;
}

int read_header(FILE *f)
{
    int i, j, byte = 0, size;
    size_t bytes_read;
    unsigned char buff[4];

    bytes_read = fread(&buff, 1, sizeof(int), f);
    if (bytes_read < 1)
        return -1;
    byte = 0;
    original_size = buff[byte++];
    while (byte < sizeof(int))
        original_size =
            (original_size << (1 << 3)) | buff[byte++];

    bytes_read = fread(&num_active, 1, 1, f);
    if (bytes_read < 1)
        return -1;

    allocate_tree();

    size = num_active * (1 + sizeof(int));
    unsigned int weight;
    char *buffer = (char *)calloc(size, 1);
    if (buffer == NULL)
        return -1;
    fread(buffer, 1, size, f);
    byte = 0;
    for (i = 1; i <= num_active; ++i)
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
    num_nodes = (int)num_active;
    free(buffer);
    return 0;
}

int flush_buffer(FILE *f)
{
    if (bits_in_buffer)
    {
        size_t bytes_written =
            fwrite(buffer, 1,
                   (bits_in_buffer + 7) >> 3, f);
        if (bytes_written < MAX_BUFFER_SIZE && ferror(f))
            return -1;
        bits_in_buffer = 0;
    }
    return 0;
}

void initialize()
{
    frequency = (int *)
        calloc(2 * num_alphabets, sizeof(int));
    leaf_index = frequency + num_alphabets - 1;
}

void finalize()
{
    free(parent_index);
    free(frequency);
    free(nodes);
}