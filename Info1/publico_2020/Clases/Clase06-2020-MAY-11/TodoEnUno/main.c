#include <stdio.h>

#define DOBLE   2
#define TRIPLE  3
#define BASE   10
#define PAR     2

int main ()
{

	int oper1, oper2, i=1;

	printf("Ingrese un número entero de menos de 10 dígitos: ");
	scanf ("%d",&oper1);
	printf("Ingrese otro número entero de menos de 10 dígitos: ");
	scanf ("%d",&oper2);

	if (oper1 > oper2)
	{
 		if (oper2) printf("El resultado de la división es: %f\n", (float) oper1/oper2);
		else printf("No se puede dividir por 0\n");
		while (oper1>BASE)
		{
			oper1 = oper2/BASE;
			i++;
/*
			45678
			4567
			456
			45
			4
*/

		}
		printf("El numero mayor tiene %d dígitos\n", i);
		printf("El doble del numero mayor es %d\n", DOBLE*oper1);
		if (oper2 % PAR)
		{
			printf("El numero menor es impar\n");
		}
		else
		{
			printf("El numero menor es par\n");
		}
		printf("El triple del numero menor es %d\n", TRIPLE*oper2);
	}
	else
	{
		if (oper1)
		{
			printf("El resultado de la división es: %f\n", (float) oper2/oper1);
		}
		else
		{
			printf("No se puede dividir por 0\n");
		}
		while (oper2>BASE)
		{
			oper2 = oper2/BASE;
			i++;
		}
		printf("El numero mayor tiene %d dígitos\n", i);
		printf("El doble del numero mayor es %d\n", DOBLE*oper2);
		if (oper2%PAR)
		{
			printf("El numero menor es impar\n");
		}
		else
		{
			printf("El numero menor es par\n");
		}
		printf("El triple del numero menor es %d\n", TRIPLE*oper1);
	}

	return 0;
}

