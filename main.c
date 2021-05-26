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
        "����������������������������������������������������������������������������������������������������������������\n");
    if (dbg)
        printf("�� Welcome to UTS Uber (Debug mode)                     ��\n");
    else
        printf("�� Welcome to UTS Uber                                  ��\n");
    printf(
        "�˦�������������������������������������������������������������������������������������������������������������\n"
        "�� 1. Add user (XOR encryption, caesar encryption)      ��\n"
        "�� 2. Display users (XOR decryption, caesar decryption) ��\n"
        "�� 3. Save users (Run-length compression)               ��\n"
        "�� 4. Read users (Run-length decompression)             ��\n"
        "�� 5. Sort users (Binary search)                        ��\n"
        "�� 6. Search user (Radix sort)                          ��\n"
        "�� 7. Delete user                                       ��\n");
    if (dbg)
        printf("�� 9. Debug                                             ��\n");
    printf(
        "�� 0. Exit app                                          ��\n"
        "����������������������������������������������������������������������������������������������������������������\n"
        "  Enter the number: ");
}

int menu(User users[], int *count, int i, int dbg)
{
    switch (i)
    {
    case 1:
        printf(
            "����������������������������������������������������������������������������������������������������������������\n"
            "�� 1. Add user (XOR encryption, caesar encryption)      ��\n"
            "����������������������������������������������������������������������������������������������������������������\n");
        add_user(users, count);
        break;
    case 2:
        printf(
            "����������������������������������������������������������������������������������������������������������������\n"
            "�� 2. Display users (XOR decryption, caesar decryption) ��\n"
            "����������������������������������������������������������������������������������������������������������������\n");
        display_users(users, count);
        break;
    case 3:
        printf(
            "����������������������������������������������������������������������������������������������������������������\n"
            "�� 3. Save users (Run-length compression)               ��\n"
            "����������������������������������������������������������������������������������������������������������������\n");
        save_users(users, count);
        break;
    case 4:
        printf(
            "����������������������������������������������������������������������������������������������������������������\n"
            "�� 4. Read users (Run-length decompression)             ��\n"
            "����������������������������������������������������������������������������������������������������������������\n");
        read_users(users, count);
        break;
    case 5:
        printf(
            "����������������������������������������������������������������������������������������������������������������\n"
            "�� 5. Sort users (Binary search)                        ��\n"
            "����������������������������������������������������������������������������������������������������������������\n");
        sort_users(users, count);
        break;
    case 6:
        printf(
            "����������������������������������������������������������������������������������������������������������������\n"
            "�� 6. Search user (Radix sort)                          ��\n"
            "����������������������������������������������������������������������������������������������������������������\n");
        search_user(users, count);
        break;
    case 7:
        printf(
            "����������������������������������������������������������������������������������������������������������������\n"
            "�� 7. Delete user                                       ��\n"
            "����������������������������������������������������������������������������������������������������������������\n");
        delete_user(users, count);
        break;
    case 9:
        if (dbg)
        {
            printf(
                "����������������������������������������������������������������������������������������������������������������\n"
                "�� 9. Debug                                             ��\n"
                "����������������������������������������������������������������������������������������������������������������\n");
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