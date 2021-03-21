#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define LARGO 50
#define CANT_TAREAS 3
#define HIJO 0
enum errores {ERROR_MEMORIA = -1};
enum pipe_fd {READ = 0, WRITE = 1};
enum estado {CONTINUO = -1, FINALIZO = -2};
enum divisibilidad {PRIMO = 0, COMPUESTO = -1};

struct numero
{
	int n[2];
	float f;
};

typedef struct numero numeros;

struct proceso //Creo una struct con el nombre del proceso y su pipefd
{
	char name[20];
	int pipefd[2];
};

typedef struct proceso proc;

int leer_numeros (FILE *archivo, numeros **vector);
void may_a_men (numeros *vector, int cant, FILE *archivo);
void primos (numeros *vector, int cant, FILE *archivo);
