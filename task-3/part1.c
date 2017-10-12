#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>

/*Write a program where a child is created to execute command that tells you thedate and time in Unix
 * Use execl(...)
 * Speceify full path of the file name that gives you date and time information.
 * Announce the successful forking of child process by displaying its PID.*/

int main(int argc, char *argv[]) {

	int child = fork();
	int status = -1;
	//printf("\n");
	//execl("/bin/date","date",0, (char*) NULL);
	
	//int child = fork();
	if (child == 0){

		printf("The PID of child is %d\n",getpid());
		execl("/bin/date","date",0, (char*) NULL);
		perror("execl() Failure!\n");

	}

	else {
		printf("Parent PID: %d\n",getpid());
		
		waitpid(child,&status,0); 
		printf("Child exited with return code %d\n",status);

	}

	return 0;
}
	

