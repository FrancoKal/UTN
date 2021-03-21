


#include <stdio.h>

int main (void)
{
	int i;
	int suma=0, limite=100;

	for (i=1; i < limite; i = i+1)
	{
		suma = suma + i;
	}

	printf("La sumatoria hasta el valor %d es: %d\n", limite, suma);

	return 0;
}
