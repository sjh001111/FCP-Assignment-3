#include <stdio.h>
#include <string.h>
#include "user.h"

void print_menu(int debug);
int menu(User users[], int *count, int i, int debug);

int main(int argc, char *argv[])
{
    User users[MAX_USERS_SIZE];
    int i, count = 0, debug = 0;

    if (argc > 1 && !strcmp(argv[1], "debug"))
        debug = 1;

    do
    {
        print_menu(debug);
        scanf("%d", &i);
        getchar();
        printf("\n");
    } while (menu(users, &count, i, debug));

    return 0;
}

void print_menu(int debug)
{
    printf(
        "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n"
        "早 Welcome to UTS Uber                                                      早\n"
        "竹收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收羊\n"
        "弛 1. Add user (XOR encryption, caesar encryption)                          弛\n"
        "弛 2. Display users (XOR decryption, caesar decryption, Sorting, Searching) 弛\n"
        "弛 3. Save users (Run-length compression)                                   弛\n"
        "弛 4. Read users (Run-length decompression)                                 弛\n"
        "弛 5. Delete user                                                           弛\n");
    if (debug)
        printf(
            "弛 6. Debug                                                                 弛\n");
    printf(
        "弛 7. Exit app                                                              弛\n"
        "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n"
        "  Enter the number: ");
}

int menu(User users[], int *count, int i, int debug)
{
    switch (i)
    {
    case 1:
        printf(
            "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
            "弛 1. Add user (XOR encryption, caesar encryption)                          弛\n"
            "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        add_user(users, count);
        break;
    case 2:
        printf(
            "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
            "弛 2. Display users (XOR decryption, caesar decryption, Sorting, Searching) 弛\n"
            "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        display_users(users, count);
        break;
    case 3:
        printf(
            "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
            "弛 3. Save users (Run-length compression)                                   弛\n"
            "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        save_users(users, count);
        break;
    case 4:
        printf(
            "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
            "弛 4. Read users (Run-length decompression)                                 弛\n"
            "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        read_users(users, count);
        break;
    case 5:
        printf(
            "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
            "弛 5. Delete user                                                           弛\n"
            "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        delete_user(users, count);
        break;
    case 6:
        if (debug)
        {
            printf(
                "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
                "弛 6. Debug                                                                 弛\n"
                "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
            debug(users, count);
        }
        break;
    case 7:
        return 0;
    default:
        printf("  Error: Please enter the valid number\n\n");
    }
    return 1;
}