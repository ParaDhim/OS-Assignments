#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <pthread.h>
#include <semaphore.h>

int frks[5];
int bowl[5];

void pickupSpoon(int n)
{
	if (frks[n] == 0)
	{
		frks[n] = 1;
	}
	else
	{
		printf("%d already picked\n",n);
	}
}
void dropSpoon(int n)
{
	if (frks[n] == 1)
	{
		frks[n] = 0;
	}
	else
	{
		printf("%d already dropped\n",n);
	}
}
void pickupBowl(int n)
{
	if (bowl[n] == 0)
	{
		bowl[n] = 1;
	}
	else
	{
		printf("%d already picked\n",n);
	}
}
void dropBowl(int n)
{
	if (bowl[n] == 1)
	{
		bowl[n] = 0;
	}
	else
	{
		printf("%d already dropped\n",n);
	}
}

void *phil(void * arg)
{
	int f_num = *(int *) arg;
	while (1)
	{
		if (f_num % 5 == 0)
		{
			pickupSpoon(f_num);
			pickupSpoon((f_num+1) % 5);
		}
		else
		{
			pickupSpoon((f_num+1) % 5);
			pickupSpoon(f_num);
		}
		printf("Philosopher %d is eating its dish\n",f_num);

		dropBowl(f_num % 5);
		dropSpoon(f_num);
		dropSpoon((f_num + 1) % 5);


	}
}

int main()
{
	pthread_t philo[5];
	int args[5];
	for (int i = 0; i < 5; i++)
	{
		frks[i] = 0;
		bowl[i] = 0;
		args[i] = i;
	}
	for (int i = 0; i < 5; i++)
	{
		pthread_create(&philo[i],NULL,&phil,&args[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		pthread_join(philo[i],NULL);
	}
}
