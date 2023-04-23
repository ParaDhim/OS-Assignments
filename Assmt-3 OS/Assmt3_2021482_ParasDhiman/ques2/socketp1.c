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
#include <time.h>
#define SIZE 1024

void send_dona(char* hello, int k,int sockfd){
	int n;

	char dona[SIZE] = {0};

	if (send(sockfd, hello, sizeof(dona), 0) == -1) {

		perror("[-]Error in sending file.");

		exit(1);
	}
	int converted_number = htonl(k);

	write(sockfd, &converted_number, sizeof(converted_number));

}

int main(){
	clock_t start, end;
	start = clock();
	char *ip = "127.0.0.1";
	int port = 8080;
	int e;
	int sockfd;
	struct sockaddr_in server_addr;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0) {
		perror("[-]Error in socket");
		exit(1);
	}
	printf("[+]Server socket created successfully.\n");
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = port;
	server_addr.sin_addr.s_addr = inet_addr(ip);
	e = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
	int j=0;

	while(j<0){
		j++;
	}
	if(e == -1) {
		perror("[-]Error in socket");
		exit(1);
	}
	printf("[+]Connected to Server.\n");

	char* pd[50];
	pd[0]="acbd";
	pd[1]="okay";
	pd[2]="alan";
	pd[3]="onyou";
	pd[4]="ok";
	pd[5]="Know";
	pd[6]="me";
	pd[7]="on";
	pd[8]="your";
	pd[9]="parasd";
	pd[10]="Kno";
	pd[11]="meeek";
	pd[12]="onyo";
	pd[13]="yor";
	pd[14]="plce";
	pd[15]="Know";
	pd[16]="me";
	pd[17]="on";
	pd[18]="your";
	pd[19]="parasd";
	pd[20]="Know";
	pd[21]="me";
	pd[22]="on";
	pd[23]="your";
	pd[24]="parasd";
	pd[25]="Know";
	pd[26]="me";
	pd[27]="on";
	pd[28]="your";
	pd[29]="parasd";
	pd[30]="Know";
	pd[31]="me";
	pd[32]="on";
	pd[33]="your";
	pd[34]="parasd";
	pd[35]="Know";
	pd[36]="me";
	pd[37]="on";
	pd[38]="your";
	pd[39]="parasd";
	pd[40]="Know";
	pd[41]="me";
	pd[42]="on";
	pd[43]="your";
	pd[44]="parasd";
	pd[45]="Know";
	pd[46]="me";
	pd[47]="on";
	pd[48]="your";
	pd[49]="parasd";
	int i =0;
	while(i<50){
		send_dona(pd[i], i, sockfd);
		i++;
	}
	printf("[+]File sent successfully.\n");
	end = clock();
	double duration = ((double)end - start)/CLOCKS_PER_SEC;
	printf("%f",duration);
	return 0;
}
