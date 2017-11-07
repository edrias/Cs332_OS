/*Emmanuil Simkhayev
 * CSC332 - Task 4
 * Problem 2*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<errno.h>

int main(int argc, char *argv[])
{
	int x, y;//Chapters, Homeworks
	x = 2;
	y = 2;
	int students = 10;
	int hwch = x*y;//number of columns
	int matrix[students][hwch];//2d array of studends vs (Chapters * Homeworks)
	//read file with grades
	FILE *grades = fopen("grades.txt", "r");
	

	int curr_numb;//result of current scanned number of grades.txt
	
	//nested for loop for parsing the numbers in grades.txt into matrix
	for(int i = 0; i < students; ++i)
	{
		for (int j = 0; j < hwch; ++j)
		{
			fscanf(grades, "%d", &curr_numb);
			matrix[i][j] = curr_numb;
		}
	}
	fclose(grades);

	//start processes
	for (int rows = 0; rows<x; ++rows)
	{
		//fork manager 
		int manager = fork();
		if (manager < 0)
			printf("Manger Error");
		else if (manager == 0)
		{
			for (int cols = 0; cols < x; ++cols)
			{
				//worker process start
				int worker = fork();

				if (worker < 0)
					printf("Worker Error");
				else if (worker == 0)
				{
					double score = 0;
					double avg = 0;
					//calculate average
					for( int j = 0; j < students; ++j)
					{
						score = score + matrix[j][cols];//update total score
				
					}
					avg = double(score/students);
					printf("Chapter %d, Homework %d average: %f \n",rows+1,cols+1,avg);
					exit(worker);
				}
				wait(&worker);
			}
			return 0;
		}
		wait(&manager);
	}
	return 0;
}


	

