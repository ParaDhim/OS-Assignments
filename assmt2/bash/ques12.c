// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <limits.h>
// #include <pwd.h>
// #include <errno.h>
// #include <sys/wait.h>
// #include <sys/types.h>

// void main()
// {

//     struct timespec start1, finish1, delta1;
//     pid_t pid1;
//     clock_gettime(CLOCK_REALTIME, &start1);
//     pid1 = fork();
//     if (pid1 == 0)
//     {
//         execlp("sh", "sh", "-c", "./bash1.sh", 0);
//     }
//     clock_gettime(CLOCK_REALTIME, &finish);
//     printf("%lld %ld\n", start1.tv_sec, start1.tv_nsec);
//     printf("%lld %ld\n", finish1.tv_sec, finish1.tv_nsec);

//     struct timespec start2, finish2, delta2;
//     pid_t pid2;
//     clock_gettime(CLOCK_REALTIME, &start2);
//     pid2 = fork();
//     if (pid2 == 0)
//     {
//         execlp("sh", "sh", "-c", "./bash2.sh", 0);
//     }
//     clock_gettime(CLOCK_REALTIME, &finish);
//     printf("%lld %ld\n", start2.tv_sec, start2.tv_nsec);
//     printf("%lld %ld\n", finish2.tv_sec, finish2.tv_nsec);

//     struct timespec start3, finish3, delta3;
//     pid_t pid3;
//     clock_gettime(CLOCK_REALTIME, &start3);
//     pid3 = fork();
//     if (pid3 == 0)
//     {
//         execlp("sh", "sh", "-c", "./bash3.sh", 0);
//     }
//     else
//     {
//         waitpid(pid3, NULL, 0);
//     }
//     clock_gettime(CLOCK_REALTIME, &finish);
//     printf("%lld %ld\n", start3.tv_sec, start3.tv_nsec);
//     printf("%lld %ld\n", finish3.tv_sec, finish3.tv_nsec);
// }