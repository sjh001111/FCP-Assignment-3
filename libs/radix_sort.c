#include <stdio.h>
#include "../user.h"
#include "radix_sort.h"

//compares and return max
int get_max(User users[], int count)
{
    int i, max = users[0].ID;

    for (i = 1; i < count; i++)
        if (users[i].ID > max)
            max = users[i].ID;
    return max;
}

//sorts the elements inside
void count_sort(User users[], int count, int value)
{
    int i, cnt[10] = {0};
    User sorted_users[count];
//count the number of elements
    for (i = 0; i < count; i++)
        cnt[(users[i].ID / value) % 10]++;
//place the cumulative sum inside count
    for (i = 1; i < 10; i++)
        cnt[i] += cnt[i - 1];

//sort by correct order
    for (i = count - 1; i >= 0; i--)
    {
        sorted_users[cnt[(users[i].ID / value) % 10] - 1] = users[i];
        cnt[(users[i].ID / value) % 10]--;
    }
//replace the users[] by the new sorted one
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
