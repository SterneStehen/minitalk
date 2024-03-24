#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void fork2()
{
	int child_status;
	if(fork == 0)
	{
		printf("HC: hello from children\n");
	}
	else
	{
		printf("HP : hello from parents\n");
		wait(&child_status);
		printf("CT: children has terminsted\n");
	}
	printf("Bay\n");
	exit(0);
}

void fork1()
{
	int x = 1;
	pid_t pid = fork();
	if(pid == 0)
	{
		//sleep(2);
		//fork();
		printf("Child has process = %d\n", ++x);
		//exit (0);
	}
	else
	{
		//sleep(2);
		//fork();
		printf("Parents has process = %d\n", --x);
		//while (1);
	}
	printf("Bye from process %d with x = %d\n", getpid(), x);
}

int main()
{
	fork1();
	fork2();
	return 0;
}