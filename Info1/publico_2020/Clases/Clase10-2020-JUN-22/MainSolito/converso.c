#include <stdio.h>


#define BASE 2
#define MAXBITS 32


int main (void)
{


	int coef [MAXBITS];
	int valor, tempo;
	int i = 0;

	printf("Por favor, ingresa un numero para convertir: ");
	scanf("%d", &valor);

	tempo = valor;

	while (tempo >= BASE)
	{
		coef [i] = tempo % BASE;
		tempo = tempo / BASE;
		i=i+1;  //i++;
	}

	coef[i] = tempo;

	printf("El valor %d pasado a decimal es: ", valor);

	for ( ;i >= 0; i--)
	{
		printf("%d", coef[i]);
	}

	printf("\n\n");

	return 0;
}
