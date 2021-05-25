#ifndef USER_H
#define USER_H

#define MAX_USERS_SIZE 128
#define MAX_STRING_SIZE 128
#define DB_FILE_NAME "db.txt"

typedef struct User
{
    char name[64];
    char password[64];
    char card_number[16];
} User;

void add_user(User users[], int *count);
void delete_user(User users[], int *count);
void display_users(User users[], int *count);
void save_users(User users[], int *count);
void read_users(User users[], int *count);
void debug(User users[], int *count);

#endif