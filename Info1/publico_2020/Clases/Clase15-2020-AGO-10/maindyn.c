#include "fundyn.h"

int main (void)
{

	runner * listado = NULL;
	velocidad * resultado = NULL;
	int cant;

	cant = carga (&listado);

	calculo (listado, &resultado, cant);

	orden (resultado, cant);

	impresion(resultado, cant);

	return 0;

}


