/*******************************************************************************
 * 13740802 Joonghyuk Seong
 * 
*******************************************************************************/

typedef struct Order{
    int id;
} Order;

typedef struct User
{
    int ID[20];
    char name[64];
    char password[64];
    char card_number[16];
    // 주소, ip, 주문 배열
} User;

void add_user(User users[], int *count);
void display_users(User users[], int *count);
void save_users();
void read_users();
