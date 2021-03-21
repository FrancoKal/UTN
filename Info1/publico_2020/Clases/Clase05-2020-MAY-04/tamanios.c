#include <stdio.h>
#define BITS 10
#define VUELTAS 8

int main (void)
{

	const int bits = 10;
	int bitsi = 32;

	

	printf("El tamaño del char es: %d bits (%ld bytes)\n", sizeof(char)*BITS, sizeof(char));
	printf("El tamaño del int  es: %ld bits (%ld bytes)\n", sizeof(int)*BITS, sizeof(int));
	printf("El tamaño del float es: %ld bits (%ld bytes)\n", sizeof(float)*bits, sizeof(float));
	printf("El tamaño del double es: %ld bits (%ld bytes)\n", sizeof(double)*bits, sizeof(double));
	printf("El tamaño del unsigned int es: %ld bits (%ld bytes)\n", sizeof(unsigned int)*bits, sizeof(unsigned int));
	printf("El tamaño del short es: %ld bits (%ld bytes)\n", sizeof(short)*bits, sizeof(short));
	printf("El tamaño del long es: %ld bits (%ld bytes)\n", sizeof(long)*bits, sizeof(long));
	printf("El tamaño del long double es: %ld bits (%ld bytes)\n", sizeof(long double)*bits, sizeof(long double));
	printf("El tamaño del unsigned long es: %ld bits (%ld bytes)\n", sizeof(unsigned long)*bits, sizeof(unsigned long));

	bits = 64;

	return 0;

}
