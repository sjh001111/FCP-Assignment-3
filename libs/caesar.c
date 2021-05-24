/*******************************************************************************
 * 학번 Myungseok Seo
 * 학번 Hong Joo Lee
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../main.h"
#include "caesar.h"

char *caesar_encryption(char *input)
{
    int i, length = strlen(input);
    char *output = (char *)malloc(sizeof(char) * (length + 1));
    for (i = 0; i < length; i++)
    {
        if (is_upper(input[i]))
            output[i] = (input[i] - 'A' + 6) % 26 + 'A';
        else if (is_lower(input[i]))
            output[i] = (input[i] - 'a' + 1) % 26 + 'a';
        else if (is_digit(*input))
            output[i] = (input[i] - '0' + 4) % 10 + '0';
        else
            output[i] = input[i];
    }

    output[i] = '\0';
    return output;
}

char *caesar_decryption(char *input)
{
    int i, length = strlen(input);
    char *output = (char *)malloc(sizeof(char) * (length + 1));
    for (i = 0; i < length; i++)
    {
        if (is_upper(input[i]))
            output[i] = (input[i] - 'A' + 20) % 26 + 'A';
        else if (is_lower(input[i]))
            output[i] = (input[i] - 'a' + 25) % 26 + 'a';
        else if (is_digit(*input))
            output[i] = (input[i] - '0' + 6) % 10 + '0';
        else
            output[i] = input[i];
    }

    output[i] = '\0';
    return output;
}

int is_upper(int c)
{
    return ((c >= 'A' && c <= 'Z'));
}
int is_lower(int c)
{
    return ((c >= 'a' && c <= 'z'));
}

int is_digit(int c)
{
    return (c >= '0' && c <= '9');
}