/*Emmanuil Simkhayev
 * Task-3 Problem 3 steps 3 + 4*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	//fork child process and execute Prcs_P1. 
	int child_1 = fork();
	int status = -1;
	char *args1[2];
	args1[0] = "./Prcs_P1";
	args1[1] = NULL;
	
	if (child_1 == 0)
	{
		
		printf("Child 1 Pid: %d\n",getpid());
		sleep(1);
		execv(args1[0],args1);
		sleep(1);
		printf("EXECV Prcs_P1 failed\n");
		sleep(1);
	}
	else
	{
		printf("Parent of child 1 is : %d\n",getpid());
		sleep(1);
		waitpid(child_1,&status,0);
		sleep(1);
	}

	int child_2 = fork();
	int status2 = -1;
	char *args2[2];
	args2[0] = "./Prcs_P2";
	args2[1] = NULL;
	sleep(1);
	if (child_2 == 0)
	{
		printf("Child 2 Pid: %d\n",getpid());
		sleep(1);
		execv(args2[0], args2);
		sleep(1);
		printf("EXECV  Prcs_P2 failed\n");
		sleep(1);

	}
	else
	{
		printf("Parent of child 2 is: %d\n",getpid());
		waitpid(child_2,&status2,0);
		sleep(1);
	}
}
