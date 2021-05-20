/*******************************************************************************
 * 13740802 Joonghyuk Seong
 * 학번 Dongwok Hong
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../main.h"
#include "rle.h"

char *run_length_compression(char *input)
{
    int i, j = 0, k, length = strlen(input), char_length;
    char count[MAX_STRING_SIZE];
    char *output = (char *)malloc(sizeof(char) * (length * 2 + 1));

    for (i = 0; i < length; i++)
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

char *run_length_decompression(char *input){

}

/* 에러나서 실행안됨
char *run_length_decompression(char *input)
{
    char* decompression;
    int decompression_length = run_length_compression(input);
    decompression = (char*)malloc(decompression_length * sizeof(char*) + 1);

    char point;
    int count;
    int i;
    int j;
    int current_Length_Index = 0;

    for (i = 0; i < strlen(input) - 1; i++) {

        if ((input + i) != '\0') {

            sscanf(input + i, "%c%u", &point, &count);

            for (j = 0; j < count; j++) {
                *(decompression + current_Length_Index + j) = point;
            }
        }

        current_Length_Index += j;
        i += floor(log10(abs(count))) + 1;
    }

    *(decompression + decompression_length + 1) = '\0';

    return decompression;
}
}
*/