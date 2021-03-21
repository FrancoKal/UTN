
/**---------------------------------------- 
Curso r1041 (2020)
Clase 3 - Estructuras de Selección
Realizar un programa (este es uno nuevo!!!!!!) que a partir de la nota muestre la nota en letras.
----------------------------------------*/

#include <stdio.h>

int main (void)
{

	int dia = 4;

	printf ("El día de la semana es: ");

	switch (dia)
	{
		case 1: printf("Domingo\n");
			break;
		case 2: printf("Lunes\n");
			break;
		case 3: printf("Martes\n");
			break;
		case 4: printf("Miércoles\n");
			break;
		case 5: printf("Jueves\n");
			break;
		case 6: printf("Viernes\n");
			break;
		case 7: printf("Sabado\n");
			break;
		default: printf("No es una día válido\n");
			// break; No es necesario
	}

	return 0;
}
