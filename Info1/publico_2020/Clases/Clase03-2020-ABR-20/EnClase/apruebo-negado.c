/**---------------------------------------- 
Curso r1041 (2020)
Clase 3 - Estructuras de Selección
Modificar el programa anterior, para que informe tanto si el examen está aprobado como si no.
Probando el uso de la negación.
----------------------------------------*/

#include <stdio.h>

int main (void)
{

	int nota;

	nota = 9;

	if (!(nota < 6))
	{
		printf("Aprobaste por suerte\n");
	}
	else
	{
		printf("Estas desaproba2 guey :-( :-(\n");
	}

	return 0;
}
