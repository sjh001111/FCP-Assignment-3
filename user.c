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

    printf("\n  You have successfully added the user.\n\n");
}

void delete_user(User users[], int *count)
{
    if (*count)
    {
        *count -= 1;
    }
    else
    {
        printf("  Error: No employee\n\n");
    }
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
        printf("\n");
    }
    else
    {
        printf("  Error: No employee\n\n");
    }
}

void save_users(User users[], int *count)
{
    FILE *fp;

    fp = fopen(DB_FILE_NAME, "w");

    for (int i = 0; i < *count; i++)
    {
        fprintf(fp, "%s\t%s\n",
                run_length_compression(users[i].name),
                run_length_compression(users[i].password));
    }

    fclose(fp);
    printf("  You have successfully saved the users to the database.\n\n");
}

void read_users(User users[], int *count)
{
    FILE *fp;
    User user;

    if ((fp = fopen(DB_FILE_NAME, "r")) == NULL)
    {
        printf("  Error: No database file\n");
        return;
    }
    *count = 0;


    for (int i = 0; i < MAX_USERS_SIZE; i++)
    {
        if (fscanf(fp, "%s\t%s",
                   user.name,
                   user.password) == 2)
        {
            strcpy(user.name, run_length_decompression(user.name));
            strcpy(user.password, run_length_decompression(user.password));

            users[i] = user;
            *count += 1;
        }
    }
    fclose(fp);
    printf("  The database has been read successfully.\n\n");
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
        printf("\n");
    }
    else
    {
        printf("  Error: No employee\n\n");
    }
}