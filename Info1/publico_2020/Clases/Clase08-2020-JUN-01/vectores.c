

#include <stdio.h>

#define TAM 15


int main (void)
{

	char basurita = 'W';
	char vec[TAM];

	char basura = 'Z';
	char vec2[];
	int i, cant = 8;
	char vec3[cant];


	printf("Decime cuantos: ");
	scanf("%d", cant);
	char vec5[cant];




	printf("Antes: Basura vale: %c\n", basura);
	printf("Antes: Basurita vale: %c\n", basurita);

	for(i=0; i<TAM; i++)
	{
		vec[i] = 'A';
	}

	printf("Despues: Basura vale: %c\n", basura);
	printf("Despues: Basurita vale: %c\n", basurita);

	return 0;
}

