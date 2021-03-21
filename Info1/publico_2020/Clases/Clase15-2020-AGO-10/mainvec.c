#include "funvec.h"

int main (void)
{

	runner listado[CANT];
	velocidad resultado[CANT];


	carga (listado);

	calculo (listado, resultado);

	orden (resultado);

	impresion(resultado);

	return 0;

}


