#include <stdio.h>
#include <string.h>
#include "main.h"
#include "user.h"
#include "libs/rle.h"
#include "libs/xor.h"
#include "libs/caesar.h"
#include "libs/searching.h"
#include "libs/sorting.h"

void add_user(User users[], int *count)
{
    User user;
    char name[MAX_STRING_SIZE];
    char password[MAX_STRING_SIZE];
    char card_number[MAX_STRING_SIZE];

    printf("  Enter name: ");
    scanf("%64s", name);
    strcpy(user.name, name);

    printf("  Enter password: ");
    scanf("%64s", password);
    strcpy(user.password, XOR_cipher(password));

    printf("  Enter card number: ");
    scanf("%64s", card_number);
    strcpy(user.card_number, caesar_encryption(card_number));

    users[*count] = user;
    *count += 1;

    printf("\n  You have successfully added the user.\n\n");
}

void delete_user(User users[], int *count)
{
    if (*count)
    {
        *count -= 1;
        printf("  You have successfully deleted the user.\n\n");
    }
    else
        printf("  Error: No employee\n\n");
}

void display_users(User users[], int *count)
{
    if (*count)
    {
        printf("  Name                 Encrypted password   Encrypted card num  \n"
               "  -------------------- -------------------- --------------------\n");

        for (int i = 0; i < *count; i++)
        {
            printf("  %-20s %-20s %-20s\n",
                   users[i].name,
                   users[i].password,
                   users[i].card_number);
        }
        printf("\n");
    }
    else
        printf("  Error: No employee\n\n");
}

void save_users(User users[], int *count)
{
    FILE *fp;

    fp = fopen(DB_FILE_NAME, "w");

    for (int i = 0; i < *count; i++)
    {
        fprintf(fp, "%s|%s|%s\n",
                run_length_compression(users[i].name),
                run_length_compression(users[i].password),
                run_length_compression(users[i].card_number));
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
        if (fscanf(fp, "%[^|]|%[^|]|%[^|]",
                   user.name,
                   user.password) == 2)
        {
            strcpy(user.name, run_length_decompression(user.name));
            strcpy(user.password, run_length_decompression(user.password));
            strcpy(user.password, run_length_decompression(user.card_number));

            users[i] = user;
            *count += 1;
        }
    }
    fclose(fp);
    printf("  The database has been read successfully.\n\n");
}

void debug(User users[], int *count)
{
    display_users(users, count);
    if (*count)
    {
        printf("  Name                 Decrypted password   Decrypted card num  \n"
               "  -------------------- -------------------- --------------------\n");

        for (int i = 0; i < *count; i++)
        {
            printf("  %-20s %-20s %-10s\n",
                   users[i].name,
                   XOR_cipher(users[i].password),
                   caesar_decryption(users[i].card_number));
        }
        printf("\n");
    }
    else
    {
        printf("  Error: No employee\n\n");
    }
}