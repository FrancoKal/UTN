#include "conversof.h"



int main (void)
{

	char coef [MAXBITS];
	int valor;

	printf("Por favor, ingresa un numero para convertir: ");
	scanf("%d", &valor);

	telopaso (valor, coef);

	printf("El valor %d pasado a decimal es: ", valor);

	muestro (coef);

	return 0;
}
