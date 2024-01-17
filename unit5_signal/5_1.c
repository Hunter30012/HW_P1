#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void sig_handler1(int num)
{
    printf("I'm handler of SIGINT\n");
}

void my_handler(int signum)
{
    if (signum == SIGUSR1)
    {
        printf("Received SIGUSR1!\n");
    }
    else if(signum == SIGUSR2)
    {
        printf("Received SIGUSR2!\n");
    }
}

int main()
{
    if (signal(SIGINT, sig_handler1) == SIG_ERR) 
    {
		fprintf(stderr, "Cannot handle SIGINT\n");
		exit(EXIT_FAILURE);
	}
    signal(SIGUSR1, my_handler);
    signal(SIGUSR2, my_handler);
    while (1)
    {
        /* code */
    }
    return 0;
}