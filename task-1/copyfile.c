/*Emmanuil Simkhayev - Task-1 Problem 2.
 * copy the cp command of bash. */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>


int main(int argc, char *argv[]) 
{
	//first open file you want to copy.
	
	int fd;
	//char* filepath = argv[1];
	char* filepath = argv[1];
	if (3 != argc)
	{
		printf("\n Usage: \n");
		return 1;
	}

	errno = 0;
	//check if file exists or has permissions.
	fd = open(filepath, O_RDWR);

	if (-1 == fd)
	{
		printf("%s open() failed with error [%s]\n",strerror(errno));
		return 1;
	}
	else
		printf("open() successfull\n");

	//read the file
	int rd;
	char buf[1080];
	
	//check read access
	

	rd = read(fd,buf,1080);

	//char* destination = argv[2];
	//open destination file.
	int destination_fd = open(argv[2],O_RDONLY|O_WRONLY,0666);
	
	//check if destination file has write access
	
	write(destination_fd,buf,1080);
	
	close(destination_fd);
	close(fd);

	return 0;
}
