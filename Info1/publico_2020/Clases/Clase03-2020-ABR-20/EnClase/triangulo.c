/**---------------------------------------- 
Curso r1041 (2020)
Clase 3 - Estructuras de Selección
Realizar un programa al que se le brinden tres valores e informar si los mismos 
corresponden a los lados de un triángulo o no. Usando if anidados
----------------------------------------*/

#include <stdio.h>


int main(void)
{
	int LadoA = 2;
	int LadoB = 2;
	int LadoC = 2;

	if (LadoA+LadoB >= LadoC)
	{
		if (LadoA+LadoC >= LadoB)
			if (LadoC+LadoB >= LadoA)
				printf("Es un triangulo\n\n");
	}
	else
	{
		printf("No es un triangulo\n\n");
	}

	return 0;
}
