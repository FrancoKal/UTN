#include <stdio.h>



int main (void)
{

	int a = 1;
	int b = 2;

	if (a & b) printf("verdadero\n");
	else printf("Falso\n");

	if (a && b) printf("verdadero\n");
	else printf("Falso\n");

	return 0;
}

