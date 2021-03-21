

/**---------------------------------------- 
Curso r1041 (2020)
Clase 3 - Estructuras de Selección
Realizar un programa (este es uno nuevo!!!!!!) que a partir de la nota muestre la nota en letras.
----------------------------------------*/

#include <stdio.h>

int largo (char * frase);

int main (int cuanto, char ** p)
{

	int dia, c_letras;

	if((cuanto >= 2) && (cuanto < 9))
	{
		printf("Ingrese el número de un día de la semana (1 al 7): ");
		scanf("%d", &dia);

//		dia++; //No ajusto porque los elementos se cuentan desde 1.

		if((dia >= 1) && (dia < 8))
		{
			c_letras = largo (*(p+dia));
			printf("Mi peor día de la semana es el %s porque me levanto de mal humor, el día se me hace relargo. Encima su nombre empieza con %c y eso me da más bronca porque es una letra que no me banco. Para colmo, el día %s tiene %d letras que es mi número de mala suerte.\n\n", *(p+dia), *(*(p+dia)), *(p+dia), c_letras);
		}
		else 
		{
			printf("No es una día válido\n");
		}
	}
	else 
	{
		printf("Error en la ejecución.\n\nEl uso del programa es %s <nombres_de_los_dias>\n", *(p+0));
	}


	return 0;
}


int largo (char * frase)
{
	int cuenta=0;

	while (*(frase+cuenta)!='\0')
	{
		cuenta++;
	}

	return cuenta;
}

