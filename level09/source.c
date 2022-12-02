#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int     handle_msg(void) {
    int dest;
    int var_ch;
    
    var_ch._0_4_ = 0x8c;
    set_username((int)&dest);
    set_msg((char *)&dest);
    puts(">: Msg sent!");
    return;
}


int     secret_backdoor(void) {
    char *string;
    
    fgets(&string, 0x80, stdin);
    system(&string);
    return;
}


int     set_msg(char *dest) {
    char *src;

    bzero(src, 128);
    puts(">: Msg @Unix-Dude");
    printf(">>: ");
    fgets(&src, 1024, stdin);
    strncpy(dest, &src, (int)*(dest + 0xb4));
    return ;
}    

void        set_username(int dest)
{
    char    *s;
    int     i;
    
    bzero(s, 16);
    puts(">: Enter your username");
    printf(">>: ");
    fgets(&s, 128, stdin);
    strncpy(dest + 140, s, 41); //*(undefined *)(arg1 + 0x8c + (int64_t)(int32_t)var_4h) = *(undefined *)((int64_t)&s + (int64_t)(int32_t)var_4h);
    printf(">: Welcome, %s", dest + 0x8c);
    return;
}


int     main(void) {
    puts("--------------------------------------------\n");
    puts("|   ~Welcome to l33t-m$n ~    v1337        |\n");
    puts("--------------------------------------------");
    handle_msg();
    return 0;
}