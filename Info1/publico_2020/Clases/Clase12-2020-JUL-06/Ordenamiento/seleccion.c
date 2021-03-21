#include <stdio.h>

void imprimo (int * vector, int largo);

int main (void)
{

	int V[] = {44, 37, 67, 25, 81, 76, 54, 28};

	int i, j;
	int aux;
	int largo = 8;

	imprimo (V, largo);

	for (j=0; j<largo-1; j++)
	{
		for (i=j+1; i < largo; i++)
		{
			if (V[j] > V[i])
			{
				aux = V[j];
				V[j] = V[i];
				V[i] = aux;
			}
		}

		imprimo (V, largo);
	}


	return 0;
}

void imprimo (int * vector, int largo)
{
	int i;

	printf("\n-----------------------------------------\n");
	for (i = 0; i < largo; i++)
	{
		printf("| %d ", vector[i]);
	}
	printf("|\n-----------------------------------------\n");
}
