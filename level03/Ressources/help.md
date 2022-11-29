# LEVEL03

```
int     test(int password, int arg_ch)
{
    unsigned long nb = arg_ch - password;

    if (nb <= 21)
    {
        nb = nb << 2;
        nb += 0x80489f0;
        nb = *(nb);
        void (*nb)();
    }
    decrypt(rand());
    return nb;
}
```



```
level03@OverRide:~$ (python -c 'print(0x1337d00d - 18)'; cat) | ./level03 
***********************************
*               level03         **
***********************************


whoami
level04
cat /home/users/level04/.pass
kgv3tkEb9h2mLkRsPkXRfc2mHbjMxQzvb2FrgKkf
```