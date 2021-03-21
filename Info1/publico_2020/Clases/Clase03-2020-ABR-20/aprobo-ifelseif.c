
/**---------------------------------------- 
Curso r1023 (2020)
Clase 3 - Estructuras de Selección
Nueva versión. Modificar el programa anterior para que informe si el examen está aprobado, si tiene nota de promoción
 o si está desaprobado.
----------------------------------------*/

#include <stdio.h>

int main (void)
{

	int nota = 8;

	if (nota >= 8)
	{
		printf("******PROMOCIONASTE******\n\n");
	}
	else if (nota >= 6)
	{
		printf("Aprobaste!!!!!!!!\n\n");
	}
	else
	{
		printf("No Aprobaste :-( :-( :-(\n\n");
	}

	printf("Chau....");

	return 0;
}
