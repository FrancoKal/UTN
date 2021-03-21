#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>


#define PROLE 50000

int main (void)
{
	int pid;
	int i;

	printf("Comenzando la procreación.\n");

	for (i = 0; i < PROLE; i++)
	{ 
		pid = fork();

		if(pid > 0)
		{
			printf("Generado el hijo: %d \n", i);
		}
		else if(pid == -1)
		{
			printf("Error generando el hijo\n");
		}
		else
		{
			sleep(90);
			return 0;
		}
	}

	for (i = 0; i < PROLE; i++)
	{
		wait(NULL);
	}

	return 0;
}
