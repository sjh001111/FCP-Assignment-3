#include <stdio.h>   // sprintf()
#include <stdlib.h>  // malloc()
#include <string.h>  // strlen()
#include "../user.h"
#include "rle.h"

// run-length encoding
char *run_length_encode(char *input)
{
    // Make a char[] with the length of twice + 1 of the inserted char[] length
    // Because run-length encoding can be twice the bigger than the original char[]
    // and the temporary made char[] must have a '\0' ate the end
    int j = 0, k, length = strlen(input), char_length;
    char *output = (char *)malloc(sizeof(char) * (length * 2 + 1));
    char count[MAX_STRING_SIZE];

    // Count the repeated char and encodes
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

    // output[] is made with the'\0' at the end
    output[j] = '\0';
    return output;
}

char *run_length_decode(char *input)
{
    // Make a char[] with the length of twice + 1 of the inserted char[] length
    // Because run-length encoding can be twice the bigger than the original char[]
    // and the temporary made char[] must have a '\0' ate the end
    int j = 0, length = strlen(input);
    char *output = (char *)malloc(sizeof(char) * length);
    char temp;

    // Read the character and the number of it to restore it to the original char[]
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

    // output[] is made with the'\0' at the end
    output[j] = '\0';
    return output;
}
