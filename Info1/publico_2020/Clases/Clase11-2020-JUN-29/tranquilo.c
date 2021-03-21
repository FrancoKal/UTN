#include <stdio.h>


int main (int argc, char * argv [], char * envp [])
//(1) int main (int argc, char ** argv, char * envp [])
{


	int i;

	printf("Ingresaste los siguientes parametros: \n");

	for (i=0; i< argc; i++)
	{
		printf("El argumento %d es: %s\n", i, argv[i]);
//(1)		printf("El argumento %d es: %s\n", i, *(argv+i));
	}

	i = 0;

	printf("\n----------------------------------------------------\n");
	
	while (envp[i] != NULL)
	{
		printf("El argumento de entorno %d es: %s\n", i, envp[i]);
		i++;
	}

	return 0;
}
