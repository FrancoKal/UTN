#include <stdio.h>
#include <stdlib.h>

#define LONG 4

union endian
{
	unsigned int valor;
	unsigned char byte[LONG];
};


int main (int cant, char ** argv)
{

	union endian evaluar;
	int i, j;

	if  (cant > 1)
	{
		for (i=1; i< cant; i++)
		{
			evaluar.valor = (unsigned int) atoi (*(argv+i));
			printf("Mostrando byte a byte el argumento %d (%u - %x): \n", i, evaluar.valor, evaluar.valor);
			for (j=0; j<LONG; j++)
			{
				printf("[%d]: %02x\n", j, evaluar.byte[j]);
			}
		}
	}
	else
	{
		printf ("No hay nada para procesar.\n\n");

	}
}
