#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../user.h"
#include "caesar.h"

// 카이사르 암호화
char *caesar_encryption(char *input)
{
    // 입력받은 문자열의 길이보다 1만큼 큰 문자열을 생성 (임의로 생성하는 문자열은 마지막에 '\0'를 넣어줘야해서)
    int i, length = strlen(input);
    char *output = (char *)malloc(sizeof(char) * (length + 1));

    for (i = 0; i < length; i++)
    {
        // 대문자일 경우
        if (is_upper(input[i]))
            // 6칸 뒤로 밂
            output[i] = (input[i] - 'A' + 6) % 26 + 'A';
        // 소문자일 경우
        else if (is_lower(input[i]))
            // 1칸 뒤로 밂
            output[i] = (input[i] - 'a' + 1) % 26 + 'a';
        // 숫자일 경우
        else if (is_digit(*input))
            // 4칸 뒤로 밂
            output[i] = (input[i] - '0' + 4) % 10 + '0';
        // 그 외의 문자일 경우
        else
            // 그대로 내비 둠
            output[i] = input[i];
    }

    // 아웃풋 마지막에 '\0' 넣어서 문자열 완성~
    output[i] = '\0';
    return output;
}

// 카이사르 복호화
char *caesar_decryption(char *input)
{
    // 입력받은 문자열의 길이보다 1만큼 큰 문자열을 생성 (임의로 생성하는 문자열은 마지막에 '\0'를 넣어줘야해서)
    int i, length = strlen(input);
    char *output = (char *)malloc(sizeof(char) * (length + 1));

    for (i = 0; i < length; i++)
    {
        // 대문자일 경우
        if (is_upper(input[i]))
            // 20칸 뒤로 밂 (= 6칸 당김)
            output[i] = (input[i] - 'A' + 20) % 26 + 'A';
        // 소문자일 경우
        else if (is_lower(input[i]))
            // 25칸 뒤로 밂 (= 1칸 당김)
            output[i] = (input[i] - 'a' + 25) % 26 + 'a';
        // 숫자일 경우
        else if (is_digit(*input))
            // 6칸 뒤로 밂 (= 4칸 당김)
            output[i] = (input[i] - '0' + 6) % 10 + '0';
        // 그 외의 문자일 경우
        else
            // 그대로 내비 둠
            output[i] = input[i];
    }

    // 아웃풋 마지막에 '\0' 넣어서 문자열 완성~
    output[i] = '\0';
    return output;
}

// char이 대문자인지 판단하는 함수
int is_upper(int c)
{
    return ((c >= 'A' && c <= 'Z'));
}

// char이 소문자인지 판단하는 함수
int is_lower(int c)
{
    return ((c >= 'a' && c <= 'z'));
}

// char이 숫자인지 판단하는 함수
int is_digit(int c)
{
    return (c >= '0' && c <= '9');
}