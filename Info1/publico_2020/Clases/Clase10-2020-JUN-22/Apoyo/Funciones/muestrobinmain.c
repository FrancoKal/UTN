
#include "muestrobinfunc.h"

int main (void)
{

	int valor;
	int i=0, largo;
	char bin[MAX_BIN];


	printf("Ingrese el valor para convertir a binario: ");
	scanf("%d", &valor);

	largo = convierto (valor, bin);


	printf("El valor convertido es: \n");

	for ( i=largo ; i >= 0 ; i-- )
	{
		printf("%d",bin[i]);
		if (!(i%4)) printf(" ");
	}

	printf("\n");

	return 0;

}

