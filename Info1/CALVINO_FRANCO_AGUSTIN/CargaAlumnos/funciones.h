#include <stdio.h>

#define LARGO_NOM 50
#define CANT_MAX 100
#define SALIDA 1

enum errores {SIN_MEMORIA = -1};

struct fechas
{
	int dia, mes, anio;
};

typedef struct fechas fecha;

struct alumnos
{
	int id;
	char *nombre;
	fecha fe;
	int edad;
};

typedef struct alumnos alumno;

int cargar (alumno ***lista);
alumno ** ordenar (alumno **lista, int cant);
void mostrar (alumno **ordenado, int cant);
void liberar_lista (alumno ***lista, int cant);
