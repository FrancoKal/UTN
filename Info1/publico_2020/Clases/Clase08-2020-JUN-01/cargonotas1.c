#include <stdio.h>

#define MAX_ALUMNOS 50


int main (void)
{

	int notas[MAX_ALUMNOS];
	int i, total;

	print("Pido las notas:\n");

	printf("Ingresa la nota 1:");
	scanf("%d", notas[0]);

	for (i=1; (i<MAX_ALUMNOS)&&(notas[i-1]>=0);i++)
	{
		printf("Ingresa la nota %d:", i+1);
		scanf("%d", notas[i]);
	}

	total = i;

	print("Muestro las notas:\n");

	for (i=0;i<total;i++)
	{
		printf("Nota %d: %d\n", i+1, nota[i]);
	}

	return 0;
}
