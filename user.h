typedef struct User
{
    char name[64];
    char password[64];
} User;

void add_user();
void display_users();
void save_users();
void read_users();