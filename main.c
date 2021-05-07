#include <stdio.h>
#include "menu.h"
#include "user.h"
#include "libs/compression.h"
#include "libs/decompression.h"
#include "libs/decryption.h"
#include "libs/encryption.h"
#include "libs/searching.h"
#include "libs/sorting.h"

int main()
{
    int i;

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