#include <stdio.h>
#include <string.h>
#include "main.h"
#include "user.h"
#include "libs/rle.h"
#include "libs/xor.h"
#include "libs/searching.h"
#include "libs/sorting.h"

void add_user(User users[], int *count)
{
    User user;
    char name[MAX_STRING_SIZE];
    char password[MAX_STRING_SIZE];

    printf("Enter name: ");
    scanf("%64s", name);
    strcpy(user.name, name);

    printf("Enter password: ");
    scanf("%64s", password);
    strcpy(user.password, password);

    users[*count] = user;
    *count += 1;
}

void display_users()
{
}

void save_users()
{
}

void read_users()
{
}