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
        switch (i)
        {
        case 1:
            add_user(users, &users_count);
            break;
        case 2:
            display_users(users, &users_count);
            break;
        case 3:
            save_users(users, &users_count);
            break;
        case 4:
            read_users(users, &users_count);
            break;
        case 5:
            debug(users, &users_count);
        case 6:
            return 0;
        default:
            printf("Error: Please enter the valid number");
        }
    }
}

void print_menu()
{
    printf("\nWelcome to\n"
           "\n"
           "1. Add user (XOR encryption)\n"
           "2. Display users (XOR decryption, Sorting, Searching)\n"
           "3. Save users (Run-length compression)\n"
           "4. Read users (Run-length decompression)\n"
           "5. Debug\n"
           "5. Exit app\n"
           "Enter the number: ");
}