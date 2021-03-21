
#include <stdio.h>

#define MAX_BIN 32
#define BASE 	2

int main (void)
{

	int valor;
	int i=0;
	char bin[MAX_BIN];

/*******************************************
NO LO VOY A HACER

	bitio[var];
	var = sizeof(int);

********************************************/

	printf("El tamaño de mi entero es: %ld.\n", sizeof(int));
	printf("El tamaño de mi long es: %ld.\n", sizeof(long));
	printf("El tamaño de mi float es: %ld.\n", sizeof(float));
	printf("El tamaño de mi double es: %ld.\n", sizeof(double));
	printf("El tamaño de mi char es: %ld.\n", sizeof(char));

//--------------------------------------------------------------------

	printf("Ingrese el valor para convertir a binario: ");
	scanf("%d", &valor);

	while (valor >= BASE)
	{

		//guardar el resto de cada división
		bin[i] = valor % BASE;
		i++;
		valor = valor/BASE;

/*
1234 % 2 --> 0   bin[0]
617  % 2 --> 1   bin[1]
308  % 2 --> 0   bin[2]
154  % 2 --> 0   bin[3]
77   % 2 --> 1   bin[4]
33   % 2 --> 1   bin[5]
16   % 2 --> 0   bin[6]
8    % 2 --> 0   bin[7]
4    % 2 --> 0   bin[8]
2    % 2 --> 0   bin[9]
1        --> 1   bin[10]
*/

	}

	//guardar valor como el MSB 
	bin[i] = valor;

	printf("El valor convertido es: \n");


	for ( ; i >= 0 ; i-- )
	{
		printf("%d",bin[i]);
		if (!(i%4)) printf(" ");
	}

	printf("\n");

	return 0;

}

