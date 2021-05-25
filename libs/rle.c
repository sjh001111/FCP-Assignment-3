#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../user.h"
#include "rle.h"

char *run_length_compression(char *input)
{
    int j = 0, k, length = strlen(input), char_length;
    char count[MAX_STRING_SIZE];
    char *output = (char *)malloc(sizeof(char) * (length * 2 + 1));

    for (int i = 0; i < length; i++)
    {
        output[j++] = input[i];
        char_length = 1;
        while (i + 1 < length && input[i] == input[i + 1])
        {
            char_length++;
            i++;
        }
        sprintf(count, "%d", char_length);
        for (k = 0; *(count + k); k++, j++)
            output[j] = count[k];
    }

    output[j] = '\0';
    return output;
}

char *run_length_decompression(char *input)
{
    int j = 0, length = strlen(input);
    char temp;
    char *output = (char *)malloc(sizeof(char) * length);

    for (int i = 0; i < length; i++)
    {
        if (input[i] == '\0')
            break;
        if (i % 2)
        {
            int count = input[i] - '0';
            for (int k = 0; k < count; k++)
            {
                output[j] = temp;
                j++;
            }
        }
        else
            temp = input[i];
    }

    output[j] = '\0';
    return output;
}
