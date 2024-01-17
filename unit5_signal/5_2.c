#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

void sig_handler1(int signum)
{
    printf("Im signal handler1\n");
    exit(EXIT_SUCCESS);
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
    sigset_t sig_old;
    sigset_t sig_new;

    sigemptyset(&sig_old);
    sigemptyset(&sig_new);

    if (signal(SIGINT, sig_handler1) == SIG_ERR) 
    {
		fprintf(stderr, "Cannot handle SIGINT\n");
		exit(EXIT_FAILURE);
	}

    if (sigprocmask(SIG_SETMASK, NULL, &sig_old) == 0)
    {
		if (sigismember(&sig_old, SIGINT) == 1 ) 
        {
			printf("SIGINT is block\n");
            sig_new = sig_old;
            sigdelset(&sig_new, SIGINT);
            if (sigprocmask(SIG_SETMASK, &sig_new, &sig_old) == 0)
            {
                printf("unblock SIGINT success\n");
            }
		} 
        else if (sigismember(&sig_old, SIGINT) == 0) 
        {
			printf("SIGINT is unblock\n");
            sig_new = sig_old;
            sigaddset(&sig_new, SIGINT);
            if (sigprocmask(SIG_SETMASK, &sig_new, &sig_old) == 0)
            {
                printf("Block SIGINT success\n");
            }
		}
    }
    while (1)
    {
        /* code */
    }
    return 0;
}