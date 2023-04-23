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
	char argArr[1028];
	char *argArrWords[1028];
	FILE *ptrFile;
	char *name = "/home/paras/ques/assmt2/History.txt";
	ptrFile = fopen(name,"a+");
	if (ptrFile == NULL)
	{
		perror("Error\n");
		exit(1);
	}

	fgets(argArr,1028,stdin);
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
	//printf("%s\n",argArrWords[0]);
	//printf("%s\n",argArrWords[1]);
	if(argArrWords[2] != NULL)
	{
		perror("Too Many Arguments");
	}
	else if(argArrWords[0] == NULL)
	{
		perror("Too few Arguments");
	}
	else if(strcmp(argArrWords[0],"-d") == 0)
	{
		if(argArrWords[1] == NULL)
		{
			printf(".\n");
		}
		else
		{
			int testing = 0;
			DIR *memAdd;
			struct dirent *et;
			memAdd = opendir(".");
			if(memAdd)
			{
				for(et = readdir(memAdd);et!=NULL;et=readdir(memAdd))
				{
					char *nm = et->d_name;
					if(strcmp(argArrWords[1],nm) == 0)
					{
						printf("%s\n",nm);
						testing = 1;
						break;
					}
				}
			}
			if (testing == 0)
			{
				perror("Directory Not Found");
			}	    
		}
	}
	else if(strcmp(argArrWords[0],"-a") == 0)
	{
		if(argArrWords[1] != NULL)
		{
			perror("Too many Arguments");
		}
		else
		{
			DIR *mainDir;
			struct dirent *et;
			mainDir = opendir(".");
			if(mainDir)
			{
				int count = 0;
				for(et = readdir(mainDir);et!=NULL;et=readdir(mainDir))
				{
					char *nm = et->d_name;
					if(count == 3)
					{
						printf("%s\n",nm);
						count = 1;
						continue;
					}
					else
					{
						printf("%s\t",nm);
						count += 1;
					}
				}
			}
			printf("\n");
			closedir(mainDir);
		}
	}

	else if(strcmp(argArrWords[0],"--help") == 0)
	{
		FILE *ptrFile;
		ptrFile = fopen("/home/paras/ques/assmt2/lsInfo.txt","r");
		if(ptrFile == NULL)
		{
			perror("File Not Found");
		}
		char liner[400];
		while(fgets(liner,400,ptrFile))
		{
			printf("%s",liner);
		}
		printf("\n");
		fclose(ptrFile);
	}
	else
	{
		perror("Invalid Command");
	}


	//return 0;    
	exit (0);
}
