#include "funciones.h"

int main ()
{

	int oper1, oper2;

	printf("Ingrese un número entero de menos de 10 dígitos: ");
	scanf ("%d",&oper1);
	printf("Ingrese otro número entero de menos de 10 dígitos: ");
	scanf ("%d",&oper2);

	if (oper1 > oper2)
	{
		calculo (oper1, oper2);
	}
	else
	{
		calculo (oper2, oper1);
	}

	return 0;
}


