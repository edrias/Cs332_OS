/*Emmanuil Simkhayev
 * task-3 question 3 parts 1 & 2.*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	//part1. 
	//create two files named destination1.txt & destination2.txt, with
	//read, write, and execute permissions.
	
	int fd, fd1,fd2;
	//open source file
	fd = open("source.txt", O_RDWR);//open source.txt
	
	fd1 = open("destination1.txt",O_WRONLY);
	fd2 = open("destination2.txt",O_WRONLY);
	
	if (fd1 == -1 )
	{
		printf("\n open() failed with error [%s]\n", strerror(errno));
	}
	else
	{
		printf("\n destination1.txt opened successfully");
	}
	//check destination2.txt
	if (fd1 == -1 )
	{
		printf("\n open() failed with error [%s]\n", strerror(errno));
	}
	else
	{
		printf("\n destination2.txt opened successfully");
	}


	if(fd == -1)
	{
		printf("\n open() failed with error [%s]\n", strerror(errno));
	}
	else
	{
		printf("\n source.txt opened successfully\n");
	}
	
	//copy from source to destinations. 
	//first read next 100 chars from source and repace each char '1' with an 'A'
	//then read next 50 characters and replace '2' with 'B'
	FILE *fp = fopen("source.txt","r");
	fseek(fp,0,2);
	int file_size = ftell(fp);

	//read source file
	int rd;
	int fd1_bufsize = 100;
	int fd2_bufsize = 50;

	char buf[file_size];//store contents of source here.
	
	int index = 0;

	while(index < file_size)
	{
		rd = read(fd,buf,fd1_bufsize);//read 100 characters
		int a = strlen(buf);
		
		for ( int i = 0; i < fd1_bufsize; i++)
		{
			if (buf[i] == '1')
				buf[i] = 'A';
		}
		
		write(fd1,buf,fd1_bufsize);//write 100 characters
		
		if (index + 100 >file_size)
		{
			//if the source file has less than 100 characters left
			index += (file_size - index);
			//buffer size of fd1 less than 100 now.
			fd1_bufsize = file_size - index; 
		} 
		else
			index +=fd1_bufsize;

		if (index== file_size)
			break;
		
		rd = read(fd,buf,fd2_bufsize);
		for ( int i = 0; i < fd2_bufsize; i++)
		{
			if (buf[i] == '2')
				buf[i] = 'B';
		}

		write(fd2,buf,fd2_bufsize);//write 50 characters to fd2

		if (index + 50 >file_size)
		{
			//if the source file has less than 50 characters left
			index += (file_size - index);
			//buffer size of fd1 less than 100 now.
			fd2_bufsize = file_size - index;
			fd1_bufsize = file_size-index;
			
		} 
		else
			index +=fd2_bufsize;	
	}
	//printf("file size of source.txt: %d\n",file_size);

	
	close(fd);
	return 0;

}
