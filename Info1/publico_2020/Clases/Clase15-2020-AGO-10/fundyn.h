#include <stdio.h>

struct corredores
{
	int id;
	float distancia;
	int tiempo;
};

typedef struct corredores runner;

struct performance
{
	int id;
	float veloc;
};

typedef struct performance velocidad;


int carga (runner ** listado);
void calculo (runner * listado, velocidad ** resultado, int cant);
void orden (velocidad * resultado, int cant);
void impresion(velocidad * resultado, int cant);


