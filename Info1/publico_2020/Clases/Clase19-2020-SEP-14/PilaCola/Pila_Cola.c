/**
Apilar/QuitarB			Encolar/QuitarA
Camila					Facundo
Juan Pablo				Lucas
Joaquin					Franco
Romina					Mariano
*/

/**
	\file    Pila_Cola.c
	\brief   Archivo principal para la ejecución del menú y llamar a las funciones de apilar, encolar, quitarA y quitarB
	\author  Hecho en clase
	\date    2020.09.14
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include <stdlib.h>

//-----------------
//---- Defines ----
//-----------------
enum estado {OK, ERROR};

//-----------------
//-- Prototipos ---
//-----------------
int apilar (int ** vec, int * cant, int dato);
int encolar (int ** vec, int * cant, int dato);
int quitarA (int ** vec, int * cant, int * dato);
int quitarB (int ** vec, int * cant, int * dato);
void mostrar (int * vec, int cant);

//-----------------------------------------------------------------------------------------

/**
	\fn      main
	\brief   funcion principal
	\author  Hecho en clase
	\date    2020.09.14
	\return  0: si todo salió bien
		 1: si se produjo algún error
*/

int main (void)
{

	int cant = 0, delta;
	int i;
	int * vec = NULL;
	char opcion;
	int dato;
	int resu;
	int salida = OK;

	do
	{
		printf("Menu:\n\tAgregar elementos en la pila (p).\n");
		printf("\tAgregar elementos en la cola (c).\n");
		printf("\tQuitar elementos función A (q).\n");
		printf("\tQuitar elementos función B (r).\n");
		printf("\tSalir. (s).\n\t----> ");
		scanf(" %c", &opcion);

		if  ((opcion == 'p') || (opcion == 'c'))
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

			if (delta > cant) 
			{
				delta = cant;
			}

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
	while (opcion != 's');

	if (vec) free(vec);

	return 0;
}

//-------------------------------------------------------------------------------------------------------------

/**
	\fn      void mostrar (int * vec, int cant)
	\brief   Muestra el listado de los valores cargados.
	\author  Hecho en clase
	\date    2020.09.14
	\param   vec: dirección del vector donde se encuentran los datos
	\param   cant: cantidad de datos que se encuentran en el vector
*/

void mostrar (int * vec, int cant)
{
	int i;

	printf("Estado del vector:\n");
	for (i = 0; i < cant; i++)
	{
		printf("\tVec[%d]: %d\n", i, *(vec+i));
	}
	return;
}

//-------------------------------------------------------------------------------------------------------------

/**
	\fn      int encolar (int ** vec, int * cant, int dato)
	\brief   Agrega el dato recibido al vector. Lo hace como COLA (Carga al final)
	\author  Hecho en clase
	\date    2020.09.14
	\param   vec: dirección del vector donde se encuentran los datos
	\param   cant: cantidad de datos que se encuentran en el vector
	\param   dato: dato a agregar en el vector
	\return  OK si se agregó
		 ERROR si no se agregó
*/

int encolar (int ** vec, int * cant, int dato)
{

	int * aux = NULL;
	int salida = ERROR;

	if ((*cant) == 0)
	{
	    aux = (int *) malloc (sizeof(int) * ((*cant)+1));
//	    aux = malloc (sizeof(int));
	}
	else
	{
	    aux = (int *) realloc(*vec,sizeof(int) *(*cant + 1));
  	}

  	if (aux != NULL)
	{
		*vec = aux;
		salida = OK;
		(*vec)[*cant] = dato;
	        *cant = *cant + 1;
  	}

  	return salida;

  /*    int i;
                         0
        *vec = (*cant == 0)? (int *) malloc (sizeof(int)) : (int *) realloc (*vec, sizeof(int) * (*cant + 1)); 

        if (*vec != NULL)
        {
                (*vec)[*cant] = dato;
                printf("%i\n", (*vec)[*cant]);
        }

}*/ //Lo mio

}

//-------------------------------------------------------------------------------------------------------------

/**
	\fn      int apilar (int ** vec, int * cant, int dato)
	\brief   Agrega el dato recibido al vector. Lo hace como PILA (Lo carga al principio)
	\author  Hecho en clase
	\date    2020.09.14
	\param   vec: dirección del vector donde se encuentran los datos
	\param   cant: cantidad de datos que se encuentran en el vector
	\param   dato: dato a agregar en el vector
	\return  OK si se agregó
		 ERROR si no se agregó
*/

int apilar (int ** vec, int * cant, int dato)
{

	int i, estado;
	int * aux =NULL;

  	if (*cant == 0)
  	{
		aux = (int *) malloc (sizeof(int));
  	}
 	else
  	{
		aux = (int *) realloc (*vec, (sizeof(int)*(*cant + 1)));
  	}

  	if (aux == NULL)
  	{
    		estado = ERROR;
  	}
  	else
 	{
    		*vec = aux;

	    	for (i = *cant; i > 0; i--)
    		{
      			(*vec)[i] = (*vec)[i-1];
// 10 20 30
// 0  1  2
// *cant --> 3
// i  (*vec)[3]
// 3	
    		}

    		(*vec)[0] = dato;
    		(*cant)++;
    		estado = OK;
  	}

  	return estado;
}

//-------------------------------------------------------------------------------------------------------------

/**
	\fn      int quitarB (int ** vec, int * cant, int * dato)
	\brief   Quita el ultimo dato del vector y devuelve el dato que sacó en la variable dato
	\author  Hecho en clase
	\date    2020.09.14
	\param   vec: dirección del vector donde se encuentran los datos
	\param   cant: cantidad de datos que se encuentran en el vector
	\param   dato: dato a agregar en el vector
	\return  OK si se quitó
		 ERROR si no se quitó
*/

int quitarB (int ** vec, int * cant, int * dato)
{
	int * aux = NULL;
  	int estado = OK;

	if (*cant==0)
	{
		estado = ERROR;
	}
	else
	{
	  	*dato = (*vec)[*cant];
//	  	*dato = (*vec)[*cant]; Busca la direccion del contenido de vec y luego desplaza *cant.
//	  	*dato = *vec[*cant]; Busca (vec+*cant) y luego va a buscar el contenido en esa direccion.
	  	(*cant)--;

		if (*cant == 0)
		{
	      		free(*vec);
			*vec = NULL;
    		}
  		else
    		{
      			aux = (int*)realloc(*vec, sizeof(int)*(*cant));
	    		if (aux == NULL)
        		{
	          		estado = ERROR;
        		}
	      		else
        		{
	          		*vec = aux;
        		}
		}
	}
  	return estado;
}

//-------------------------------------------------------------------------------------------------------------

/**
	\fn      int quitarA (int ** vec, int * cant, int * dato)
	\brief   Quita el primer dato del vector y devuelve el dato que sacó en la variable dato
	\author  Hecho en clase
	\date    2020.09.14
	\param   vec: dirección del vector donde se encuentran los datos
	\param   cant: cantidad de datos que se encuentran en el vector
	\param   dato: dato a agregar en el vector
	\return  OK si se quitó
		 ERROR si no se quitó
*/

int quitarA (int ** vec, int * cant, int * dato)
{




	return OK;
}

//-------------------------------------------------------------------------------------------------------------
