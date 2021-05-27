#include <stdio.h>   // sprintf()
#include <stdlib.h>  // malloc()
#include <string.h>  // strlen()
#include "../user.h"
#include "rle.h"

// 런렝스 인코딩
char *run_length_encode(char *input)
{
    // 입력받은 문자열의 길이x2보다 1만큼 큰 문자열을 생성
    // (런렝스 인코딩의 경우 원본 문자열보다 최대 2배 커질 수 있고,
    // 임의로 생성하는 문자열은 마지막에 '\0'를 넣어줘야해서)
    int j = 0, k, length = strlen(input), char_length;
    char *output = (char *)malloc(sizeof(char) * (length * 2 + 1));
    char count[MAX_STRING_SIZE];

    // 연속된 글자 수 세서 인코딩함
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

    // 아웃풋 마지막에 '\0' 넣어서 문자열 완성~
    output[j] = '\0';
    return output;
}

char *run_length_decode(char *input)
{
    // 입력받은 문자열의 길이x2보다 1만큼 큰 문자열을 생성
    // (런렝스 인코딩의 경우 원본 문자열보다 최대 2배 커질 수 있고,
    // 임의로 생성하는 문자열은 마지막에 '\0'를 넣어줘야해서)
    int j = 0, length = strlen(input);
    char *output = (char *)malloc(sizeof(char) * length);
    char temp;

    // 글자와 그 글자의 개수를 읽어와서 원본 문자열로 복원시킴
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

    // 아웃풋 마지막에 '\0' 넣어서 문자열 완성~
    output[j] = '\0';
    return output;
}
