In this question we have used fork() calling in multiple for loops
and have used 
int clock_gettime(clockid_t clk_id, struct timespec *tp);
2 times for the start one and the finish one

struct timespec {
        time_t   tv_sec;        /* seconds */
        long     tv_nsec;       /* nanoseconds */
};

and also we have use execlp for calling the bash files in between the program running
nt execlp(const char *file, const char *arg, ...);
and after the execution of our fork function we have also called the wait function
where we check the pid of the fork call and have 

then we have printed the output of the respective timings where it has been printed in float values respectively