
#include "muestrobinfunc.h"

void convierto (int valor, char * bin)
{
	int i = 0;

	while (valor >= BASE)
	{
		//guardar el resto de cada división
		bin[i] = valor % BASE;
		i++;
		valor = valor/BASE;
	}

	//guardar valor como el MSB 
	bin[i] = valor;
	bin[i+1] = BASE;

	return;
}
