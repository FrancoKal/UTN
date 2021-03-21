/**
	\file imagen.c
	\brief función principal que muestra por pantalla la matriz binaria
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date 2019.05.17
	\version 1.1.0 
*/ 

/**
	\fn int main (void);
	\brief función principal que muestra por pantalla la matriz binaria
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date 2019.05.17
	\return Devuelve un 0 si termina en forma exitosa
*/




#include <stdio.h>
#include <math.h>

#define PRENDIDO 1
#define MAX 100
#define CARACTER "0"
#define VACIO " "

int main (void)
{


	char imagen [MAX] [MAX];
	int filas, colu, i, j, parapasar;

	printf("Ingresa el tamaño de la matriz.\n Filas: ");
	scanf("%d", &filas);
	printf("Columnas: ");
	scanf("%d", &colu);
	

	for (i=0; i<filas; i++) {
		printf("Ingresa la linea %d de la imagen: ", i);
		scanf("%d", &parapasar);
		if (parapasar>=pow(2,colu)) printf("Valor fuera de rango. Ingrese nuevamente la linea %d.\n********\n", i--); 
		else {
			for (j=colu-1;j>=0;j--) {
				imagen [i] [j] = parapasar % 2;
				parapasar = parapasar/2;
			}
			imagen [i] [j] = parapasar;
		}
	}


	printf ("\n");
	printf ("\n");

	for (i=0; i<filas; i++) {
		printf("%2d: ", i);
		for (j=0; j<colu; j++) {
			if (imagen [i] [j] == PRENDIDO) printf(CARACTER);
			else printf(VACIO);
		}
		printf ("\n");
	}

	printf("\n    ");
	for(j=colu-1; j>=0; j--)
		printf("¨");

	printf("\n    ");
		for(j=colu-1; j>=0; j--)
			printf("%d", j%10);


	printf("\n\n--------------------------------------\n\n");
	for (i=0; i<filas; i++) {
		printf ("%d: ",i); 
		for (j=0; j<colu; j++) {
			printf ("%d", imagen [i] [j]);
		}
		printf ("\n");
	}

	return  0;

}
