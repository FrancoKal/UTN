#include <stdio.h>

void imprimo (int * vector, int largo);

int main (void)
{

//	int V[] = {44, 37, 67, 25, 81, 76, 54, 28};
	int V[] = {25, 28, 37, 44, 54, 67, 76, 81};

	int i, j=0;
	int aux;
	int mecambio =1;
	int largo = 8;

	imprimo (V, largo);

	while (mecambio != 0)
	{
		mecambio = 0;
		for (i=0; i<largo-1-j ; i++)
		{
			if (V[i] > V[i+1])
			{
				aux = V[i];
				V[i] = V[i+1];
				V[i+1] = aux;
				mecambio = 1;
			}
		}
		j++;

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
//	printf("|\n-----------------------------------------\n");
}

