#include <stdio.h>
#include "menu.h"
#include "user.h"

#define MAX_USERS_SIZE 100

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
            add_user();
            break;
        case 2:
            display_users();
            break;
        case 3:
            save_users();
            break;
        case 4:
            read_users();
            break;
        case 5:
            return 0;
        default:
            printf("Error: Please enter the valid number");
        }
    }
}