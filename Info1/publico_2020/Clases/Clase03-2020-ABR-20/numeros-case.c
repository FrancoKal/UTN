
/**---------------------------------------- 
Yo te digo si aprobaste 
----------------------------------------*/

#include <stdio.h>

int main (void)
{

	int nota = 8;

	printf ("La nota en letras es: ");

	switch (nota)
	{
		case 0: printf("Cero\n");
			break;
		case 1: printf("Uno\n");
			break;
		case 2: printf("Dos\n");
			break;
		case 3: printf("Tres\n");
			break;
		case 4: printf("Cuatro\n");
			break;
		case 5: printf("Cinco\n");
			break;
		case 6: printf("Seis\n");
			break;
		case 7: printf("Siete\n");
			break;
		case 8: printf("Ocho\n");
			break;
		case 9: printf("Ocho\n");
			break;
		case 10: printf("Ocho\n");
			break;
		default: printf("No es una nota válida\n");
			// break; No es necesario
	}

	return 0;
}
