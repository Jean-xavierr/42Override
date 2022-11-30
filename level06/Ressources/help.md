# LEVEL06

```
level06@OverRide:~$ ./level06 
***********************************
*               level06           *
***********************************
-> Enter Login: login
***********************************
***** NEW ACCOUNT DETECTED ********
***********************************
-> Enter Serial: serial
level06@OverRide:~$ 
```

```
level06@OverRide:~$ ./level06 
***********************************
*               level06           *
***********************************
-> Enter Login: AAAAAA
***********************************
***** NEW ACCOUNT DETECTED ********
***********************************
-> Enter Serial: 6229050
Authenticated!
$ cat /home/users/level07/.pass
GbcPDRgsFK77LNnnuh7QyFYA2942Gp8yKj9KrWD8
```

decrypt hash with source code

https://www.onlinegdb.com/online_c_compiler


```
#include <stdio.h>

int main()
{
    char login[6] = "AAAAAA";
    unsigned int hash = 0;
    hash = ((int)login[3] ^ 0x1337U) + 0x5eeded; // 0x1337U = 4919 | 0x5eeded = 6221293 | (A ^ 4919) + 6221293 = (1376) + 6221293 = 6222669 

    for ( int i = 0 ; i < strnlen(login, 32) ; i++ ) {
        if (login[i] < ' ')
            return 1;

        hash = hash + ((int)login[i] ^ hash) % 1337;
    }
    printf("%d", hash);
}  
```