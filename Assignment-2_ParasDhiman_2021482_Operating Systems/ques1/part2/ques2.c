#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <pwd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <time.h>
#include <time.h>
#include <sys/syscall.h>

pid_t forkCalling(char* bashCall,struct timespec* tim,int prior,pid_t pid)
{
    clock_gettime(CLOCK_REALTIME, tim);
    setpriority(0, PRIO_PROCESS, prior)
    printf("%s\n",bashCall)
    pid = fork();
    switch (pid)
    {
    case 0: /* child */
        /* Do stuff */
        execlp("sh", "sh", "-c", bashCall, 0);
        exit(1) 
    case -1 : 
        perror("fork");
        exit(1);
    }
    return pid;
}

void waitPiid(pid_t pidID[], struct timespec finish[])
{
    pid_t wID = waitpid(-1, NULL, 0);
    struct timespec tim1;
    clock_gettime(CLOCK_REALTIME, &tim1);
    struct timespec timePID;

    for (int num = 0; num < 3; num++)
    {
        if (pidID[num] == wID)
        {
            finish[num] = tim1;
        }
    }
}

void main()
{
    pid_t pid1, pid2, pid3;
    struct timespec start1, finish1, delta1;
    struct timespec start2, finish2, delta2;
    struct timespec start3, finish3, delta3;
    int prior[3] = {30,10,20};
    char* bashCall[] = {"./bash1.sh","./bash2.sh","./bash3.sh"};

    pid_t pidID[3] = {pid1, pid2, pid3};
    struct timespec start[3] = {start1, start2, start3};
    struct timespec finish[3] = {finish1, finish2, finish3};
    for (int i = 0; i < 3; i++)
    {
        pidID[i] = forkCalling(bashCall[i],&start[i], prior[i],pidID[i]);
    }

    for (int n = 0; n < 3; n++)
    {
        waitPiid(pidID, finish);
        /* code */
    }

    for (int num1 = 0; num1 < 3; num1++)
    {
        printf("for thread (sec) %d is %lld for start %lld for finish %lld", num1+1, start[num1].tv_sec, finish[num1].tv_sec);
        printf("for thread (nano) %d is %lld for start %ld for finish %ld", num1+1, start[num1].tv_nsec, finish[num1].tv_nsec);
        double tm = ((double)(finish[num1].tv_sec + 1.0e-9*finish[num1].tv_nsec)-(double)(start[num1].tv_sec + 1.0e-9*start[num1].tv_nsec));
        printf("%0.5f\n",tm);
        /* code */
    }
}