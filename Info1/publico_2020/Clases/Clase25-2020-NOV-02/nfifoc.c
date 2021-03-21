#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX 5
#define TAM 4
#define EMISOR "emisor.fifo"
#define RECEPTOR "receptor.fifo"

int main (void)
{

	int opcion;
	char * acciones [MAX] = {"pri", "sum", "par", "imp", "dec"};
	int valor = -1;
	long int valorote = -1;
	int cuenta = 0;
	int receptor, emisor;


	printf("Indique que información desea recibir:\n");
	printf("\t1 - Numeros primos.\n\t2 - Sumatoria de numeros.\n\t3 - Numeros Pares.\n");
	printf("\t4 - Numeros impares.\n\t5 - Numeros decenas.\n\t---> ");

	do
	{
		scanf("%d", &opcion);
		if((opcion < 0) && (opcion > 5))
		{
			printf("Opción invalida. Reintente.\n\t---> ");
		}
	}
	while ((opcion < 0) && (opcion > 5));

	receptor = open(RECEPTOR, O_WRONLY);
	emisor = open(EMISOR, O_RDONLY);

	printf("Named pipes abiertos.\n");

	if ((receptor != -1) && (emisor != -1))
	{
		write(receptor, acciones[opcion-1], sizeof(char)*TAM);

		printf("Se envio el comando.\n");

		do
		{
			if (opcion == 2)
			{
				read(emisor, &valorote, sizeof(long int));
				if (valorote != -1)
				{
					cuenta++;
					printf("%d: %ld\n", cuenta, valorote);
				}
			}
			else
			{
				read(emisor, &valor, sizeof(int));
				if (valor != -1)
				{
					cuenta++;
					printf("%d: %d\n", cuenta, valor);
				}
			}
		}
		while ((valor != -1) || (valorote != -1));
	}

	printf("Finalizó la recepción de datos.\n");


	if (emisor != -1) close(emisor);
	if (receptor != -1) close(receptor);

	return 0;
}
