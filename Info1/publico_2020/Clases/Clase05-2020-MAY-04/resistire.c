/*
Realizar un programa para el departamento de control de calidad de la empresa Resistire S.A.
El mismo deberá solicitar el ingreso de una resistencia patrón.
A continuación comenzará a solicitar repetidamente distintos valores de resistencias.
La carga finalizará con el ingreso del valor cero.
Una vez finalizada la carga, presentará por pantalla la siguiente información:
Cantidad de resistencias que superan el 10% del valor patrón (es decir que la diferencia con el valor patrón es superior 
al 10% tanto por exceso como por defecto)
Cantidad de resistencias que están dentro del 5% del valor patrón (es decir que la diferencia con el valor patrón es menor 
al 5% tanto por exceso como por defecto)
Valor de la resistencia promedio y su diferencia porcentual respecto de la resistencia patrón.
*/


#include <stdio.h>


int main (void)
{

	int patron;
	int resistencia;
	int acumulado = 0;
	int contador = 0;
	int diego = 0;
	int quinta = 0;
	float promedio;

	printf("\n\n\t**************************************************************\n");
	printf("\t*                                                            *\n");
	printf("\t*                     RESISTIRE SA                           *\n");
	printf("\t*                                                            *\n");
	printf("\t**************************************************************\n\n\n");
	printf("\t------------------ Departamento de calidad -------------------\n\n\n");
	printf("Ingrese el valor de la resistencia patron (en ohms): ");
	scanf("%d", &patron);

	do
	{
		printf("Ingrese el valor la resistencia (en ohms): ");
		scanf("%d", &resistencia);

		if(resistencia != 0)
		{
			contador++;
			acumulado = acumulado + resistencia;

			if((resistencia > patron*0.95)&&(resistencia<patron*1.05)) quinta++;
			if((resistencia > patron*1.10)||(resistencia<patron*0.9)) diego++;
		}
	}
	while (resistencia!=0);

	promedio = (float) acumulado/contador;

	printf("\n\n\t---------------------- Reporte -----------------------------\n\n\n");
	printf("Para la resistencia patron %d y la carga de %d resistencias nos encontramos que:\n", patron, contador);
	printf("Resistencias mayores al 10 por ciento: %d\n", diego);
	printf("Resistencias menores al 5 por ciento:  %d\n", quinta);
	printf("Resistencia promedio %f tiene una variación de %f por ciento\n", promedio, 100-(promedio/patron*100));
	printf("\n\n\t------------------ Fin del reporte -------------------------\n\n\n");


	return 0;
}
