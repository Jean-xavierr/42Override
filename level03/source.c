#include <unistd.h>
#include <string.h>

void    decrypt(int nb)
{
    int     index;
    long    len;
    char    *str;
    
    char *str = (char *)(int [4]){ 0x757c7d51, 0x67667360, 0x7b66737e, 0x33617c7d };

    len = strlen((char *)str);
    while (0 < len) {
        str += index;
        str += index;
        index += 1;
    }
    if (strncmp("Congratulations", str, 17) == 0) {
        system("/bin/sh");
    } else {
        puts("\nInvalid Password");
    }
    return ;
}

int     test(int password, int arg_ch)
{
    unsigned long nb = arg_ch - password;

    if (nb <= 21)
    {
        nb = nb << 2;
        nb += 0x80489f0;
        nb = *(nb);
        void (*nb)();
        return 0;
    }
    decrypt(rand());
    return nb;
}


int     main(void)
{
    int password;

    srand(time(0));
    puts("***********************************");
    puts("*               level03         **");
    puts("***********************************");
    printf("Password:");
    scanf("%d", &password);
    test(password, 0x1337d00d);
    return 0;
}
