typedef struct User
{
    char first_name[16];
    char last_name[16];
    char card_num[16];
    int cvc;
} User;

void add_user();
void display_users();
void save_users();
void read_users();