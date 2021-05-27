#include <stdlib.h>  // malloc()
#include <string.h>  // strlen()
#include "../user.h"
#include "xor.h"

// XOR encryption & decryption
char *XOR_cipher(char *input)
{
    /* Generate a char[] that is 1 greater than the length 
     * of the input char[] (because temporary char[] needs'\0' at the end) */
    int i, j = 0, length = strlen(input);
    char *output = (char *)malloc(sizeof(char) * (length + 1));
    // Make a key called S, J, H
    char key[] = {'S', 'J', 'H'};

    for (i = 0; i < strlen(input); i++)
    {
        // XOR calculation
        output[i] = input[i] ^ key[i % (sizeof(key) / sizeof(char))];
        j++;
    }

    // Put '\0' at the end of the output to finish
    output[j] = '\0';
    return output;
}
