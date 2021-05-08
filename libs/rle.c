#include "main.h"
#include "rle.h"

char *run_length_compression(char *input)
{
    int rLen;
    char count[MAX_STRING_SIZE];
    int len = strlen(input);

    char *output = (char *)malloc(sizeof(char) * (len * 2 + 1));
    int i, j = 0, k;

    for (i = 0; i < len; i++)
    {
        output[j++] = input[i];
        rLen = 1;
        while (i + 1 < len && input[i] == input[i + 1])
        {
            rLen++;
            i++;
        }
        sprintf(count, "%d", rLen);
        for (k = 0; *(count + k); k++, j++)
            output[j] = count[k];
    }
    output[j] = '\0';

    return output;
}

char *run_length_decompression(char *input)
{
}
