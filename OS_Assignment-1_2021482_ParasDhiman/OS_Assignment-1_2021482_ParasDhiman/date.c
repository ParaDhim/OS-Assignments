#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void main()
{
	printf("Enter the Arguments/options:");
	char argArr[50];
	char *argArrWords[50];
	FILE *ptrFile;
	char *name = "/home/paras/ques/assmt2/History.txt";
	ptrFile = fopen(name,"a+");
	if (ptrFile == NULL)
	{
		perror("Error\n");
		exit(1);
	}

	fgets(argArr,50,stdin);
	fputs(argArr,ptrFile);
	fclose(ptrFile);
	char *tkn;
	int tokSz = 0;
	tkn = strtok(argArr," \n");

	while (tokSz < 5)
	{
		if (tkn != NULL)
		{
			argArrWords[tokSz] = tkn;
			tokSz++;
			tkn = strtok(NULL, " \n");
		}
		else
		{
			argArrWords[tokSz] = NULL;
			tokSz++;
			tkn = strtok(NULL, " \n");
		}
	}

	if(argArrWords[1] != NULL || argArrWords[2] != NULL)
	{
		perror("Too many Arguments");
	}
	if(argArrWords[0] == NULL)
	{
		struct tm *pd;
		time_t curt = time(NULL);
		pd = localtime(&curt);
		printf("%s\n",asctime(pd));
	}
	else if(argArrWords[0] != NULL && strcmp(argArrWords[0],"--help") == 0)
	{
		FILE *ptrFile1;
		ptrFile1 = fopen("/home/paras/ques/assmt2/dateInfo.txt","r");
		if(ptrFile1 == NULL)
		{
			perror("File Specified can't be Found");
			exit(0);
		}
		char liner[400];
		while(fgets(liner,400,ptrFile1))
		{
			printf("%s",liner);
		}
	
		fclose(ptrFile1);
	}
	else if(argArrWords[0] != NULL && strcmp(argArrWords[0],"-u"))
	{
		time_t curt = time(NULL);
		if(curt == -1)
		{
			perror("Error");
			return;
		}
		struct tm *pd;
		char bfr1[4];
		char bfr2[4];
		char bfr3[6];
		pd = localtime(&curt);
		if(pd == NULL)
		{
			perror("Error");
			return;
		}
		strftime(bfr1,4,"%a",pd);
		strftime(bfr2,4,"%b",pd);
		strftime(bfr3,6,"%z",pd);
		printf("%s, %02d %s %d %02d:%02d:%02d UTC %d\n",bfr1,pd->tm_mday,bfr2,pd->tm_year + 1900,pd->tm_hour,pd->tm_min,pd->tm_sec,bfr3);
	}
	else if(argArrWords[0] != NULL && strcmp(argArrWords[0],"-R"))
	{
		time_t curt = time(NULL);
		if(curt == -1)
		{
			perror("Error");
			return;
		}
		struct tm *pd;
		char bfr1[4];
		char bfr2[4];
		char bfr3[6];
		pd = localtime(&curt);
		if(pd == NULL)
		{
			perror("Error");
		}
		strftime(bfr1, 4, "%a", pd);
		strftime(bfr2, 4, "%b", pd);
		strftime(bfr3, 6, "%z", pd);
		printf("%s, %02d %s %d %02d:%02d:%02d %s\n", bfr1, pd->tm_mday, bfr2, pd->tm_year + 1900, pd->tm_hour, pd->tm_min, pd->tm_sec, bfr3);
	}

	else
	{
		perror("Command Entered Invalid  Check");
	}
	exit(0);


	//return 0;    
}
