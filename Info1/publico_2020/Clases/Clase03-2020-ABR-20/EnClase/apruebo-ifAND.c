/**---------------------------------------- 
Curso r1041 (2020)
Clase 3 - Estructuras de Selección
Nueva versión. En esta oportunidad el programa además deberá considerar que hayan sido aprobados los trabajos prácticos 
para informar si el examen está aprobado, si tiene nota de promoción o si está desaprobado.
----------------------------------------*/

#include <stdio.h>

int main (void)
{

	int nota;
	int tepes;

	nota = 9;
	tepes = 5;

	if ((nota >= 8) && (tepes >=8))
	{
		printf("PROMOCIONASTE!!!!!!! Sos un capo.\n");
	}
	else if ((nota >=6) && (tepes >= 8))
	{
		printf("Aprobaste por suerte\n");
	}
	else
	{
		printf("Estas desaproba2 guey :-( :-(\n");
	}

	return 0;
}
