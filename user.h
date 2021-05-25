#ifndef USER_H
#define USER_H

#define MAX_USERS_SIZE 256
#define MAX_STRING_SIZE 256
#define DB_FILE_NAME "db.txt"

typedef struct User
{
    char name[MAX_STRING_SIZE];
    char password[MAX_STRING_SIZE];
    char card_number[MAX_STRING_SIZE];
} User;

void add_user(User users[], int *count);
void delete_user(User users[], int *count);
void display_users(User users[], int *count);
void save_users(User users[], int *count);
void read_users(User users[], int *count);
void display_debug(User users[], int *count);

#endif