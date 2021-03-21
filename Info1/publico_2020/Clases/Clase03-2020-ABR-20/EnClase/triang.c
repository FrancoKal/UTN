/**---------------------------------------- 
Curso r1041 (2020)
Clase 3 - Estructuras de Selección
Realizar un programa al que se le brinden tres valores e informar si los mismos 
corresponden a los lados de un triángulo o no.
----------------------------------------*/


#include <stdio.h>


int main (void)
{

	int LadoA;
	int LadoB;
	int LadoC;

	printf("Ingresate lado A: ");
	scanf("%d", &LadoA);
	printf("Ingresate lado B: ");
	scanf("%d", &LadoB);
	printf("Ingresate lado C: ");
	scanf("%d", &LadoC);

	printf("Los lados a evaluar son: %d %d %d\n", LadoA, LadoB, LadoC);

	if (((LadoA+LadoB)>LadoC) && ((LadoB+LadoC)>LadoA) && ((LadoA+LadoC)>LadoB))
	{
		printf("Es un triangulo.\n");
	}
	else
	{
		printf("No vieja, buscate otro.\n");
	}

	return 0;
}
