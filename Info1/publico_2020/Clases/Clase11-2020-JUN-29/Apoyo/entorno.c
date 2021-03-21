

/**---------------------------------------- 
Curso r1041 (2020)
Clase 3 - Estructuras de Selección
Realizar un programa (este es uno nuevo!!!!!!) que a partir de la nota muestre la nota en letras.
----------------------------------------*/

#include <stdio.h>

int largo (char * frase);

int main (int cuanto, char * p[], char * envp[])
{

	int i=0;

	printf("Variales de entorno:\n");

	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}

	return 0;
}


