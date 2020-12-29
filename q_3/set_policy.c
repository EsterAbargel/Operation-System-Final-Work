#include <stdio.h>
#include <sched.h>

#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc < 3)
    {
        fprintf(stderr, "Please provide scheduler and priority\n");
        exit(1);
    }

    int scheduler = strtol(argv[1], NULL, 10);
    int priority = strtol(argv[2], NULL, 10);

    struct sched_param param;

    param.sched_priority = priority;
    if (sched_setscheduler(0, scheduler, &param) == -1)
    {
        fprintf(stderr, "Error setting scheduler... are you root?\n");
        exit(1);
    }


    printf("My PID is: %d\n", getpid());
    printf("Changes were applied succesfully\n");
    printf("Now you can run chrt to make sure the changes were applied\n");
    printf("Press Enter to exit...\n");
    getchar();
    return 0;
}
