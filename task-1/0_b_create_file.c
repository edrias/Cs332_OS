/*Emmanuil Simkhayev CSc-332 Task-1*/
/* Task-1 problem 0.b - Write a C program where open system call creates a new file (say, desintation.txt) and then opens it. (Hint: use bitwise OR flag)*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd;
	if(2 != argc)
	{
		printf("\nUsage : \n");
		return 1;
	}

	errno = 0;
	fd = open(argv[1],O_CREAT | O_RDONLY|O_WRONLY,0666);
	//0666 for read/write permission.
	
	if( fd == -1)
		printf("\n open() failed with error [%s]\n",strerror(errno));

	else
		printf("\nopen() successful, file created.\n");

	close(fd);

	return 0;
}
