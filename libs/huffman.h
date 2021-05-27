#ifndef HUFFMAN_H
#define HUFFMAN_H

#define MAX_BUFFER_SIZE 256

typedef struct
{
    int index;
    unsigned int weight;
} Node;

int huffman_encode(const char *input, const char *output);
int huffman_decode(const char *input, const char *output);

void determine_frequency(FILE *f);
void allocate_tree();
void add_leaves();
void build_tree();
int add_node(int index, int weight);

void encode_alphabet(FILE *fout, int character);
void decode_bit_stream(FILE *fin, FILE *fout);

int write_header(FILE *f);
int read_header(FILE *f);
int write_bit(FILE *f, int bit);
int read_bit(FILE *f);
int flush_buffer(FILE *f);

void initialize();
void finalize();

#endif