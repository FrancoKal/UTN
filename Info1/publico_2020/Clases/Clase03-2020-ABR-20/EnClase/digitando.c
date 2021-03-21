#include <stdio.h>

int main (void)
{

	int numerazo, contador = 0, b = 1 ;

	printf("Ingresa el numero: ");
	scanf("%d", &numerazo);

//	tempo = numerazo;

	while (numerazo / b > 0)
	{					//   1    2  3   4  5  
						//45678 4567 456 45 4 0y se va
//		numerazo = numerazo / b;  	//4567	456  45  4  0
		b = b * 10;
		contador = contador + 1;
	}

	printf ("El numero %d  que ingresaste tiene %d digitos\n", numerazo, contador);

	return 0;
}

/*
123  12
12   1
*/


