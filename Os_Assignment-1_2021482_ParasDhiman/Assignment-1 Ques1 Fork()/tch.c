#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <pwd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_SIZE_CMD 4294967296
#define MAX_SIZE_ARG 16

typedef long long int ll;

ll loop_count = 4294967296;

#define handle_error_en(en,mssg)\
    do { errno = en; perror(msg); exit(EXIT_FAILURE); } while(0)


struct timespec start, finish, delta;
cloack_gettime(CLOCK_REALTIME, &start);

// char *testingArgs1[] = {execlp("sh","sh","-c","gcc -o cou.o countA.c; countA.o",0);",0};
pid_t pid1;
pid1 = fork();

if (pid1 == 0)
{
// execvp(testingArgs1[0],testingArgs1);
execlp("sh","sh","-c","gcc -o countA.o countA.c; countA.o",0);
}
else
{
wait(NULL);
}


cloack_gettime(CLOCK_REALTIME, &finish);
printf("%lld %ld\n",start.tv_sec,start.tv_nsec);
printf("%lld %ld\n",finish.tv_sec,finish.tv_nsec);





struct timespec start, finish, delta;
cloack_gettime(CLOCK_REALTIME, &start);

// char *testingArgs2[] = {"sh","-c","gcc -o countB.o countB.c; countB.o",0};
pid_t pid2;
pid2 = fork();

if (pid2 == 0)
{
// execvp(testingArgs2[0],testingArgs2);
execlp("sh","sh","-c","gcc -o countB.o countB.c; countB.o",0);

}
else
{
wait(NULL);
}


cloack_gettime(CLOCK_REALTIME, &finish);
printf("%lld %ld\n",start.tv_sec,start.tv_nsec);
printf("%lld %ld\n",finish.tv_sec,finish.tv_nsec);





struct timespec start, finish, delta;
cloack_gettime(CLOCK_REALTIME, &start);

// char *testingArgs3[] = {"sh","-c","gcc -o countC.o countC.c; countC.o",0};
pid_t pid3;
pid3 = fork();

if (pid3 == 0)
{
// execvp(testingArgs3[0],testingArgs3);
execlp("sh","sh","-c","gcc -o countC.o countC.c; countC.o",0);

}
else
{
wait(NULL);
}


cloack_gettime(CLOCK_REALTIME, &finish);
printf("%lld %ld\n",start.tv_sec,start.tv_nsec);
printf("%lld %ld\n",finish.tv_sec,finish.tv_nsec);
