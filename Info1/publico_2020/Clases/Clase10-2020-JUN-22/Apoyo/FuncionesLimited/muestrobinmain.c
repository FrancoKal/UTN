
#include "muestrobinfunc.h"

int main (void)
{

	int valor;
	int i=0;
	char bin[MAX_BIN+1];


	printf("Ingrese el valor para convertir a binario: ");
	scanf("%d", &valor);

	convierto (valor, bin);

	printf("El valor convertido es: \n");

	while (bin[i]!= BASE)
	{
		i++;
	}

	i--;

	for ( ; i >= 0 ; i-- )
	{
		printf("%d",bin[i]);
		if (!(i%4)) printf(" ");
	}

	printf("\n");

	return 0;

}

