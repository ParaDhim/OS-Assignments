#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

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
	//printf("%s",argArrWords[0]);
	//printf("%s",argArrWords[1]);
	if(argArrWords[0] == NULL && argArrWords[1] == NULL)
	{
		perror("Too few Arguments");
	}
	else if(strcmp(argArrWords[0],"-v") != 0 && strcmp(argArrWords[0],"-p") != 0 && strcmp(argArrWords[0],"--help") != 0)
	{
		perror("Invalid Command");
	}
	else if (argArrWords[2] == NULL && argArrWords[1] != NULL && strcmp(argArrWords[0],"-v") == 0)
	{
		int a = mkdir(argArrWords[1],0700);
		if(a != 1)
		{
			printf("Directory Successfully Created\n");
		}
		else
		{
			printf("Cannot Create Directory\n");
		}
	}
	else if(argArrWords[2] != NULL && argArrWords[1] != NULL && strcmp(argArrWords[0],"-v") == 0)
	{
		int a = mkdir(argArrWords[1],0700);
		int b = mkdir(argArrWords[2],0700);
		if (a != -1)
		{
			printf("Directory1 Successfully Created\n");
		}
		if (b != 1)
		{
			printf("Directory2 Successfully Created\n");
		}
		else
		{
			printf("Directory Created");
		}
		    
	}
	else if(argArrWords[2] == NULL && argArrWords[1] != NULL && strcmp(argArrWords[0],"-p") == 0)
	{
		char *poin = strtok(argArrWords[2],",\n");
		while (poin != NULL)
		{
			int a = mkdir (poin,0700);
			if (a != -1)
			{
				printf("Cannot Create Directory\n");
				break;
			}
			chdir(poin);
			poin = strtok(NULL,",\n");
		}
		    
	}
	else if(argArrWords[2] == NULL && argArrWords[1] == NULL && strcmp(argArrWords[0],"--help") == 0)
	{
		FILE *ptrFile;
		ptrFile = fopen("/home/paras/ques/assmt2/mkdirInfo.txt","r");
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
	exit (0);
}
