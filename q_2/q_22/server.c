#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>

int sigint_counter = 0;
int sigusr1_counter = 0;

void sigint_handler(int signo)
{
    if (signo == SIGINT)
    {
        sigint_counter++;
    }
}

void sigusr1_handler(int signo)
{
    if (signo == SIGUSR1)
    {
        sigusr1_counter++;
    }
}

int main(int argc, char *argv[])
{
    printf("My PID is: %d\n", getpid());
    if (signal(SIGINT, sigint_handler))
    {
        fprintf(stderr, "Error while setting handler for SIGINT\n");
        exit(1);
    }
    if (signal(SIGUSR1, sigusr1_handler))
    {
        fprintf(stderr, "Error while setting handler for SIGUSR1\n");
        exit(1);
    }
    printf("Waiting for signals... Press Enter to get signals counters and exit!\n");
    getchar();
    printf("SIGINT count is: %d\n", sigint_counter);
    printf("SIGUSR1 count is: %d\n", sigusr1_counter);
    return 0;
}
