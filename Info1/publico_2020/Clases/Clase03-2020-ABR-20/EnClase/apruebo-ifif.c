/**---------------------------------------- 
Curso r1041 (2020)
Clase 3 - Estructuras de Selección
Modificar el programa anterior, para que informe tanto si el examen está aprobado como si no.
----------------------------------------*/

#include <stdio.h>

int main (void)
{

	int nota;

	nota = 5;

	if (nota >= 6)
	{
		printf("Estas aprobado compadre.\n");
	}

	if (nota < 6)
	{
		printf("Estas desaproba2 guey :-( :-(\n");
	}

	return 0;
}
