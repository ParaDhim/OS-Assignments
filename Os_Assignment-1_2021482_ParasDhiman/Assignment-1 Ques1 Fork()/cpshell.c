#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <pwd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_SIZE_CMD 1028
#define MAX_SIZE_ARG 16

int main(){
	printf("******************** WELCOME TO THE SHELL ********************\n");
	//char commands[10] = 
	while(1){
		printf("Shell>$\t");
		char comd[MAX_SIZE_CMD];
		char *comdWord[MAX_SIZE_CMD];
		pid_t pid;
		int tokSize;
		fgets(comd,MAX_SIZE_CMD,stdin);
		FILE *ft;
		char *name = "/home/paras/ques/assmt2/History.txt";
		ft = fopen(name,"a+");
		if(ft == NULL)
		{
			perror("Error\n");
			exit(1);
		}
		fputs(comd,ft);
		//fputs("\n",ft);
		fclose(ft);

		//scanf("%[^\n]%*c",comd);
		//if(comd[0] != 0){
			//char *com = malloc(sizeof(char) * strlen(comd));
			//char *token;
			//char *delim = " ";
			//strcpy(com,comd);

			//token = strtok(com, delim);
			//while (token != NULL){
			//	printf("%s\n",token);
			//	token = (NULL, " ");
			//}

		//}
		//removing the newline character
		if ((strlen(comd) > 0) && (comd[strlen(comd) - 1] == '\n')){
			comd[strlen (comd) - 1] = '\0';
		}

		if (strcmp("",comd) == 0){
			continue;
		}
		if (strcmp("exit",comd) == 0){
			char exit[5] = "exit";
			printf("%s\n",exit);
			break;
		}

		else{
			char *token;
			tokSize = 0;
			token = strtok(comd, " \n");

			
			while (tokSize < 5){
				if(token != NULL)
				{
					comdWord[tokSize] = token;
					tokSize++;
					token = strtok(NULL, " \n");
				}
				else
				{
					comdWord[tokSize] = NULL;
					tokSize++;
					token = strtok(NULL, " \n");
				}
			}
			//printf("%s",comdWord[0]);
			//printf("%s",comdWord[1]);
			//printf("%s",comdWord[3]);
			
			/*
			FILE *ft;
			char *name = "/home/paras/ques/assmt2/History.txt";
			ft = fopen(name,"a+");
			if(ft == NULL)
			{
				perror("Error\n");
				exit(1);
			}
			fputs(comd,ft);
			fclose(ft);
			*/

			//char *str1;
			//char *str2;
			//char *str3;
			//char *str4;


			char *ptr = strtok(comd, " \n");
			//printf("%s\n",ptr);
			//str1 = comdWord[0];
			//str2 = comdWord[1];
			//str3 = comdWord[2];
			//str4 = comdWord[3];
			//printf("%s",str1);
			//printf("%s",str2);
			//printf("%s",str3);
			//printf("%s",str4);


			if(strcmp(comdWord[0],"cd") == 0)
			{
				//printf("hii");
				//printf("%s",str1);
				//printf("%s",comdWord[3]);
				if(comdWord[1] == NULL)
				{
					printf("");
				}
			
				else if(comdWord[3] != NULL)
				{
					perror("To Many Arguments\n");
				}
				else
				{
					if(strcmp(comdWord[1],"-P") == 0)
					{
						if(comdWord[2] == NULL)
						{
							perror("Too Few Arguments");
						}
						else
						{
							int test = chdir(comdWord[2]);
							if(test == 0)
							{
								printf("");
							}
							else
							{
								perror("Directory not found\n");
							}
						}
					}
					else if(strcmp(comdWord[1],"-L") == 0)
					{
						if(comdWord[2] != NULL)
						{
							int iden = chdir(comdWord[2]);
							if(iden != 0)
							{
								perror("invalid command");
							}
							else
							{
								char cwd[200];
								char *ptrCwd = getcwd(cwd, sizeof(cwd));
								printf("%s",cwd);
							}
						}
					}
					else if(strcmp(comdWord[1],"--help") == 0)
					{
						FILE *cdInfo;
						cdInfo = fopen("/home/paras/ques/assmt2/cdInfo.txt","r");
						if(cdInfo == NULL)
						{
							perror("File Not Found");
						}
						char liner[400];
						while(fgets(liner,400,cdInfo))
						{
							printf("%s",liner);
						}
						fclose(cdInfo);
					}
					else
					{
						if(comdWord[2] != NULL)
						{
							perror("Too many Arguments Passed");
						}
						else
						{
							int notF = chdir(comdWord[1]);
							if(notF == -1)
							{
								perror("Cannot Find the directory/Invalid Command");
							}
						}
					}
				}
			}
		
			else if(strcmp(comdWord[0],"pwd") == 0)
			{
				char ch12[200];
				if(comdWord[1] == NULL)
				{
					printf("%s\n",getcwd(ch12,200));
				}
				else if(comdWord[2] != NULL)
				{
					perror("Too Many Arguments\n");
				}
				else if(strcmp(comdWord[1],"-P") == 0)
				{
					printf("%s\n",getcwd(ch12,200));
				}
				else if(strcmp(comdWord[1],"-L") == 0)
				{
					char bfr[MAX_SIZE_CMD];
					char *rePa = realpath(ch12,bfr);
					printf("%s\n",getcwd(ch12,200));
				}
				else if(strcmp(comdWord[1],"--help") == 0)
				{
					FILE *ptrFile;
					ptrFile = fopen("/home/paras/ques/assmt2/pwdInfo.txt","r");
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
				else
				{
					perror("invalid command\n");
				}
	
			}
			else if(strcmp(comdWord[0],"history") == 0)
			{
				if(comdWord[2] != NULL)
				{
					printf("Too many Arguments");
				}
				else if(comdWord[1] != NULL && strcmp(comdWord[1],"-c") == 0)
				{
					FILE *ptrFile = fopen(name,"w");
					fprintf(ptrFile,"");
				}
				else if(comdWord[1] != NULL && strcmp(comdWord[1],"--help") == 0)
				{
					FILE *ptrFile1;
					ptrFile1 = fopen("/home/paras/ques/assmt2/HistryInfo.txt","r");
					if(ptrFile1 == NULL)
					{
						perror("File Not found");
					}
					char liner[400];
					while(fgets(liner,400,ptrFile1))
					{
						printf("%s",liner);
					}
					fclose(ptrFile1);
				}
				else if(comdWord[1] == NULL)
				{
					FILE *ptrFile2 = fopen(name,"r");
					char lineW[1028];
					int count = 1;
					while (fgets(lineW,1028,ptrFile2))
					{
						printf("%d: ",count);
						printf("%s",lineW);
						count += 1;
					}
					fclose(ptrFile2);
				}
				else
				{
					perror("Invalid Command");
				}
			}
			else if(strcmp(comdWord[0],"echo") == 0)
			{
				if(comdWord[3] != NULL || comdWord[2] != NULL)
				{
					perror("Too Many Arguments");
				}
				else if(comdWord[1] == NULL)
				{
					perror("Too few Arguments");
				}
				else if(strcmp(comdWord[1],"--help") == 0 && comdWord[2] == NULL)
				{
					FILE *ptrFile1;
					ptrFile1 = fopen("/home/paras/ques/assmt2/echoInfo.txt","r");
					if(ptrFile1 == NULL)
					{
						perror("File not Found");
					}
					char liner[400];
					while(fgets(liner,400,ptrFile1))
					{
						printf("%s",liner);
					}
					fclose(ptrFile1);
				}
				else if(strcmp(comdWord[1],"-E") != 0 && strcmp(comdWord[1],"-n") != 0)
				{
					perror("Invalid Command");
				}
				else
				{
					FILE *ptrFile = fopen(name,"a+");
					char inputTxt[50];
					fgets(inputTxt,50,stdin);
					fputs(inputTxt,ptrFile);
					fclose(ptrFile);
					char *txt = inputTxt;
					char *txt2 = strtok(txt,"\n");
					txt = txt2;
					if(strcmp(comdWord[1],"-E") == 0)
					{
						printf("%s\n",txt);
					}
					else if(strcmp(comdWord[1],"-n") == 0)
					{
						printf("%s",txt);
					}
					/*else if(strcmp(comdWord[1],"--help") == 0)
					{
						FILE *ptrFile1;
						ptrFile1 = fopen("/home/paras/ques/assmt2/echoInfo.txt","r");
						if(ptrFile1 == NULL)
						{
							perror("File not Found");
						}
						char liner[400];
						while(fgets(liner,400,ptrFile1))
						{
							printf("%s",liner);
						}
						fclose(ptrFile1);
					}*/
				}
			}
			else if(strcmp(comdWord[0],"exit") == 0)
			{
				if(comdWord[2] != NULL)
				{
					perror("Too many Arguments");
				}
				//else if(comdWord[1] == NULL)
				//{
				//	exit(0);
				//}

				else if(strcmp(comdWord[1],"1") == 0 || strcmp(comdWord[1],"0") == 0)
				{
					if(strcmp(comdWord[1],"1") == 0)
					{
						exit(1);
					}
					else if(strcmp(comdWord[1],"0") == 0)
					{
						exit(0);
					}

				}
				else if(strcmp(comdWord[1],"--help") == 0)
				{
					FILE *ptrFile;
					ptrFile = fopen("/home/paras/ques/assmt2/exitInfo.txt","r");
					char liner[200];
					if(liner == NULL)
					{
						perror("File Not Found");
						exit(0);
					}
					while(fgets(liner,200,ptrFile))
					{
						printf("%s",liner);
					}
					fclose(ptrFile);
				}
				else
				{
					perror("Invalid Option");
				}

			}
			else if(strcmp(comdWord[0],"cat") == 0)
			{
				if(comdWord[1] != NULL)
				{
					perror("Enter the Arguments/Option in subsequentl;ine");
				}
				char *testingArgs[] = {"sh","-c","gcc -o /home/paras/ques/assmt2/cat.o /home/paras/ques/assmt2/cat.c; /home/paras/ques/assmt2/cat.o",0};
				pid_t pid;
				pid = fork();
				if(pid == 0)
				{
					execvp(testingArgs[0],testingArgs);
				}
				else
				{
					wait(NULL);
				}
			}


			else if(strcmp(comdWord[0],"date") == 0)
			{
				if(comdWord[1] != NULL)
				{
					perror("Enter the Arguments/Option in subsequent Line");
				}
				char *testingArgs[] = {"sh","-c","gcc -o /home/paras/ques/assmt2/date.o /home/paras/ques/assmt2/date.c; /home/paras/ques/assmt2/date.o",0};
				pid_t pid;
				pid = fork();

				if (pid == 0)
				{
					execvp(testingArgs[0],testingArgs);
				}
				else
				{
					wait(NULL);
				}
			}


			else if(strcmp(comdWord[0],"ls") == 0)
			{
				if(comdWord[1] != NULL)
				{
					perror("Enter the Arguments/Option in subsequent Line");
				}
				char *testingArgs[] = {"sh","-c","gcc -o /home/paras/ques/assmt2/ls.o /home/paras/ques/assmt2/ls.c; /home/paras/ques/assmt2/ls.o",0};
				pid_t pid;
				pid = fork();
				if (pid == 0)
				{
					execvp(testingArgs[0],testingArgs);
				}
				else
				{
					wait(NULL);
				}
			}  


			else if(strcmp(comdWord[0],"rm") == 0)

			{
				if(comdWord[1] != NULL)
				{
					perror("Enter the Arguments/Option in subsequent Line");
				}
				char *testingArgs[] = {"sh","-c","gcc -o /home/paras/ques/assmt2/rm.o /home/paras/ques/assmt2/rm.c; /home/paras/ques/assmt2/rm.o",0};
				pid_t pid;
				pid = fork();
				if (pid == 0)
				{
					execvp(testingArgs[0],testingArgs);
				}
				else
				{
					wait(NULL);
				}
			}  

			else if(strcmp(comdWord[0],"mkdir") == 0)
			{
				if(comdWord[1] != NULL)
				{
					perror("Enter the Arguments/Option in subsequent Line");
				}
				char *testingArgs[] = {"sh","-c","gcc -o /home/paras/ques/assmt2/mkdir.o /home/paras/ques/assmt2/mkdir.c; /home/paras/ques/assmt2/mkdir.o",0};
				pid_t pid;
				pid = fork();
				if (pid == 0)
				{
					execvp(testingArgs[0],testingArgs);
				}
				else
				{
					wait(NULL);
				}
			}
			else
			{
				perror("Command Not Found");
			}
			comdWord[0] = NULL;
			comdWord[1] = NULL;
			comdWord[2] = NULL;
			comdWord[3] = NULL;
			comdWord[4] = NULL;
		

		}
	}
	return 0;
}

