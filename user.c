#include <stdio.h>
#include <string.h>
#include "main.h"
#include "user.h"
#include "libs/rle.h"
#include "libs/xor.h"
#include "libs/searching.h"
#include "libs/sorting.h"

void add_user(User users[], int *count)
{
    User user;
    char name[MAX_STRING_SIZE];
    char password[MAX_STRING_SIZE];

    printf("Enter name: ");
    scanf("%64s", name);
    strcpy(user.name, name);

    printf("Enter password: ");
    scanf("%64s", password);
    strcpy(user.password, XOR_cipher(password));

    users[*count] = user;
    *count += 1;

    XOR_cipher(user.password);
}

void display_users(User users[], int *count)
{
    int i;

    if (*count)
    {
        printf("Name       Encrypted password   Decrypted password  \n"
               "---------- -------------------- --------------------\n");

        for (i = 0; i < *count; i++)
        {
            printf("%-10s %-20s %-10s\n",
                   users[i].name,
                   users[i].password,
                   XOR_cipher(users[i].password));
        }
    }
    else
    {
        printf("No employee.\n");
    }
}

void save_users()
{
    char input[MAX_STRING_SIZE] = "test";
    char *output;
    output = run_length_compression(input);
    printf("%s", output);
}

void read_users()
{
}