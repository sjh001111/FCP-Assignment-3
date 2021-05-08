#include <string.h>
#include "main.h"
#include "xor.h"

void XOR_cipher(char *input, char *output)
{
    char key[] = {'S', 'J', 'H'};

    int i;
    for (i = 0; i < strlen(input); i++)
        output[i] = input[i] ^ key[i % (sizeof(key) / sizeof(char))];
}