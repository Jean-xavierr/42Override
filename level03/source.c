#include <unistd.h>
#include <string.h>

void    decrypt(int nb)
{
    char *str;
    
    if (strncmp("Congratulations", str, 17)) {
        system("/bin/sh");
    } else {
        puts("\nInvalid Password");
    }
}

int     test(int format, int arg_ch)
{
    int nb = arg_ch - format;

    if (nb <= 21)
    {
        nb = nb << 2;
        nb += 0x80489f0;
        nb = *(nb);
        void (*nb)();
    }
    nb = rand();
    decrypt(nb);
    return nb;
}


int     main(void)
{
    char    *format;

    srand(time(0));
    puts("***********************************");
    puts("*               level03         **");
    puts("***********************************");
    printf("Password:");
    scanf(format,100);
    test(format, 100);
    return 0;
}
