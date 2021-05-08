/*******************************************************************************
 * 13740802 Joonghyuk Seong
 * 
*******************************************************************************/

typedef struct User
{
    char name[64];
    char password[64];
} User;

void add_user(User users[], int *count);
void display_users(User users[], int *count);
void save_users();
void read_users();