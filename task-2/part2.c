/*Emmanuil Simkhayev 
 *CSc332 - Task-2 - problem 2*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	//parent P
	int a = 10, b = 25, fq = 0, fr = 0;
	
	fq = fork();
	if(fq == 0)
	{
		a = a +b;
		printf("case 1: a: %d, b: %d, PID: %d\n",a,b,getpid());
		fr = fork();
		if(fr!=0)
		{
			b = b+20;
			printf("case 2: a: %d, b: %d, PID: %d\n",a,b,getpid());
		}
		else
		{
			a = (a*b) + 30;
			printf("case 3: a: %d, b: %d, PID: %d\n",a,b,getpid());
		}
	}
	else
	{
		b = a+b-5;
		printf("case 4: a: %d, b: %d, PID: %d\n",a,b,getpid());
	}
	

}
