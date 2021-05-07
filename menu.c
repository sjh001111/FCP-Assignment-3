/*******************************************************************************
 * 13740802 Joonghyuk Seong
 * 
*******************************************************************************/

#include <stdio.h>
#include "menu.h"

void print_menu()
{
    printf("Welcome to 조민수 바보\n"
           "\n"
           "1. Add user (XOR encryption)\n"
           "2. Display users (XOR decryption, Sorting, Searching)\n"
           "3. Save users (Run-length compression)\n"
           "4. Read users (Run-length decompression)\n");
}

void menu(int i)
{
    switch (i)
    {
    case 1:
    case 2:
    default:
        printf("error");
    }
}