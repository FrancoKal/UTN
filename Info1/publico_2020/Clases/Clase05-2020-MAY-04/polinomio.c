/*
Realizar un programa que solicite un número entero positivo en decimal (se debe validar que sea positivo) y muestre por pantalla el polinomio correspondiente indicando las potencias de mayor a menor.

Por ejemplo, si el programa recibe 345.678 y la base 10 mostrará por pantalla:
3 * 10^5 + 4 * 10^4 + 5 * 10^3 + 6 * 10^2 + 7 * 10^1 + 8 * 10^0  = 345678
*/

#include <stdio.h>

int main (void)
{


	int numero, contador=0, muestro, i, divido = 1;


	printf("\n\nIngrese el número a descomponer: ");
	scanf("%d", &numero);

	muestro = numero;

	do
	{
		muestro = muestro/10;
		contador++;
		divido = divido*10;
	}
	while(muestro!=0);

	muestro = numero;
	divido = divido / 10;

	for (i=(contador-1); i>0; i--)
	{
		printf("%d * 10^%d + ", muestro/divido, i);
		muestro = muestro % divido;
		divido = divido / 10;
	}

	printf(" %d * 10^%d = %d\n\n", muestro, i, numero);

	return 0;
}

