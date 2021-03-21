/*
Realizar un programa que calcule la sumatoria de todos los números 
hasta un límite dado.
*/

#include <stdio.h>

int main (void)
{

	int i, limite, resultado = 0;

//	resultado = 0;

	printf("Hasta que numero sumas: ");
	scanf("%d", &limite);

//	for(i = 1; i <= limite ;i = i + 1)
	for(i = limite; i > 0 ;i = i - 1)
	{

		resultado = resultado + i;

	}

	printf("La sumatoria de %d es: %d\n", limite, resultado);

	return 0;
}
