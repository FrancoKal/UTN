

/**---------------------------------------- 
Curso r1041 (2020)
Clase 3 - Estructuras de Selección
Realizar un programa (este es uno nuevo!!!!!!) que a partir de la nota muestre la nota en letras.
----------------------------------------*/

#include <stdio.h>

int largo (char * frase);

int main (int cuanto)
{

	char d1 [] = "Domingo";
	char d2 [] = "Lunes";
	char d3 [] = "Martes";
	char d4 [] = "Miercoles";
	char d5 [] = "Jueves";
	char d6 [] = "Viernes";
	char d7 [] = "Sabado";
	char * p [] = {d1, d2, d3, d4, d5, d6, d7};

	int dia, c_letras;

	printf("Ingrese el número de un día de la semana (1 al 7): ");
	scanf("%d", &dia);

//	dia--; //ajusto porque los elementos se cuentan desde 0.

	printf("Ingresaste: %d parametros \n\n", cuanto);

	if((dia > 0) && (dia < 8))
	{
		c_letras = largo (p[dia]);
		printf("Mi peor día de la semana es el %s porque me levanto de mal humor, el día se me hace relargo. Encima su nombre empieza con %c y eso me da más bronca porque es una letra que no me banco. Para colmo, el día %s tiene %d letras que es mi número de mala suerte.\n\n", p[dia], p[dia][0], p[dia], c_letras);
	}
	else 
	{
		printf("No es una día válido\n");
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

