#include "conversof.h"



int main (void)
{

	char coef [MAXBITS];
	int valor;
	int largo;

	printf("Por favor, ingresa un numero para convertir: ");
	scanf("%d", &valor);

	largo = telopaso (valor, coef);
//	largo = telopaso (valor, &coef[0]);

	printf("El valor %d pasado a decimal es: ", valor);

	muestro (largo, coef);

	return 0;
}
