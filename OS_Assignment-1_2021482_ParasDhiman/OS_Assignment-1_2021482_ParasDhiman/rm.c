#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>


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
	char*tkn;
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

	if((argArrWords[1] == NULL || argArrWords[0] == NULL) && strcmp(argArrWords[0],"--help") != 0)
	{
		perror("file name not entered/Too few Arguments");
	}
	else if(strcmp(argArrWords[0],"-f") != 0 && strcmp(argArrWords[0],"-i") != 0 && strcmp(argArrWords[0],"--help") != 0)
	{
		perror("Command Entered is Invalid");
	}
	else if(argArrWords[2] == NULL && argArrWords[1] == NULL && strcmp(argArrWords[0],"--help")== 0)
	{
		FILE *ptrFile;
		ptrFile = fopen("/home/paras/ques/assmt2/rmInfo.txt","r");
		if(ptrFile == NULL)
		{
			perror("File speified can't be found");
		}
		char liner[400];
		while(fgets(liner,400,ptrFile))
		{
			printf("%s",liner);
		}
		fclose(ptrFile);
	}
	else if(argArrWords[2] == NULL && argArrWords[1] != NULL)
	{
		if (strcmp(argArrWords[0],"-f") == 0)
		{
			remove(argArrWords[1]);
		}
		else if(strcmp(argArrWords[0],"-i") == 0)
		{
			char chrArr[2];
			printf("Y to delete / N to Ignore \n");
			fgets(chrArr,2,stdin);
			if(strcmp(chrArr,"Y") == 0)
			{
				int a = remove(argArrWords[1]);
				if(a == -1)
				{
					perror("File can't be Found\n");
				}
				else if(a == 0)
				{
					printf("File Deleted\n");
				}
			}
			else if(strcmp(chrArr,"N") == 0)
			{
				printf("Nothing is done to file not deleted");
			}
			else
			{
				perror("Selected Option is not correct");
			}
		}
		    
	}
	else if(argArrWords[2] != NULL)
	{
		if(strcmp(argArrWords[0],"-f") == 0)
		{
			remove(argArrWords[1]);
			remove(argArrWords[2]);
		}
		else if(strcmp(argArrWords[0],"-i") == 0)
		{
			char chrArr[2];
			int chrA;
			printf("Y to delete / N to Ignore \n");
			fgets(chrArr,2,stdin);
			if(strcmp(chrArr,"Y") == 0)
			{
				int a = remove(argArrWords[1]);
				if(a == -1)
				{
					    perror("File can't be Found\n");
				}
				else if(a == 0)
				{
					printf("File Deleted\n");
				}
			}
			else if(strcmp(chrArr,"N") == 0)
			{
				printf("Noting is done to file not deleted");
			}
			else
			{
				perror("Selected Option is not correct");
			}
			printf("1 to delete /0 to Ignore File2:");
			scanf("%d",&chrA);
			if(chrA == 1)
			{
				int a = remove(argArrWords[2]);
				if(a == -1)
				{
					perror("File can't be found\n");
				}
				else if(a == 0)
				{
					printf("File Deleted\n");
				}
			}
			else if (chrA == 0)
			{
				printf("File Deleted");
			}
			else
			{
				perror("Selected Option is not correct");
			}
		}
	}



	//return 0;    

	exit(0);
}
