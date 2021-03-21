#include "funvec.h"


void carga (runner * listado)
//void carga (struct corredores listado)
{
	int i;

	for (i=0; i<CANT; i++)
	{
		printf("Ingrese el id del corredor: ");
		scanf("%d", &listado[i].id);
		printf("Ingrese el tiempo utilizado (min): ");
		scanf("%d", &listado[i].tiempo);
		printf("Ingrese la distancia recorrida (kmts): ");
		scanf("%f", &listado[i].distancia);
	}

	return;
}


void calculo (runner * listado, velocidad * resultado)
{

	int i;

	for (i=0; i<CANT; i++)
	{
		resultado[i].id = listado[i].id;
//		velocidad = distancia/(tiempo/60);
		resultado[i].veloc = listado[i].distancia/(listado[i].tiempo/60.0);
	}

	return;
}

void orden (velocidad * resultado)
{
	return;
}


void impresion(velocidad * resultado)
{
	int i;

	printf("El resultado de las pruebas fue:\n\n");

	for(i=0; i<CANT; i++)
	{
		printf("El corredor %d tuvo una velocidad de %f\n",resultado[i].id, resultado[i].veloc);
	}
	return;
}
