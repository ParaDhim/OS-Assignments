#include <sys/ipc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#define MAX 5
#define PERMISSION 0666

int main()
{
	clock_t start, end;
	start = clock();
	char ALPHA[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char pd[MAX];
	int fd;
	char * myfifo = "myfif1";
	int j=0;
	while(j<0){
		j++;
	}
	mkfifo(myfifo, PERMISSION);
	printf("Sending Data through FIFO\n");
	int m = 1;
	while (m <= 50)
	{
		m++;
		fd = open(myfifo, O_WRONLY);

		printf("#%d\tData sent is :\t",m-1);
		int i=0;
		while(i<5){
			int k = rand() % 52;
			pd[i] = ALPHA[k];
			printf("%c",pd[i]);
			i++;
		}
		printf("\n");

		usleep(80);
		write(fd, pd, sizeof(pd));
		close(fd);
		fd = open(myfifo, O_RDONLY);

		int data[1];

		read(fd, data, sizeof(data));
		if (data[0] <= 50 && data[0] % 5 == 0){
			printf("Read id: %d\n",data[0]);
		}
		close(fd);

	}
	printf("Terminated\n");
	end = clock();
	double duration = ((double)end - start)/CLOCKS_PER_SEC;
	printf("%f",duration);
	return 0;
}
