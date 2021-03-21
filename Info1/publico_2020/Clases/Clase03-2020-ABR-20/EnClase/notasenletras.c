#include <stdio.h>


int main (void)
{
	int nota;

	printf("Pasame la nota que te digo como se escribe: ");
	scanf("%d", &nota);

	switch (nota)
	{
		case 0:
			printf("La nota %d es cero.\n", nota); 
			break; 
		case 1:
			printf("La nota %d es uno.\n", nota);
			break;
		case 2:
			printf("La nota %d es dos.\n", nota);
			break;
		case 3:
			printf("La nota %d es tres.\n", nota);
			break;
		case 4:
			printf("La nota %d es cuatro.\n", nota);
			break;
		case 5:
			printf("La nota %d es cinco.\n", nota);
			break;
		case 6:
			printf("La nota %d es seis.\n", nota);
			break;
		case 7:
			printf("La nota %d es siete.\n", nota);
			break;
		case 8:
			printf("La nota %d es ocho.\n", nota);
			break;
		case 9:
			printf("La nota %d es nueve.\n", nota);
			break;
		case 10:
			printf("La nota %d es diez.\n", nota);
			break;
		default:
			printf("No pusiste una nota valida.\n");

	}

	return 0;
}
