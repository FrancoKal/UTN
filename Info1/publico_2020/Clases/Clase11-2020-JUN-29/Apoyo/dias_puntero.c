

/**---------------------------------------- 
Curso r1041 (2020)
Clase 3 - Estructuras de Selección
Realizar un programa (este es uno nuevo!!!!!!) que a partir de la nota muestre la nota en letras.
----------------------------------------*/

#include <stdio.h>

int main (void)
{

	char d1 [] = "Domingo";
	char d2 [] = "Lunes";
	char d3 [] = "Martes";
	char d4 [] = "Miercoles";
	char d5 [] = "Jueves";
	char d6 [] = "Viernes";
	char d7 [] = "Sabado";

	char * p = NULL;
	int dia;

	printf("Ingrese el número de un día de la semana (1 al 7): ");
	scanf("%d", &dia);

	switch (dia)
	{
		case 1:
			p = d1;
			break;
		case 2:
			p = d2;
			break;
		case 3:
			p = d3;
			break;
		case 4:
			p = d4;
			break;
		case 5:
			p = d5;
			break;
		case 6:
			p = d6;
			break;
		case 7:
			p = d7;
	}

	if (p!=NULL) 
	{
		printf ("El día %d de la semana es: %s\n", dia, p);
	}
	else
	{
		printf("No es una día válido\n");
	}


	return 0;
}


