#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    __pid_t pid_child;
    pid_child = fork();
    if(pid_child == 0)
    {
        printf("\nI'm the child process\n");
        printf("\nMy PID is: %d, My parent PID is: %d\n", getpid(), getppid());
    }
    else
    {
        printf("\nI'm the parent process\n");
        printf("\nMy PID is: %d, My parent PID is: %d\n", getpid(), getppid());
        while(1);
    }
}