
/**
	\file main.c
	\brief función principal que muestra por pantalla la matriz binaria
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date 2019.05.17
	\version 1.0.0 
*/ 

/**
	\fn int main (void);
	\brief función principal que muestra por pantalla la matriz binaria
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date 2019.05.17
	\return Devuelve un 0 si termina en forma exitosa
*/



#include <stdio.h>
#include "funciones.h"

int main (void)
{

	int pasamelo, i, j, descompongo, lineas;
	char imagen [MAX] [MAX];

	printf("Ingresa cantidad de lineas: ");
	scanf("%d", &lineas);

	if (lineas> MAX) lineas = MAX;

	for (i=0; i<lineas; i++) {
		printf("Ingresa la linea %d de la imagen: ", i);
		scanf("%d", &pasamelo);
		descompongo = aBinario (pasamelo);
		for (j=0;j<MAX;j++) {
			imagen [i] [j] = descompongo % 10;
			descompongo=descompongo/10;
		}
	}

	printf ("\n");
	printf ("\n");

	for (i=0; i<lineas; i++) {
		for (j=0; j<MAX; j++) {
			if (imagen [i] [j] == PRENDIDO) printf(CARACTER);
			else printf(VACIO);
		}
		printf ("\n");
	}

	printf("\n\n--------------------------------------\n\n");
	for (i=0; i<lineas; i++) {
		printf ("%d: ",i); 
		for (j=0; j<MAX; j++) {
			printf ("%d", imagen [i] [j]);
		}
		printf ("\n");
	}

	return  0;

}
