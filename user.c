/*******************************************************************************
 * 13740802 Joonghyuk Seong
*******************************************************************************/

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

    printf("  Enter name: ");
    scanf("%64s", name);
    strcpy(user.name, name);

    printf("  Enter password: ");
    scanf("%64s", password);
    strcpy(user.password, XOR_cipher(password));

    users[*count] = user;
    *count += 1;

    printf("\n  User added successfully\n");
}

void display_users(User users[], int *count)
{
    if (*count)
    {
        printf("  Name       Encrypted password  \n"
               "  ---------- --------------------\n");

        for (int i = 0; i < *count; i++)
        {
            printf("  %-10s %-20s\n",
                   users[i].name,
                   users[i].password);
        }
    }
    else
    {
        printf("  No employee.\n");
    }
}

void save_users(User users[], int *count)
{
    FILE *fp;

    fp = fopen(DB_FILE_NAME, "w");

    for (int i = 0; i < *count; i++)
    {
        fprintf(fp, "%s %s\n",
                run_length_compression(users[i].name),
                run_length_compression(users[i].password));
    }

    fclose(fp);
}

void read_users(User users[], int *count)
{
    FILE *fp;
    User user;

    if ((fp = fopen(DB_FILE_NAME, "r")) == NULL)
    {
        printf("  Read error\n");
        return;
    }
    *count = 0;

    for (int i = 0; i < MAX_USERS_SIZE; i++)
    {
        if (fscanf(fp, "%s %s",
                   run_length_decompression(users[i].name),
                   run_length_decompression(users[i].password)) == 2)
        {
            users[i] = user;
            *count += 1;
        }
    }

    fclose(fp);
}

void debug(User users[], int *count)
{
    if (*count)
    {
        printf("  Name       Encrypted password   Decrypted password  \n"
               "  ---------- -------------------- --------------------\n");

        for (int i = 0; i < *count; i++)
        {
            printf("  %-10s %-20s %-10s\n",
                   users[i].name,
                   users[i].password,
                   XOR_cipher(users[i].password));
        }
    }
    else
    {
        printf("  No employee.\n");
    }
}