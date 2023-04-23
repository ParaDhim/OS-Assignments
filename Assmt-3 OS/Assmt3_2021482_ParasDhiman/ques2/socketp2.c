#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>
#define SIZE 1024
int max=-1;

void write_file(int sockfd){

	int i=0;
	while(i<5){
		int n;
		char buffer[SIZE];
		bzero(buffer, sizeof(buffer));
		n = read(sockfd, buffer, 1024);
		if (n <=0){
			printf("[-]Error in reading data");
			return;
		}
		printf("Here is the Message: %s\n", buffer);
		bzero(buffer, sizeof(buffer));
		int received_int = 0;

		n = read(sockfd, &received_int, sizeof(received_int));
		int m=ntohl(received_int);

		if (m> max) {
			max= m;
		}

		if (n> 0) {
			fprintf(stdout, "Received int = %d\n", ntohl(received_int));
		}
		bzero(buffer, sizeof(buffer));
		i++;
	}
	printf("The Maximum Index: %d\n",max);
	return;
}

int main()
{
	clock_t start, end;
	start = clock();
	char *ip = "127.0.0.1";

	int port = 8080;
	int e;

	int sockfd, new_sock;
	struct sockaddr_in server_addr, new_addr;
	socklen_t addr_size;
	char buffer[SIZE];
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0) {
		perror("[-]Error in socket");
		exit(1);
	}
	printf("[+]Server socket created successfully.\n");

	server_addr.sin_family = AF_INET;

	server_addr.sin_port = port;

	server_addr.sin_addr.s_addr = inet_addr(ip);

	e = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
	if(e < 0) {

		perror("[-]Error in bind");

		exit(1);
	}
	printf("[+]Binding successfull.\n");

	if(listen(sockfd, 10) == 0){

		printf("[+]Listening....\n");

	}

	else{
		perror("[-]Error in listening");
		exit(1);
	}
	addr_size = sizeof(new_addr);
	new_sock = accept(sockfd, (struct sockaddr*)&new_addr, &addr_size);
	int i=0;
	while(i<10){
		write_file(new_sock);
		i++;
	}
	printf("[+]Data written in the file successfully.\n");
	end = clock();
	double duration = ((double)end - start)/CLOCKS_PER_SEC;
	printf("%f",duration);
	return 0;
}
