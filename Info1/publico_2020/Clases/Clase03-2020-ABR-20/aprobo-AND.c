
/**---------------------------------------- 
Curso r1023 (2020)
Clase 3 - Estructuras de Selección
Nueva versión. En esta oportunidad el programa además deberá considerar que hayan sido aprobados los trabajos prácticos 
para informar si el examen está aprobado, si tiene nota de promoción o si está desaprobado.
----------------------------------------*/

#include <stdio.h>

int main (void)
{

	int nota = 8;
	int TP = 10;


	if ((nota >= 8) && (TP >= 8))
	{
		printf("******PROMOCIONASTE******\n\n");
	}
	else if ((nota >= 6) && (TP >= 8))
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
