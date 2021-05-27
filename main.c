/*
 * Lab07 G2
 *
 * 13740802 Joonghyuk Seong
 * 13659901 Min Soo Joh
 * 12700302 Dongwok Hong
 * 13659709 Hong Joo Lee
 * 13660042 Myungseok Seo
 * 
 * 1. Type "make" to build
 * 2. Type "./main.out" to run in default mode
 * 3. Type "./main.out debug" to run in debugging mode
 * 4. Type "make clean" to delete useless files
 */

#include <stdio.h>  // printf(), scanf(), getchar()
#include <string.h> // strcmp()
#include "user.h"   /* add_user(), display_users(), save_users(), read_users()
                     * sort_users(), search_user(), delete_user(), debug() */

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
    // 檜 嬴楚煎 printf л熱朝 width陛 80濠陛 剩朝等
    // 80濠 嬴楚煎 虜菟 唳辦 囀萄曖 陛絮撩檜 10璽釭晦 陽僥縑
    // 斜渠煎 舒朝啪 蜃棻堅 っ欽ц棻~
    printf(
        "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
    if (dbg)
        printf("早 Welcome to UTS Uber (Debug mode)                                    早\n");
    else
        printf("早 Welcome to UTS Uber                                                 早\n");
    printf(
        "竹收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收羊\n"
        "弛 1. Add user (XOR encryption, caesar encryption)                     弛\n"
        "弛 2. Display users (XOR decryption, caesar decryption)                弛\n"
        "弛 3. Save users (Run-length encoding)                                 弛\n"
        "弛 4. Read users (Run-length decoding)                                 弛\n"
        "弛 5. Sort users (Binary search)                                       弛\n"
        "弛 6. Search user (Radix sort)                                         弛\n"
        "弛 7. Delete user                                                      弛\n");
    if (dbg)
        printf("弛 9. Debug                                                            弛\n");
    printf(
        "弛 0. Exit app                                                         弛\n"
        "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n"
        "  Enter the number: ");
}

int menu(User users[], int *count, int i, int dbg)
{
    switch (i)
    {
    case 1:
        printf(
            "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
            "弛 1. Add user (XOR encryption, caesar encryption)                     弛\n"
            "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        add_user(users, count);
        break;
    case 2:
        printf(
            "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
            "弛 2. Display users (XOR decryption, caesar decryption)                弛\n"
            "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        display_users(users, count);
        break;
    case 3:
        printf(
            "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
            "弛 3. Save users (Run-length encoding)                                 弛\n"
            "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        save_users(users, count);
        break;
    case 4:
        printf(
            "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
            "弛 4. Read users (Run-length decoding)                                 弛\n"
            "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        read_users(users, count);
        break;
    case 5:
        printf(
            "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
            "弛 5. Sort users (Binary search)                                       弛\n"
            "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        sort_users(users, count);
        break;
    case 6:
        printf(
            "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
            "弛 6. Search user (Radix sort)                                         弛\n"
            "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        search_user(users, count);
        break;
    case 7:
        printf(
            "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
            "弛 7. Delete user                                                      弛\n"
            "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        delete_user(users, count);
        break;
    case 9:
        if (dbg)
        {
            printf(
                "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n"
                "弛 9. Debug                                                            弛\n"
                "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
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