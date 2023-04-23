#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main()
{
	clock_t start, end;
	start = clock();
	int fd1;
	char *myfifo = "myfif1";
	mkfifo(myfifo, 0666);
	char buff[5];
	int m = 0;
	printf("Recieveing Data\n");
	while (m < 50)
	{
		m++;
		fd1 = open(myfifo, O_RDONLY);
		read(fd1, buff, 5);
		printf("#%d\tData recieved :\t%s\n", m, buff);
		close(fd1);
		int id[1];
		id[0] = m;
		fd1 = open(myfifo, O_WRONLY);
		write(fd1, id, sizeof(id));
		if (m % 5 == 0)
		{
			printf("Sent id: %d\n", id[0]);
		}
		close(fd1);
	}
	printf("Terminated\n");
	end = clock();
	double duration = ((double)end - start)/CLOCKS_PER_SEC;
	printf("%f",duration);
	return 0;
}
