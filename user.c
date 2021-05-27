#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "libs/rle.h"
#include "libs/huffman.h"
#include "libs/xor.h"
#include "libs/caesar.h"
#include "libs/binary_search.h"
#include "libs/radix_sort.h"

//add new user information and is encrypted
void add_user(User users[], int *count)
{
    User user;
    int ID, check;
    char name[MAX_STRING_SIZE];
    char password[MAX_STRING_SIZE];
    char card_number[MAX_STRING_SIZE];

    do
    {
        check = 0;
        ID = rand() % MAX_USERS_SIZE + 1;
        for (int i = 0; i < *count; i++)
            if (ID == users[i].ID)
                check = 1;
    } while (check);

    printf("  User ID: %d\n", ID);
    user.ID = ID;

    printf("  Enter name: ");
    scanf("%64s", name);
    strcpy(user.name, name);

    printf("  Enter password: ");
    scanf("%64s", password);
    strcpy(user.password, caesar_encryption(password));

    while (1)
    {
        printf("  Enter card number: ");
        scanf("%16s", card_number);
        long long num = atoll(card_number);
        if (num >= 100000000000000 && num <= 9999999999999999)
        {
            strcpy(user.card_number, XOR_cipher(card_number));
            break;
        }
        else
        {
            printf("\n  Error: Please enter the valid card number\n\n");
        }
    }
    users[*count] = user;
    *count += 1;

    printf("\n  You have successfully added the user.\n\n");
}
//display users in the program
void display_users(User users[], int *count)
{
    if (*count)
    {
        printf("   ID ¦¢ Name               ¦¢ Encrypted password ¦¢ Encrypted card num \n"
               "  ¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n");

        for (int i = 0; i < *count; i++)
        {
            printf("  %4d %20.20s %20.20s %20.20s\n",
                   users[i].ID,
                   users[i].name,
                   users[i].password,
                   users[i].card_number);
        }
        printf("\n");
    }
    else
        printf("  Error: No employee\n\n");
}
// saves the user in the program to the database(.txt)
void save_users(User users[], int *count)
{
    FILE *fp;

    fp = fopen(RLE_DB_FILE_NAME, "w");

    for (int i = 0; i < *count; i++)
    {
        fprintf(fp, "%d\t%s\t%s\t%s\t\n",
                users[i].ID,
                run_length_encode(users[i].name),
                run_length_encode(users[i].password),
                run_length_encode(users[i].card_number));
    }

    fclose(fp);
    huffman_encode(RLE_DB_FILE_NAME, HUFFMAN_DB_FILE_NAME);
    printf("  You have successfully saved the users to the database.\n\n");
}
//brings user information from the database(.txt) to the program
void read_users(User users[], int *count)
{
    FILE *fp;
    User user;

    huffman_decode(HUFFMAN_DB_FILE_NAME, RLE_DB_FILE_NAME);

    if ((fp = fopen(RLE_DB_FILE_NAME, "r")) == NULL)
    {
        printf("  Error: No database file\n");
        return;
    }

    *count = 0;

    for (int i = 0; i < MAX_USERS_SIZE; i++)
    {            
        if (fscanf(fp, "%d\t%[^\t]\t%[^\t]\t%[^\t]\t",
                   &user.ID,
                   user.name,
                   user.password,
                   user.card_number) == 4)
        {
            strcpy(user.name, run_length_decode(user.name));
            strcpy(user.password, run_length_decode(user.password));
            strcpy(user.card_number, run_length_decode(user.card_number));

            users[i] = user;
            *count += 1;
        }
    }

    fclose(fp);
    printf("  The database has been read successfully.\n\n");
}
// sorts the user by ID.
void sort_users(User users[], int *count)
{
    radix_sort(users, *count);
    printf("  Users have been sorted successfully.\n\n");
}
// Search the user by ID
void search_user(User users[], int *count)
{
    int ID;

    printf("  Enter the ID to find : ");
    scanf("%d", &ID);
    int index = binary_search(users, *count, ID);

    if (index != -1)
        printf("   ID ¦¢ Name               ¦¢ Encrypted password ¦¢ Encrypted card num \n"
               "  ¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n"
               "  %4d %20.20s %20.20s %20.20s\n\n",
               users[index].ID,
               users[index].name,
               users[index].password,
               users[index].card_number);
    else
        printf("  Error: No matching ID\n\n");
}
// Delete the last user saved in the program
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
// decrypted user information is shown 
void debug(User users[], int *count)
{
    printf("  File : %s\n"
           "  Func : %s()\n"
           "  Line : %05d\n\n",
           __FILE__, __func__, __LINE__);

    display_users(users, count);
    if (*count)
    {
        printf("   ID ¦¢ Name               ¦¢ Decrypted password ¦¢ Decrypted card num \n"
               "      ¦¢                    ¦¢ (Caesar Cipher)    ¦¢ (XOR Cipher)       \n"
               "  ¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n");

        for (int i = 0; i < *count; i++)
        {
            printf("  %4d %20.20s %20.20s %20.20s\n",
                   users[i].ID,
                   users[i].name,
                   caesar_decryption(users[i].password),
                   XOR_cipher(users[i].card_number));
        }
        printf("\n");
    }
}
