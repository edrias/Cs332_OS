/*Emmanuil Simkhayev - CSc-322 Task-1*/
/* Task-1 problem 0.a - Extend code snippet 1 to check for read adn write access permissions of a given file.*/

#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char* argv[])
{
	char* filepath = argv[1];
	int returnval;

	//check file existence
	returnval = access(filepath, F_OK);
	if (returnval == 0)
		printf("\n%s exists\n", filepath);
	else
	{
		if (errno == ENOENT)
			printf("%s does not exist\n", filepath);
		else if (errno == EACCES)
			printf("%s is not accessible\n", filepath);
		return 0;
	}

	//check read access
	if (access(filepath, R_OK) == 0) 
		printf("%s read permission granted\n",filepath);
	else
		printf("%s read permission denied\n", filepath);

	//Check write acess
	if (access(filepath, W_OK) == 0)
		printf("%s write permission granted\n",filepath);
	else
		printf("%s write permission denied\n", filepath);

	printf("\n");

	return 0;
}

