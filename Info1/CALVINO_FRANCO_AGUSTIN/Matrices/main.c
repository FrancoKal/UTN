#include "matrix.h"

int main (void)
{
	int i;
	iMatrix M[3] = {NULL};

	for (i = 0; i < CANT_MATRICES; i++)
	{
		printf("Ingresa filas y columnas para la matriz %i: ", i+1);
		scanf("%i %i", &M[i].rows, &M[i].cols);
		M[i] = iMatrix_Malloc(M[i].rows, M[i].cols);
		printf("Ingresa la matriz %i\n", i+1);
		iMatrix_Scanf(&M[i]);
	}

	if (M[0].mat != NULL && M[1].mat != NULL)
	{
		M[2] = iMatrix_Product(M[0], M[1]);

		if (M[2].mat != NULL)
		{
			iMatrix_Printf(iMatrix_ScalarProduct(M[2], 2));
			
			for (i = 0; i < CANT_MATRICES + 1; i++)
			{
				printf("det(M[%i]) = %i\n", i+1, iMatrix_Det(M[i]));
				iMatrix_Free(&M[i]);
			}
		}
	}

	return 0;
}
