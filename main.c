#include <stdio.h>
#include "main.h"
#include "user.h"

int main()
{
    User users[MAX_USERS_SIZE];
    int i, users_count = 0;

    while (1)
    {
        print_menu();
        scanf("%d", &i);
        printf("\n");
        switch (i)
        {
        case 1:
            printf(
                "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
                "弛 1. Add user (XOR encryption)                          弛\n"
                "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
            add_user(users, &users_count);
            break;
        case 2:
            printf(
                "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
                "弛 2. Display users (XOR decryption, Sorting, Searching) 弛\n"
                "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
            display_users(users, &users_count);
            break;
        case 3:
            printf(
                "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
                "弛 3. Save users (Run-length compression)                弛\n"
                "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
            save_users(users, &users_count);
            break;
        case 4:
            printf(
                "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
                "弛 4. Read users (Run-length decompression)              弛\n"
                "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
            read_users(users, &users_count);
            break;
        case 5:
            printf(
                "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
                "弛 5. Debug                                              弛\n"
                "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
            debug(users, &users_count);
            break;
        case 6:
            return 0;
        default:
            printf("Error: Please enter the valid number");
        }
    }
}

void print_menu()
{
    printf(
        "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
        "弛 Welcome to UTS Uber                                   弛\n"
        "弛                                                       弛\n"
        "弛 1. Add user (XOR encryption)                          弛\n"
        "弛 2. Display users (XOR decryption, Sorting, Searching) 弛\n"
        "弛 3. Save users (Run-length compression)                弛\n"
        "弛 4. Read users (Run-length decompression)              弛\n"
        "弛 5. Debug                                              弛\n"
        "弛 6. Exit app                                           弛\n"
        "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n"
        "  Enter the number: ");
}