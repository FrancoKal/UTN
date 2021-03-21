/**
	\file 3cuadros.c
	\brief función principal que muestra por pantalla la matriz binaria
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date 2019.05.17
	\version 1.2.0 
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
#include <stdlib.h>
#include <unistd.h>

#define PRENDIDO 1
#define ESPERO 500000
#define VUELTAS 100
#define CARACTER "#"
#define VACIO " "
#define CUADROS 3
#define MAX 100


int main (void)
{


	char imagen [CUADROS] [MAX] [MAX];
	int filas, colu, i, j, cuadro, parapasar, veces;

	printf("Ingresa el tamaño de la matriz.\n Filas: ");
	scanf("%d", &filas);
	printf("Columnas: ");
	scanf("%d", &colu);
	

	for (cuadro=0; cuadro<CUADROS; cuadro++) {

		for (i=0; i<filas; i++) {
			printf("Ingresa la linea %d de la imagen %d: ", i, cuadro);
			scanf("%d", &parapasar);
			if (parapasar>=pow(2,colu)) printf("Valor fuera de rango. Ingrese nuevamente la linea %d.\n********\n", i--); 
			else {
				for (j=colu-1;j>=0;j--) {
					imagen [cuadro] [i] [j] = parapasar % 2;
					parapasar = parapasar/2;
				}
				imagen [cuadro] [i] [j] = parapasar;
			}
		}
	}


	for ( veces = 0; veces<VUELTAS; veces++) {
		usleep (ESPERO);
		system("clear");

		cuadro = veces % CUADROS; 

//		printf ("%d", veces);
		printf ("\n\n");

		for (i=0; i<filas; i++) {
			for (j=0; j<colu; j++) {
				if (imagen [cuadro] [i] [j] == PRENDIDO) printf(CARACTER);
				else printf(VACIO);
			}
			printf ("\n");
		}

/*
		printf("\n    ");
		for(j=colu-1; j>=0; j--)
			printf("¨");

		printf("\n    ");
		for(j=colu-1; j>=0; j--)
			printf("%d", j%10);
		printf ("\n\n");



		printf("\n\n--------------------------------------\n\n");
		for (i=0; i<filas; i++) {
			printf ("%d: ",i); 
			for (j=0; j<colu; j++) {
				printf ("%d", imagen [cuadro] [i] [j]);
			}
			printf ("\n");
		}
*/

	}



	return  0;

}
