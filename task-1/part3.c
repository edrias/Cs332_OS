/*Emmanuil Simkhayev Task-1 Problem 3*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>



int main(int argc, char *argv[])
{ 
	//read source.txt 100 characters at a time.
	//replace each character '1' with an 'A'.
	//b) write characters "XYZ" into file destination.txt
	
	int fd;
	char* filepath = argv[1];
	FILE *fp = fopen(argv[1],"r");//Need this to get size of file.

	if (3!= argc)
	{
		printf("Usage:\n");
		return 1;
	}

	errno = 0;

	fd = open(filepath, O_RDWR);//open file

	if(-1==fd)
	{
		printf("%s open() failed with error [%s]\n", strerror(errno));
		return 1;
	}

	//get size of file
	fseek(fp,0,2);
	int file_size = ftell(fp);
	//printf("size: %d\n",size);
	
	//read source file.
	int rd;
	int buf_size = 100;//number of characters to write.
	char buf[file_size];//store contents of source in here.
	//we know the size of the file so we can stop iterating when we exceed that size.
	int index = 0;
	int destination_fd = open(argv[2],O_RDONLY|O_WRONLY,0666);//0666 to give read/write permission for all.
	

	while(index != file_size)
	{
		rd = read(fd,buf,buf_size);//read 100 digits at a time.
		write(destination_fd,buf,buf_size);
		write(destination_fd,"XYZ",3);//write XYZ after 100 characters

		if (index + 100 > file_size)//when there are less than 100 characters left
		{
			index+= (file_size - index);//increment index by number of characters left.
			buf_size = file_size-index;
		}
		else
			index +=buf_size;//otherwise increment by 100
	}
	close(fd);
	close(destination_fd);
	
	return 0;
}

