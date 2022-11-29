#include <sys/types.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ptrace.h>

int     main(void)
{
    char    s[32];
    int     status;
    int     ret_ptrace;
    pid_t   pid;

    ret_ptrace = 0;
    status = 0;
    if ((pid = fork()) == 0) {
        // child process
        prctl(1, 1);
        ptrace(PTRACE_TRACEME, 0, 0, 0);
        puts("Give me some shellcode, k");
        gets(s);
        return 0;
    } else {
        // parent process
        do {
            wait(&status);
            if (((status & 127) == 0) || (((status & 127) +1) >> 1 == 0)) { 
                puts("child is exiting...");
                return 0;
            }
            ret_ptrace = ptrace(PTRACE_PEEKUSER, pid, 44, 0);
        } while (ret_ptrace != 11);
        puts("no exec() for you");
        kill(pid, 9);
    }
    return 0;
}