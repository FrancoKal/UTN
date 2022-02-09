/**
	\fn      main
	\brief   funcion principal
	\author  Hecho en clase
	\date    2020.09.11
	\return  0: si todo salió bien
		 1: si se produjo algún error
*/

enum opciones {PILA, COLA, QUITAR_A, QUITAR_B, SALIR, NADA};

#include <stdio.h>
#include "funciones.h"

int * agregar (int *, int *, int);
int * quitar (int *, int *, int *);

int main (void)
{

	int cant = 0, delta;
	int i = 0;
	int * vec = NULL;
	char opcion, *mensaje[] = {"agregar", "quitar"}, *comparo = "pcqrs";
	int dato;
	int resu = OK;
	int (*agregar[]) (int **, int *, int) = {apilar, encolar};
	int (*quitar[]) (int **, int *, int *) = {quitarA, quitarB};

	do
	{
		//i = 0;
		printf("Menu:\n\tAgregar elementos en la pila (p).\n");
		printf("\tAgregar elementos en la cola (c).\n");
		printf("\tQuitar elementos función A (q).\n");
		printf("\tQuitar elementos función B (r).\n");
		printf("\tSalir (s).\n\t---->");
		scanf("%c", &opcion);
		
		for (i = 0; (comparo[i] != opcion) && (i < NADA); i++); //Comparo la opcion elegida con un vector de las letras de cada opcion
		
		//getchar();
		
		if (i < SALIR)
		{
			printf("Ingrese la cantidad de numeros a %s: ", mensaje[i/2 /*(1)*/]); //(1) Si i es 0 o 1 (agregar), el cociente dara 0 (como es int, el resto se descarta). Si es 2 o 3 													(quitar), el cociente dara 1
			scanf("%i", &delta);
			
			while (delta != 0 && resu == OK)
			{
				if (i < QUITAR_A)
				{
					printf("Que numero desea ingresar: ");
					scanf("%i", &dato);
					resu = (agregar[i])(&vec, &cant, dato);
				}
				else
				{
					resu = (quitar[i - 2])(&vec, &cant, &dato);
						
					if (resu == OK)
					{
						printf("El numero %i fue quitado del vector\n", dato);
					}
				}
				
				if (resu == ERROR) /*opcion = 's'*/i = SALIR;
				
				delta--;
			}
			
			if (vec != NULL) mostrar(vec, cant);
		}
		else if (i == NADA)
		{
			printf("Opción no valida. Reintente.\n");
		}
	}
	while (/*opcion != 's'*/i != SALIR);

	/*	if  ((opcion == 'p') || (opcion == 'c'))
		{
			printf("Ingrese la cantidad de numeros a agregar: ");
			scanf("%d", &delta);

			i = 0;
			while ((i < delta) && (salida == OK))
			{
				printf("Que numero desea ingresar: ");
				scanf("%d", &dato);

				if (opcion == 'p')
				{
					resu = apilar (&vec, &cant, dato);
				}
				else
				{
					resu = encolar (&vec, &cant, dato);
				}

				if (resu == ERROR)
				{
					salida = ERROR;
					opcion = 's';
				}
				i++;
			}
			mostrar(vec, cant);
		}
		else if  ((opcion == 'q') || (opcion == 'r'))
		{
			printf("Ingrese la cantidad de numeros a quitar: ");
			scanf("%d", &delta);

			i = 0;
			while ((i < delta) && (salida != ERROR))
			{
				if (opcion == 'q')
				{
					resu = quitarA (&vec, &cant, &dato);
				}
				else
				{
					resu = quitarB (&vec, &cant, &dato);
				}

				if (resu == ERROR)
				{
					salida = ERROR;
					opcion = 's';
				}
				else
				{
					printf("El numero %d fue quitado del vector\n", dato);
				}
				i++;
			}
			mostrar(vec, cant);
		}
		else if (opcion != 's')
		{
			printf("Opción no valida. Reintente.\n");
		}
	}
	while (opcion != 's');*/

	if (vec != NULL) free(vec);

	return 0;
}
