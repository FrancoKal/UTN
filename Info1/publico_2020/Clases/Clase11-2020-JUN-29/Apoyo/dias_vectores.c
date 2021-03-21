

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

	int dia;

	printf("Ingrese el número de un día de la semana (1 al 7): ");
	scanf("%d", &dia);

	printf ("El día %d de la semana es: ", dia);

	switch (dia)
	{
		case 1:
			printf("%s\n", d1);
			break;
		case 2:
			printf("%s\n", d2);
			break;
		case 3:
			printf("%s\n", d3);
			break;
		case 4:
			printf("%s\n", d4);
			break;
		case 5:
			printf("%s\n", d5);
			break;
		case 6:
			printf("%s\n", d6);
			break;
		case 7:
			printf("%s\n", d7);
			break;
		default: printf("No es una día válido\n");
			// break; No es necesario
	}

	return 0;
}



