//Un solo hijo y wait


#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main (void)
{
	int pid, mi_pid, pariente_pid;

	printf("Comenzando la procreación.\n");

	pid = fork();

	if(pid)
	{
		mi_pid = getpid();
		pariente_pid = pid;
		printf("Soy el papá, mi pid es %d y el de mi hijo es %d.\n", mi_pid, pariente_pid);
		sleep(45);
		printf("Papá se va.\n");
	}
	else
	{
		mi_pid = getpid();
		pariente_pid = getppid();
		printf("Soy el hijo, mi pid es %d y el de mi papá es %d.\n", mi_pid, pariente_pid);
		sleep(70);
		printf("Hijo se va.\n");
	}



	return 0;
}
