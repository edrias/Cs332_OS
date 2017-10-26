/*Emmanuil Simkhayev
 * CSc332 task-4
 * Problem 1*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
/*Write a simple interpreter where the main process creates a child process
 * to execute the command using exec() family functions. After executing the 
 * command, it asks for a new command input (i.e., parent wait for child). 
 * The interpreter program will get terminated when the user enters quit.*/


int main(int argc, char *argv[])
{
	//steps.
	//1. run interpreter
	//2. interpreter waits for command
	//3. interpeter creates child process to execute command
	//4. interpreter waits for new command(command "quit" to exit)
	
	//char fd[128] = "/bin/";
	char cmd[256];	
	//char cmd1[128];
	char *args[256];
	int status = -1;
	char *token;
	int i;
	printf(">>welcome to C System call interpreter\n");
	
	while (1)
	{
		//char fd[128] = "/bin/";
		//char cmd[256];
		//char *sec_cmd[256];//second command ex: ls -al <- -al is second command.
		printf(">>");
		//scan the /bin/ command
		//scanf("%s",cmd);
		fgets(cmd,256,stdin);
		//printf("fd0: %s\n",fd);
		printf("cmd0: %s\n",cmd);	
		//printf("cmd1: %s\n",cmd[1]);
		if (!strcmp(cmd,"quit"))
			break;
		//update fd to include command- ex. /bin/ls
		token = strtok(cmd," ");
		args[0] =token;//= strtok(NULL," ");
		printf("token: %s\n",token);
		//args = token;
		//strcat(fd,token);//of the format /bin/cmd1 ex. /bin/ls
		//printf("fd_cat: %s\n",fd);
		
		
		for (int i = 1; i < 10; ++i)			
		{
			token = strtok(NULL," ");
			//if (i ==0)
			//	strcat(fd,token);
			printf("token[%d]: %s\n",i,token);
			args[i] = token;
			printf("args[%d]: %s\n",i,args[i]);

		}
		//strcat(fd,args[0]);
		//args = cmd;
		//scanf("%[^\n]",sec_cmd);//scan until newline
		int child = fork();
		pid_t pid, pid_p;
		
		if (child == 0)
		{
			pid = getpid();
			printf("args: %s\n",args);
			//printf("fd: %s\n",fd);
			execvp(args[0],args);
			printf("Interpreter Failure: EXECVP");
			printf("\n");
			/*if (strcmp(sec_cmd,"\n"))
			{
				//printf("POOP");
				execl(fd,"cmd",0,(char*) NULL);
				perror("Interpreter failure");
			}
			else*/
			//{
				//sec_cmd[0] = cmd;
				//execv(fd,sec_cmd);
				//printf("Interpreter Failure: EXECVP");
			//}
					
		}
		else
		{
			pid_p = getpid();
			waitpid(child,&status,0);
		}

		//printf("\n");
	}
	printf("\n");
	return 0;
}



