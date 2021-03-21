#include "funciones.h"

//-----------------------------------------------------------------

void calculo (int oper1, int oper2)
{
	int i;

	if (oper2)
	{
		printf("El resultado de la división es: %f\n", (float) oper1/oper2);
	}
	else
	{
		printf("No se puede dividir por 0\n");
	}
	i= longitud(oper1);
	printf("El numero mayor tiene %d dígitos\n", i);
	printf("El doble del numero mayor es %d\n", DOBLE*oper1);
	if (oper2%PAR)
	{
		printf("El numero menor es impar\n");
	}
	else
	{
		printf("El numero menor es par\n");
	}
	printf("El triple del numero menor es %d\n", TRIPLE*oper2);
}

//-----------------------------------------------------------------

int longitud (int oper1)
{
	int i=1;

	while (oper1>BASE)
	{
		oper1 = oper1/BASE;
		i++;
	}

	return i;
}

//-----------------------------------------------------------------



