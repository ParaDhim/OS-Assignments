#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

sem_t frks[5];
sem_t bowl[5];

void * phil(void * arg){
	int f_num = *(int*) arg;

	while(1){
		if(f_num % 5 == 0)
		{
			sem_wait(&frks[f_num]);
			//taken mod so than don't exceed if exceed we gets the neighbour
			sem_wait(&(frks[(f_num + 1) % 5]));
		}
		else
		{
			sem_wait(&frks[(f_num + 1) % 5]);
			sem_wait(&frks[f_num]);
		}

		sem_wait(&bowl[f_num % 5]);

		printf("Philosopher %d is eating its dish\n",f_num);

		sem_post(&bowl[f_num %5]);
		sem_post(&frks[f_num]);
		sem_post(&frks[(f_num + 1) % 5]);
	}
}


int main()
{
	pthread_t philo[5];
	int args[5];

	for(int i = 0 ; i < 5 ; i++)
	{
		sem_init(&frks[i], 0, 1);
	}
	for(int i = 0; i < 2; i++)
	{
		sem_init(&bowl[i], 0, 1);
	}

	for(int i = 0;i < 5; i++)
	{
		args[i] = i;
	}

	for(int i = 0; i < 5; i++)
	{
		pthread_create(&philo[i], NULL, phil, &args[i]);
	}

	for(int i = 0; i < 5 ; i++)
	{
		pthread_join(philo[i],NULL);
	}
	return 0;
}

