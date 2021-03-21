//Un solo hijo y wait


#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main (void)
{
	int pid, mi_pid, pariente_pid;
	int cont = 10;

	printf("Comenzando la procreación.\nCont vale: %d y está guardado en %p\n", cont, &cont);

	pid = fork();

	if(pid)
	{
		printf("Papá recibió cont con el valor: %d en la dirección %p.\n", cont, &cont);
		mi_pid = getpid();
		pariente_pid = pid;
		printf("Soy el papá, mi pid es %d y el de mi hijo es %d.\n", mi_pid, pariente_pid);
		cont = cont + 100;
		sleep(15);
		printf("Papá se va y cont vale: %d en la dirección %p.\n", cont, &cont);
	}
	else
	{
		printf("Hijo recibió cont con el valor: %d en la dirección %p.\n", cont, &cont);
		mi_pid = getpid();
		pariente_pid = getppid();
		printf("Soy el hijo, mi pid es %d y el de mi papá es %d.\n", mi_pid, pariente_pid);
		cont = cont + 1000;
		sleep(20);
		printf("Hijo se va y cont vale: %d en la dirección %p.\n", cont, &cont);
	}



	return 0;
}
