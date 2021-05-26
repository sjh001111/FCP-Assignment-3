#include <stdio.h>
#include "../user.h"
#include "radix_sort.h"

int get_max(User users[], int count)
{
    int i, max = users[0].ID;

    for (i = 1; i < count; i++)
        if (users[i].ID > max)
            max = users[i].ID;
    return max;
}

void count_sort(User users[], int count, int value)
{
    int i, cnt[10] = {0};
    User sorted_users[count];

    for (i = 0; i < count; i++)
        cnt[(users[i].ID / value) % 10]++;

    for (i = 1; i < 10; i++)
        cnt[i] += cnt[i - 1];


    for (i = count - 1; i >= 0; i--)
    {
        sorted_users[cnt[(users[i].ID / value) % 10] - 1] = users[i];
        cnt[(users[i].ID / value) % 10]--;
    }

    for (i = 0; i < count; i++)
        users[i] = sorted_users[i];
}

void radix_sort(User users[], int count)
{
    int max = get_max(users, count);
    int value;

    for (value = 1; max / value > 0; value *= 10)
        count_sort(users, count, value);
}

void show(int dataset[], int count)
{
    int i;
    for (i = 0; i < count; i++)
        printf("%d ", dataset[i]);
}