#include <stdlib.h>  // malloc()
#include <string.h>  // strlen()
#include "../user.h"
#include "xor.h"

// xor 암호화 & 복호화
char *XOR_cipher(char *input)
{
    // 입력받은 문자열의 길이보다 1만큼 큰 문자열을 생성 (임의로 생성하는 문자열은 마지막에 '\0'를 넣어줘야해서)
    int i, j = 0, length = strlen(input);
    char *output = (char *)malloc(sizeof(char) * (length + 1));
    // S, J, H라는 키 생성
    char key[] = {'S', 'J', 'H'};

    for (i = 0; i < strlen(input); i++)
    {
        // xor 연산
        output[i] = input[i] ^ key[i % (sizeof(key) / sizeof(char))];
        j++;
    }

    // 아웃풋 마지막에 '\0' 넣어서 문자열 완성~
    output[j] = '\0';
    return output;
}