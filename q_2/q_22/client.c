#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[])
{

    if (argc < 4)
    {
        fprintf(stderr, "Please provide server's pid, signal type and amount\n");
        exit(1);
    }

    int pid = strtol(argv[1], NULL, 10);
    int signal_type = strtol(argv[2], NULL, 10);
    int signal_amount = strtol(argv[3], NULL, 10);

    if (signal_type != 2 && signal_type != 10)
    {
        fprintf(stderr, "Signal type %d is not supported, only SIGINT(2) and SIGUSR1(10) are supported!\n", signal_type);
        exit(1);
    }

    int amount_sent = 0;
    for (int i = 0; i < signal_amount; i++)
    {
        if (kill(pid, signal_type))
        {
            fprintf(stderr, "Failed to send signal!\n");
        }
        else
        {
            amount_sent++; 
        }
    }

    printf("%d signals were sent successfully!\n", amount_sent);
    return 0;
}
