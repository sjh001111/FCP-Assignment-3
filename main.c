#include <stdio.h>
#include "menu.h"
#include "libs/compression.h"
#include "libs/decompression.h"
#include "libs/decryption.h"
#include "libs/encryption.h"
#include "libs/searching.h"
#include "libs/sorting.h"

int main(){
    
    int i;
    print_menu();
    scanf("%d", &i);
    menu(i);
    
    return 0;
}