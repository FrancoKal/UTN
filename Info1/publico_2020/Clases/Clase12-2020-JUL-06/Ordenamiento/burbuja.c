#include <stdio.h>

void imprimo (int * vector, int largo);

int main (void)
{

	int V[] = {44, 37, 67, 25, 81, 76, 54, 28};

	int i, j;
	int aux;
	int largo = 8;

	imprimo (V, largo);

	for(j=0; j < largo-1; j++)
	{
		for (i=0; i<largo-1-j ; i++)
		{
			if (V[i] > V[i+1])
			{
				aux = V[i];
				V[i] = V[i+1];
				V[i+1] = aux;
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

