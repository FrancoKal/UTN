
#include <stdio.h>

void cambio (int *, int *);

int main (void)
{

	int op1, op2;

	op1 = 45;
	op2 = 67;

	printf("Te cuento que op1 vale %d, y op2 vale %d.\n", op1, op2);

	//los voy a dar vuelta;
	cambio(&op1, &op2);

	printf("Te cuento en cambio ahora op1 vale %d, y op2 vale %d.\n", op1, op2);

	return 0;
}


void cambio (int * oper1, int * oper2)
{
	int aux;

	aux = *oper2;
	*oper2 = *oper1;
	*oper1 = aux;

	printf("En la función oper1 vale %d, y oper2 vale %d.\n", *oper1, *oper2);

	return;
}
