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
	
	int status = -1;

	//input format 
	// /file/directory command
	char fd[256];
	char cmd[256];
	printf(">>welcome to C System call interpreter\n");
	
	while (strcmp(fd,"quit"))
	{
		printf(">>");
		//scan the file destination
		scanf("%s",fd);
		if (!strcmp(fd,"quit"))
			break;
		//scan command--not neccessary for execl()
		scanf("%s",cmd);
		

		int child = fork();
		pid_t pid, pid_p;
		if (child == 0)
		{
			pid = getpid();
			//execl() & execlp() work but I'm not sure if we are to implement other exec() family functions
			//and how would we even do that?
			execlp(fd,cmd,0,(char*) NULL);
			perror("Interpreter failure");
		}
		else
		{
			pid_p = getpid();
			waitpid(child,&status,0);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}


