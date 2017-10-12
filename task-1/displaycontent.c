/*Emmanuil Simkhayev - CSc-332 Task-1*/
/*Task-1 Problem 1 - displaycontent.c*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <iostream>

int main(int argc, char *argv[])
{
	//first, open file
	
	int fd;
	char* filepath = argv[1];
	//char buf[BUF_SIZE];
	
	FILE *fp = fopen(argv[1],"r");//Need this to get size of read file

	if(2 != argc)
	{
		printf("\n Usage: \n");
		return 1;
	}

	errno = 0;
	fd = open(filepath,O_RDWR);
	
	if(-1 == fd)
	{
		printf("\nOpen() failed with error [%s]\n", strerror(errno));
		return 1;
	}
	else
		printf("\nOpen Successful\n");
	
	//now read the file(display it)
	
	if (access(filepath,R_OK) == 0)
		printf("%sRead permission granted\n",filepath);
	else
		printf("%sRead permission denied\n",filepath);
	
	
	fseek(fp,0,2);
	int rd_file_size = ftell(fp);//size of read file
	//printf("size: %d\n",rd_file_size);	
	//store characters of file into buf,
	char buf[rd_file_size]; 
	
	int rd = read(fd,buf,rd_file_size);
	printf("%s\n",buf);
			
	close(fd);

	return 0;
}

