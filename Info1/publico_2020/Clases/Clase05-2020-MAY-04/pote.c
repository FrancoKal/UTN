/*
Realizar un programa pote que sin recurrir a las funciones definidas en math.h calcule la base elevada al exponente. 
El exponente podrá ser un valor entero positivo o negativo.
El programa deberá solicitar ambos argumentos.
*/

#include <stdio.h>

float pote(int BaSe, int ExpOnEntE);

int main (void)
{

	int base, exponente;

	printf("\n\nIngrese la Base: ");
	scanf("%d", &base);
	printf("Ingrese el Exponente: ");
	scanf("%d", &exponente);

	printf("El resultado de %d elevado a la %d tiene por resultado : %f.\n\n", base, exponente, pote(base, exponente));

	return 0;
}


float pote(int BaSe, int ExpOnEntE)
{

	int signo = 0, i;
	float acumulado =1;

	if (ExpOnEntE < 0)
	{
		signo = 1;
		ExpOnEntE = ExpOnEntE * -1;

	}

	for (i=1; i<=ExpOnEntE; i++)
	{
		acumulado = BaSe * acumulado; 
	}

	if(signo) acumulado = 1/acumulado;

	return acumulado;
}
