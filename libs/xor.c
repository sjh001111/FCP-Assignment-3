#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../user.h"
#include "xor.h"

char *XOR_cipher(char *input)
{
    int i, j = 0, length = strlen(input);
    char key[] = {'S', 'J', 'H'};
    char *output = (char *)malloc(sizeof(char) * (length * 3 + 1));

    for (i = 0; i < strlen(input); i++)
    {
        output[i] = input[i] ^ key[i % (sizeof(key) / sizeof(char))];
        j++;
    }

    output[j] = '\0';

    return output;
}