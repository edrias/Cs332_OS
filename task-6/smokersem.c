/*Emmanuil Simkhayev 
 * Csc 332 task-6*/
#include <stdio.h>
#include <stdlib.h>
#include "sem.h"
#include <time.h>

#define PERMS 0666 //0666 - grant r/w permissions.

main () 
{
	//semaphore declaration
	int tobacco;
	int paper;
	int match;
	int agent;
	int lock;
	//process id
	int pid;

	//Create semaphores
	
	//tobacco semaphore
	if ((tobacco = semget(IPC_PRIVATE,1,PERMS | IPC_CREAT)) ==-1)
	{
		printf("\n can't create mutex semaphore");
		exit(1);
	}

	//match semaphore
	if ((match =semget(IPC_PRIVATE,1,PERMS | IPC_CREAT)) ==-1)
	{
		printf("\n can't create mutex semaphore");
		exit(1);
	}

	//paper semaphore
	if ((paper =semget(IPC_PRIVATE,1,PERMS | IPC_CREAT)) ==-1)
	{
		printf("\n can't create mutex semaphore");
		exit(1);
	}

	//lock semaphore 
	if (( lock=semget(IPC_PRIVATE,1,PERMS | IPC_CREAT)) ==-1)
	{
		printf("\n can't create mutex semaphore");
		exit(1);
	}

	//agent semaphore
	if ((agent=semget(IPC_PRIVATE,1,PERMS | IPC_CREAT)) ==-1)
	{
		printf("\n can't create mutex semaphore");
		exit(1);
	}

	//initialize semaphores
	sem_create(lock,1);
	sem_create(tobacco,0);
	sem_create(paper,0);
	sem_create(match,0);
	sem_create(agent,0);

	if ((pid=fork()) <0)
	{
		printf("\n Error in process creation");
		exit1(1);
	}

	//tobacco smoker will only wake when agent does so. Otherwise, he will sleep.
	if (pid ==0)
	{
		while(1)
		{
			P(tobacco); //go to sleep
			P(lock);
			//tobacco smoker gets paper & matches
			V(agent); 
			V(lock);
			printf("tobacco smoker is smoking \n");
		}
	}

	if ((pid=fork()) <0)
	{
		printf("\n Error in process creation");
		exit1(1);
	}
	//paper smoker will only wake when agent does so. Otherwise, he will sleep.
	if (pid ==0)
	{
		while(1)
		{
			P(paper); //go to sleep
			P(lock);
			//paper smoker gets tobacco & match
			V(agent); 
			V(lock);
			printf("paper smoker is smoking \n");
		}
	}

	if ((pid = fork()) <0)
	{
		print("\n Error in process creation");
		exit(1);
	}

	//match smoker will only wake when agent does so. Otherwise, he will sleep.
	if (pid == 0)
	{
		while(1)
		{
			P(match);
			P(lock);
			//match smoker gets tobacco & paper
			V(agent);
			V(lock);
			printf("match smoker is smoking" \n");
		}
	}

	 
