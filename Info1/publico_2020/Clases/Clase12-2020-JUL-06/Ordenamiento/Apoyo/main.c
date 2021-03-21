/**
	\file    main.c
	\brief   Archivo de prueba de los diferentes metodos de ordenamiento vistos
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2020.07.06
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------

#include "funcionesord.h"

/**
	\fn      int main (void)
	\brief   Función main que pide el metodo de ordenamiento
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2020.07.06
	\return  int : Código con el resultado del funcionamiento de main.
*/


int main (void)
{

	int V[] = { 44, 37, 67, 25, 81, 76, 54, 28};

	int largo = 8;
	int metodo;

	printf("Vamos a ordenar el vector: \n");

	imprimir(V, largo);

	printf("Elegí el metodo: \n");
	printf("\t0 - Seleccion\n");
	printf("\t1 - Burbuja\n");
	printf("\t2 - Burbuja Mejorado\n");
	printf("\tOpcion: ");
	scanf("%d", &metodo);


	if (metodo == 0)
	{
		printf("\nPor selección: \n");
		seleccion(V, largo);
	}
	else if (metodo == 1)
	{
		printf("\nPor Burbuja: \n");
		burbuja(V, largo);
	}
	else if (metodo == 2)
	{
		printf("\nPor Burbuja mejorado: \n");
		burbuja_mas(V, largo);
	}
	else
	{
		printf("\nError de metodo. El vector quedó igual: \n");

	}
	imprimir(V, largo);

	return 0;

}













