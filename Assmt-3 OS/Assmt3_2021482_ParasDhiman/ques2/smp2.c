#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/shm.h>
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
	key_t key;
	int shid;

	key = ftok("/Assignment", 15);
	shid = shmget(key, 1024,0666 | IPC_CREAT);
	int i=1;
	while(i<=50){
		struct mesg_buffer *shareData = (struct mesg_buffer*) shmat(shid,(void*)0,0);
		//data = shareData;
		printf("#%d Data Received is : %s \tID:%d\t%c\n",shareData->id, shareData->text,i,shareData->text[4]);
		//shmdt(data);
		if (i%5==0){
			sleep(2);

			//struct mesg_buffer* data = (struct mesg_buffer*) shmat(shid,(void*)0,0);
			//data = shareData;
			printf("Sent : %d\n",shareData->id);
			//shmdt(data);
		}

		i++;
	}

	shmctl(shid, IPC_RMID, NULL);
	end = clock();
	double duration = ((double)end - start)/CLOCKS_PER_SEC;
	printf("%f",duration);
	return 0; 

}
