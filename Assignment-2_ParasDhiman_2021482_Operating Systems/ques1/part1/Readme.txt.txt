In this ques, we have taken a loop count which is of value 2^32 and have constructed 
three count functions which are doing the same work that is of the counting
then we have constructed three threads name ThrA,ThrB,ThrC where we are assing 
them priorities and their respective scheduling policies
i.e OTHER,RR,FIFO using the pthread_setschedparam(3pthread_t thread, int policy,const struct sched_param *param);

after this we have called the time function whereas we have called
struct timespec {
        time_t   tv_sec;        /* seconds */
        long     tv_nsec;       /* nanoseconds */
};

int clock_gettime(clockid_t clk_id, struct timespec *tp);

int clock_settime(clockid_t clk_id, const struct timespec *tp);

For creating the threads we have called 
int pthread_create(pthread_t *restrict thread,
                          const pthread_attr_t *restrict attr,
                          void *(*start_routine)(void *),
                          void *restrict arg);

Then we have to create the join commands as
inclding the library
#include <pthread.h>

int pthread_join(pthread_t thread, void **retval);
and then we print the timespec value after some calculations in double format
and then after taking some observations and making their text file we can make graph by calling python script








