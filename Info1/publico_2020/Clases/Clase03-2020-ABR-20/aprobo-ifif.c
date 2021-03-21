
/**---------------------------------------- 
Curso r1023 (2020)
Clase 3 - Estructuras de Selección
Modificar el programa anterior, para que informe tanto si el examen está aprobado como si no.
----------------------------------------*/

#include <stdio.h>

int main (void)
{

	int nota = 8;

	if (nota >= 6)
	{
		printf("Aprobaste!!!!!!!!\n\n");
	}

	if (nota < 6)
	{
		printf("No Aprobaste :-( :-( :-(\n\n");
	}

	printf("Chau....");

	return 0;
}
