#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <pwd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>
#include <sched.h>
#include <time.h>

#define MAX_SIZE_CMD 4294967296
#define MAX_SIZE_ARG 16

typedef long long int ll;

ll loop_count = 4294967296;


#define handle_error_en(en, msg) \
	do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)


static void countA() 
{
	for (ll idx1 = 0; idx1 < loop_count; idx1++) {

	}
}

static void countB() {
	for (ll idx2 = 0; idx2 < loop_count; idx2++) {

	}
}

static void countC()
{
	for (ll idx3 = 0 ; idx3 < loop_count; idx3++)
	{

	}
}
static void *ThrA(void *arg)
{
	struct sched_param param1 = { .sched_priority = 0};
	//struct sched_param param1;
	int policy1 = SCHED_OTHER;
	int s1 = pthread_setschedparam(pthread_self(), policy1, &param1);

	/*if (s1 != 0)
	{
		handle_error_en(s1, "pthread_setschedparam");
	}*/
	printf("Other %d\n",s1);
	struct timespec start1, finish1, delta1;
	clock_gettime(CLOCK_REALTIME, &start1);
	countA();
	clock_gettime(CLOCK_REALTIME, &finish1);
	printf("%lld %ld Other\n", start1.tv_sec, start1.tv_nsec);
	//printf("%d %d Other\n",(int)(finish1.tv_sec - start1.tv_sec),(int)(finish1.tv_nsec - start1.tv_nsec));
	printf("%lld %ld Other\n",finish1.tv_sec, finish1.tv_nsec);
	double tam1 =((double)(finish1.tv_sec + 1.0e-9*finish1.tv_nsec) - (double)(start1.tv_sec + 1.0e-9*start1.tv_nsec));
	printf("%0.5f\n",tam1);

	FILE *fptr1;
	fptr1 = fopen("pr1.txt","a");
	char str1[100];
	sprintf(str1,"%0.5f",tam1);
	fputs(str1, fptr1);
	fputs("\n", fptr1);
	fclose(fptr1);

}

static void *ThrB(void *arg)
{
	struct sched_param param2 = { .sched_priority = 37};
	//struct sched_param param2;
	int policy2 = SCHED_RR;
	int s2 = pthread_setschedparam(pthread_self(), policy2, &param2);
	/*if (s2 != 0)
	{
		handle_error_en(s2,"pthread_setschedparam");
	}*/
	printf("RR %d\n",s2);
	struct timespec start2, finish2, delta2;
	clock_gettime(CLOCK_REALTIME, &start2);
	countB();
	clock_gettime(CLOCK_REALTIME, &finish2);
	//printf("RR\n");
	printf("%lld %ld RR\n",start2.tv_sec,start2.tv_nsec);
	//printf("%d %d RR\n",(int)(finish2.tv_sec-start2.tv_sec),(int)(finish2.tv_nsec - start2.tv_nsec));
	printf("%lld %ld RR\n",finish2.tv_sec,finish2.tv_nsec);
	double tam2 = ((double)(finish2.tv_sec + 1.0e-9*finish2.tv_nsec) - (double)(start2.tv_sec + 1.0e-9*start2.tv_nsec));
	printf("%0.5f\n",tam2);

	FILE *fptr2;
	fptr2 = fopen("pr2.txt","a");
	char str2[100];
	sprintf(str2,"%0.5f",tam2);
	fputs(str2, fptr2);
	fputs("\n", fptr2);
	fclose(fptr2);
}
static void *ThrC(void *arg)
{
	struct sched_param param3 = { .sched_priority = 37 };
	//struct sched_param param3;
	int policy3 = SCHED_FIFO;
	int s3 = pthread_setschedparam(pthread_self(), policy3, &param3);
	printf("FIFO %d\n",s3);
	/*if (s3 != 0)
	{
		handle_error_en(s3,"pthread_setschedparam");
	}*/
	struct timespec start3, finish3, delta3;
	clock_gettime(CLOCK_REALTIME, &start3);
	countC();
	clock_gettime(CLOCK_REALTIME, &finish3);
	//printf("FIFO\n");
	printf("%lld %ld FIFO\n",start3.tv_sec,start3.tv_nsec);

	//printf("%d %d FIFO\n",(int)(finish3.tv_sec-start3.tv_sec),(int)(finish3.tv_nsec - start3.tv_nsec));
	printf("%lld %ld FIFO\n",finish3.tv_sec,finish3.tv_nsec);
	double tam3 = ((double)(finish3.tv_sec + 1.0e-9*finish3.tv_nsec) - (double)(start3.tv_sec + 1.0e-9*start3.tv_nsec));
	printf("%0.5f\n",tam3);

	FILE *fptr3;
	fptr3 = fopen("pr3.txt","a");
	char str3[100];
	sprintf(str3,"%0.5f",tam3);
	fputs(str3, fptr3);
	fputs("\n", fptr3);
	fclose(fptr3);

}



int main(int argc, char *argv[]) {
	pthread_t tid1, tid2, tid3;
	pthread_attr_t attr;

	int st1, st2, st3;

	st1 = pthread_create(&tid1, NULL, &ThrA, NULL);
	st2 = pthread_create(&tid2, NULL, &ThrB, NULL);
	st3 = pthread_create(&tid3, NULL, &ThrC, NULL);

	if (st1 != 0)
	{
		handle_error_en(st1, "pthread_create");
	}
	st1 = pthread_join(tid1, NULL);
	if (st1 != 0)
	{
		handle_error_en(st1, "pthread_join");
	}
	if (st2 != 0)
	{
		handle_error_en(st2, "pthread_create");
	}
	st2 = pthread_join(tid2, NULL);
	if (st2 != 0)
	{
		handle_error_en(st2, "pthread_join");
	}

	if (st3 != 0)
	{
		handle_error_en(st3, "pthread_create");
	}
	st3 = pthread_join(tid3, NULL);
	if (st3 != 0)
	{
		handle_error_en(st3, "pthread_join");
	}

	return 0;
}