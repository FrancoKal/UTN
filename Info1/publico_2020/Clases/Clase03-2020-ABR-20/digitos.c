
#include <stdio.h>

int main (void)
{

	int cont = 1;

	int numero;

	printf("Ingrese al número a evaluar: ");
	scanf("%d", &numero);

	while (numero>10)
	{
		numero = numero/10;
		cont++;
	}

	printf("Cantidad de digitos: %d\n", cont);

	return 0;
}
