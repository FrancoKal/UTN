


#include <stdio.h>

int main (void)
{
	int i;
	int base, evaluar;

	printf("Ingrese el número a evaluar: ");
	scanf("%d", &base);

	for (i=1; i < 1000; i = i+1)
	{
		evaluar = base/i;
		if (base == (evaluar * i))
		{
			printf("Encontré un divisor y es: %d\n", i);
		}
	}

	return 0;
}
