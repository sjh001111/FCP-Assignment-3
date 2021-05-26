#include <stdio.h>
#include <string.h>
#include "user.h"

void print_menu(int dbg);
int menu(User users[], int *count, int i, int dbg);

int main(int argc, char *argv[])
{
    User users[MAX_USERS_SIZE];
    int i, count = 0, dbg = 0;

    if (argc > 1 && !strcmp(argv[1], "debug"))
        dbg = 1;

    do
    {
        print_menu(dbg);
        scanf("%d", &i);
        getchar();
        printf("\n");
    } while (menu(users, &count, i, dbg));

    return 0;
}

void print_menu(int dbg)
{
    printf(
        "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
    if (dbg)
        printf("早 Welcome to UTS Uber (Debug mode)                     早\n");
    else
        printf("早 Welcome to UTS Uber                                  早\n");
    printf(
        "竹收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收羊\n"
        "弛 1. Add user (XOR encryption, caesar encryption)      弛\n"
        "弛 2. Display users (XOR decryption, caesar decryption) 弛\n"
        "弛 3. Save users (Run-length compression)               弛\n"
        "弛 4. Read users (Run-length decompression)             弛\n"
        "弛 5. Sort users (Binary search)                        弛\n"
        "弛 6. Search user (Radix sort)                          弛\n"
        "弛 7. Delete user                                       弛\n");
    if (dbg)
        printf("弛 9. Debug                                             弛\n");
    printf(
        "弛 0. Exit app                                          弛\n"
        "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n"
        "  Enter the number: ");
}

int menu(User users[], int *count, int i, int dbg)
{
    switch (i)
    {
    case 1:
        printf(
            "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
            "弛 1. Add user (XOR encryption, caesar encryption)      弛\n"
            "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        add_user(users, count);
        break;
    case 2:
        printf(
            "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
            "弛 2. Display users (XOR decryption, caesar decryption) 弛\n"
            "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        display_users(users, count);
        break;
    case 3:
        printf(
            "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
            "弛 3. Save users (Run-length compression)               弛\n"
            "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        save_users(users, count);
        break;
    case 4:
        printf(
            "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
            "弛 4. Read users (Run-length decompression)             弛\n"
            "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        read_users(users, count);
        break;
    case 5:
        printf(
            "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
            "弛 5. Sort users (Binary search)                        弛\n"
            "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        sort_users(users, count);
        break;
    case 6:
        printf(
            "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
            "弛 6. Search user (Radix sort)                          弛\n"
            "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        search_user(users, count);
        break;
    case 7:
        printf(
            "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
            "弛 7. Delete user                                       弛\n"
            "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        delete_user(users, count);
        break;
    case 9:
        if (dbg)
        {
            printf(
                "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
                "弛 9. Debug                                             弛\n"
                "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
            debug(users, count);
        }
        break;
    case 0:
        return 0;
    default:
        printf("  Error: Please enter the valid number\n\n");
    }
    return 1;
}