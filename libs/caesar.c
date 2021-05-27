#include <stdlib.h>  // malloc()
#include <string.h>  // strlen()
#include "../user.h"
#include "caesar.h"

// Caesar encryption 
char *caesar_encryption(char *input)
{
    /* Generate a char[] that is 1 greater than the length 
    of the input char[] (because temporary char[] needs'\0' at the end)*/
    int i, length = strlen(input);
    char *output = (char *)malloc(sizeof(char) * (length + 1));

    for (i = 0; i < length; i++)
    {
        // WHen it is upper case
        if (is_upper(input[i]))
            // place it 6 spaces to the back
            output[i] = (input[i] - 'A' + 6) % 26 + 'A';
        // When it is lower case
        else if (is_lower(input[i]))
            // place it 1 space to the back
            output[i] = (input[i] - 'a' + 1) % 26 + 'a';
        // When it is number
        else if (is_digit(*input))
            // place it 4 spaces to the back
            output[i] = (input[i] - '0' + 4) % 10 + '0';
        // else when it is letter
        else
            // leave it alone
            output[i] = input[i];
    }

    // Put '\0' at the end of the output to finish
    output[i] = '\0';
    return output;
}

// Caesar decryption
char *caesar_decryption(char *input)
{
      /* Generate a char[] that is 1 greater than the length 
    of the input char[] (because temporary char[] needs'\0' at the end)*/
    int i, length = strlen(input);
    char *output = (char *)malloc(sizeof(char) * (length + 1));

    for (i = 0; i < length; i++)
    {
        // When it is uppercase
        if (is_upper(input[i]))
            // place it 20 spaces to the back (= 6 spaces to the back)
            output[i] = (input[i] - 'A' + 20) % 26 + 'A';
        // when it is lowercase
        else if (is_lower(input[i]))
            // place it 25 spaces to the back (= 1 space to the front)
            output[i] = (input[i] - 'a' + 25) % 26 + 'a';
        // when it is number
        else if (is_digit(*input))
            // place it 6 spaces to the back (= 4 space to the front)
            output[i] = (input[i] - '0' + 6) % 10 + '0';
        // else when it is letter
        else
            // leave it alone
            output[i] = input[i];
    }

    // // Put '\0' at the end of the output to finish
    output[i] = '\0';
    return output;
}

// check if the char is uppercase
int is_upper(int c)
{
    return ((c >= 'A' && c <= 'Z'));
}

// check if the char is lowercase
int is_lower(int c)
{
    return ((c >= 'a' && c <= 'z'));
}

// check if the char is number
int is_digit(int c)
{
    return (c >= '0' && c <= '9');
}
