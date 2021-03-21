#include <stdio.h>

#define CANT 10

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


void carga (runner * listado);
void calculo (runner * listado, velocidad * resultado);
void orden (velocidad * resultado);
void impresion(velocidad * resultado);


