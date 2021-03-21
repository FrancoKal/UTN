


#include <stdio.h>

int main (void)
{

	int op1, op2, aux;

	op1 = 45;
	op2 = 67;

	printf("Te cuento que op1 vale %d, y op2 vale %d.\n", op1, op2);

	//los voy a dar vuelta;

	aux = op2;
	op2 = op1;
	op1 = aux;

	printf("Te cuento en cambio ahora op1 vale %d, y op2 vale %d.\n", op1, op2);

	return 0;
}
