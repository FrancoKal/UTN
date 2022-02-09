#include "funciones.h"

int main (void)
{
	char **strings = NULL;
	int min, max, rango;

	if (pedirRango(&min, &max) != ERROR)
	{
		rango = CrearVector(min, max, &strings);
		imprimir(strings, rango);
		liberar(&strings, rango);
	}

	return 0;
}
