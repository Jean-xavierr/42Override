#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int auth(char *login, unsigned int serial)
{
    int hash;
    
    login[strcspn(login, "\n")] = '\0';

    if (strnlen(login, 32) < 6)
        return 1;

    if (ptrace(0, 0, 0, 1) == -1) {
        puts ("\e[32m.---------------------------.");
        puts ("\e[31m| !! TAMPERING DETECTED !!  |");
        puts ("\e[32m'---------------------------'");
        return 1;
    }

    hash = ((int)login[3] ^ 0x1337U) + 0x5eeded; // 0x1337U = 4919 | 0x5eeded = 6221293 | (A ^ 4919) + 6221293 = (1376) + 6221293 = 6222669 

    for ( int i = 0 ; i < strnlen(login, 32) ; i++ ) {
        if (login[i] < ' ')
            return 1;

        hash = hash + ((int)login[i] ^ hash) % 1337;
    }

    if (serial != hash)
        return 1;

    return 0;
}



int     main(void) {

    char            login[32];
    unsigned int    serial;

    puts ("***********************************");
    puts ("*\t\tlevel06\t\t  *");
    puts ("***********************************");
    printf("-> Enter Login: ");
    fgets(login, 32, stdin);


    puts ("***********************************");
    puts ("***** NEW ACCOUNT DETECTED ********");
    puts ("***********************************");
    printf ("-> Enter Serial: ");
    scanf("%u", serial);


    if ((auth(login, serial)) == 0) {
        puts ("Authenticated!");
        system ("/bin/sh");
    }
    return 0;
}