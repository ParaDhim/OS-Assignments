#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	printf("Enter the Arguments/options:");
	char argArr[50];
	char *argArrWord[50];
	FILE *ptrFile;
	char *name = "/home/paras/ques/assmt2/History.txt";
	ptrFile = fopen(name,"a+");
	if(ptrFile == NULL)
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

	while(tokSz < 5)
	{
		if(tkn != NULL)
		{
			argArrWord[tokSz] = tkn;
			tokSz++;
			tkn = strtok(NULL, " \n");
		}
		else
		{
			argArrWord[tokSz] = NULL;
			tokSz++;
			tkn = strtok(NULL, " \n");
		}
	}
	if(argArrWord[0] == NULL)
	{
		perror("Too few Arguments");
	}
	else if(strcmp(argArrWord[0],"--help") == 0 && argArrWord[1] == NULL && argArrWord[2] == NULL)
	{
		FILE *ptrFile;
		ptrFile = fopen("/home/paras/ques/assmt2/catInfo.txt","r");
		if(ptrFile == NULL)
		{
			perror("File Not Found");
		}
		char liner[400];
		while(fgets(liner,400,ptrFile))
		{
			printf("%s",liner);
		}
		fclose(ptrFile);
	}
	else if(argArrWord[2] != NULL)
	{
		perror("Too many Arguments");
	}
	else if(argArrWord[1] == NULL)
	{
		perror("No File Entered");
	}
	else
	{
		FILE *ptrFile1;
		ptrFile1 = fopen(argArrWord[1],"r");
		if(ptrFile1 == NULL)
		{
			perror("File Not Found");
			exit(0);
		}
		char liner[50];
		if(strcmp(argArrWord[0],"-n") == 0)
		{
			int count = 1;
			while(fgets(liner,50,ptrFile1))
			{
				printf("%d %s",count,liner);
				count += 1;
			}
		}
		else if(strcmp(argArrWord[0],"-E") == 0)
		{
			while(fgets(liner,50,ptrFile1))
			{
				char *pot = strtok(liner,"\n");
				printf("%s$\n",pot);
			}
		}
		/*else if(strcmp(argArrWord[0],"--help") == 0)
		{
			FILE *ptrFile;
			ptrFile = fopen("/home/ques/assmt2/catInfo.txt","r");
			if(ptrFile == NULL)
			{
				perror("File Not Found");
			}
			char liner[400];
			while(fgets(liner,400,ptrFile))
			{
				printf("%s",liner);
			}
			fclose(ptrFile);
		}*/
		else
		{
			perror("Invalid Command");
		}

	}


	exit(0);
}
