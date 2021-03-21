#include <stdio.h>

int main (void)
{

	char c;

	c = 'A';

	printf("Mostrame el ascii de lo que tengo en c: %c\n\n-----------------\n",c);
	printf("Naaaa, vieja, quiero el número: %d\n\n--------------------\n",c);
	printf("Y está guardada en la posición: %p\n\n--------------------",&c);
	printf("Y está guardada en la posición: %lx\n\n-----------",(unsigned long) &c);

	return 0;
}
