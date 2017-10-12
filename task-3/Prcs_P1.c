/*Emmanuil Simkhayev Problem 3 
 * part 1- Prcs_P1.c*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	int fd1, fd2;

	//create/open two text files
	fd1 = open("destination1.txt",O_CREAT| O_RDONLY|O_WRONLY,0666);
	fd2 = open("destination2.txt",O_CREAT| O_RDONLY|O_WRONLY,0666);

	//check destination1.txt
	if (fd1 == -1 )
	{
		printf("\n open() failed with error [%s]\n", strerror(errno));
	}
	else
	{
		printf("\n destination1.txt created successfully");
	}
	//check destination2.txt
	if (fd1 == -1 )
	{
		printf("\n open() failed with error [%s]\n", strerror(errno));
	}
	else
	{
		printf("\n destination2.txt created successfully");
	}

	printf("\n");
}	

