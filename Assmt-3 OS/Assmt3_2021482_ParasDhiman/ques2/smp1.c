#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#define MAX 5

struct mesg_buffer {
	char text[MAX];
	int id;
} *shareData;

int main() 
{
	clock_t start, end;
	start = clock();

	char pd[50][14];
	char ALPHA[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int n=strlen(ALPHA);
	char the_string[MAX];
	key_t key;
	int shid;

	key = ftok("/Assignment", 15);
	shid = shmget(key, 1024,0666 | IPC_CREAT);

	int j=0;
	while(j<0){
		j++;
	}
	struct mesg_buffer* shareData = (struct mesg_buffer *) shmat(shid,(void*)0,0);
	for (int j =1; j <=50; j++) {
		int i =0;
		while(i< MAX){
			int k = rand() %52;
			the_string[i] =ALPHA[k];
			shareData->text[i] = the_string[i];
			i++;

		}
		shareData->id = j;
		//struct mesg_buffer *data = (struct mesg_buffer *) shmat(shid,(void*)0,0);

		printf("#%d Data sent is : %s \n",j, shareData->text);

		//shmdt(data);

		if (j%5 == 0){
			//struct mesg_buffer* data = (struct mesg_buffer *) shmat(shid,(void*)0,0);
			sleep(1);

			printf("ID Received is : %d\n", shareData->id);
			//shmdt(data);
		}  
	}
	end = clock();
	double duration = ((double)end - start)/CLOCKS_PER_SEC;
	printf("%f",duration);
	return 0; 
}
