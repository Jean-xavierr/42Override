#include <stdio.h>
#include <stdlib.h>

int     main(void)
{
    int nb;
    int ret;

    puts("***********************************");
    puts("*            -Level00 -           *");
    puts("***********************************");

    printf("Password:");
    scanf("%d", &nb);

    if (nb == 0x149c) { // 5276
        puts("\nAuthenticated!");
        system("/bin/sh");
        ret = 0;
    } else {
        puts ("\nInvalid Password!");
        ret = 1;
    }

    return ret;
}