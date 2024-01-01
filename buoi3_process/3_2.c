#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    __pid_t pid_child;
    int status;

    pid_child = fork();
    if(pid_child == 0)
    {
        printf("\nI'm the child process\n");
        printf("\nMy PID is: %d, My parent PID is: %d\n", getpid(), getppid());
    }
    else
    {
        wait(&status);
        printf("\nI'm the parent process\n");
        printf("\nMy PID is: %d, My parent PID is: %d\n", getpid(), getppid());
        while(1);
    }
}