/*Emmanuil Simkhayev
 *Task-3 part 2. */

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/wait.h>


int main()
{
	int child = fork();
	int status = -1;
	
	char *args[3];
	args[0] = "ls";
	args[1] ="-al";
	//args[2] = "l";
	args[2] = NULL;
	if (child == 0)
	{
		printf("I am child, my PID is : %d\n",getpid());
 		//show all files in directory (including hidden files).
		//with information such as permissions, owner, size, and when last 
		//modified.
		
		execvp("/bin/ls", args);
		printf("EXECVP Failed\n");
		printf("EXECVP Failed\n");
	}
	else
	{
		printf("I am parent, my PID is: %d\n",getpid());
		waitpid(child,&status,0);
		printf("Child exited with return code %d\n",status);
	}
	return 0;
}


