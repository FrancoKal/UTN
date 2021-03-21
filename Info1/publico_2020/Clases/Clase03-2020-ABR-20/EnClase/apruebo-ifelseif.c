/**---------------------------------------- 
Curso r1041 (2020)
Clase 3 - Estructuras de Selección
Nueva versión. Modificar el programa anterior para que informe si el examen está aprobado, si tiene nota de promoción
 o si está desaprobado.
----------------------------------------*/

#include <stdio.h>

int main (void)
{

	int nota;

	nota = 5;

	if (nota >= 8)
	{
		printf("PROMOCIONASTE!!!!!!! Sos un capo.\n");
	}
	else if (nota >=6)
	{
		printf("Aprobaste por suerte\n");
	}
	else
	{
		printf("Estas desaproba2 guey :-( :-(\n");
	}

	return 0;
}
