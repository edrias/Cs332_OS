/*Emmanuil Simkhayev
 * CSc332 task-4
 * Problem 1*/
#include <stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
	char command[256];
	int status = -1;
	
	printf(">>Simkhayev C Interpreter\n");
	while(1)
	{
		printf(">>");

		fgets(command,sizeof(command),stdin);

		if (strcmp(command,"quit") == 0)
			break;

		char *args[128];
		char **next = args;
		char *token = strtok(command," \n");
		
		while(token !=NULL)
		{
			*next++ = token;
			token = strtok(NULL, " \n");
		}
		*next = NULL;

		int child = fork();
		if (child == 0)
		{
			execvp(args[0],args);
			perror("EXECVP Error");
		}
		else
			waitpid(child,&status,0);

		printf("\n");
	}
	return EXIT_SUCCESS;
}
