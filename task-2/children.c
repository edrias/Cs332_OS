/*Emmanuil Simkhayev 
 *CSc332 - Task-2 - Problem 1.*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
int main(int argc, char* argv[])
{
	//Let parent process produce two child processes. 
	
	int child_1 = fork();//fork child 1
	int status = -1;//status for child 1
	int status2 = -1;//status for child 2
	if(child_1 == 0)
	{
		//print pid of child one and parent
		printf("I am child one, my PID is: %d and parent: %d\n",getpid(),getppid());
		

	}
	else
	{
		//print from parent and child one
		printf("PID in Parent : %d and child one: %d\n", getpid(),child_1);
	
		
		waitpid(child_1, &status, 0);
		printf("Child one exited with the return code %d\n",status);

	
		int child_2 = fork();
	
		if (child_2 == 0)
		{
			printf("I am child two, my PID is: %d and parent: %d\n",getpid(),getppid());
		}
		else
		{
			printf("PID in parent: %d and child two: %d\n",getpid(),child_2);
			
			waitpid(child_2, &status2, 0);
			printf("Child two exited with return code %d\n", status2);
		}

	}
	
}
