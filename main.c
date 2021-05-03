#include <stdio.h>
#include "menu.h"
#include "encryption.h"
#include "decryption.h"
#include "compression.h"
#include "decompression.h"
#include "searching.h"
#include "sorting.h"

int main(){
    
    int i;
    print_menu();
    scanf("%d", &i);
    menu(i);
    
    return 0;
}