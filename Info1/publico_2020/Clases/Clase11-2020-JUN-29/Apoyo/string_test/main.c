/**
	\file    <Nombre del archivo>
	\brief   <Que contiene el archivo>
	\author  <Apellido y Nombre (mail)>
	\date    <Año.Mes.Día> 
	\version <Versión (ejemplo: 1.0.0)>
*/


//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include <string.h>

#include "funciones.h"

#define MAX_STRING 32
#define COMP 6

/**
	\fn      <Prototipo de la función>
	\brief   <Función de la función>
	\author  <Apellido y Nombre (mail)>
	\date    <Año.Mes.Día>
	\param   <Parámetro A (si no tiene no se pone)>
	\param   <Parámetro B (si no tiene no se pone)>
	\return  <Lo que retorna>
*/
int main (void) {

	char mensaje[MAX_STRING] ="Informatica I";
	char mensaje2[MAX_STRING]=" UTN-FRBA";

	printf("mensaje  = \"%s\"\n", mensaje);
	printf("mensaje2 = \"%s\"\n", mensaje2);

	// printf("   strlen(\"%s\") = %lu\n", mensaje,    strlen(mensaje));
	// printf("mi_strlen(\"%s\") = %lu\n\n", mensaje, mi_strlen(mensaje));
	

	// mi_strcpy(mensaje2,mensaje);
	// printf("mensaje2 = \"%s\"\n", mensaje2);

	// printf("   strcmp(\"%s\",\"%s\") = %i\n",mensaje,mensaje2,   strcmp(mensaje,mensaje2));
	// printf("mi_strcmp(\"%s\",\"%s\") = %i\n",mensaje,mensaje2,mi_strcmp(mensaje,mensaje2));


	// printf("   strncmp(\"%s\",\"%s\",%i) = %i\n",mensaje,mensaje2,COMP,    strncmp(mensaje,mensaje2,COMP));
	// printf("mi_strncmp(\"%s\",\"%s\",%i) = %i\n",mensaje,mensaje2,COMP, mi_strncmp(mensaje,mensaje2,COMP));

	// printf("   strcat(\"%s\",\"%s\") = ",mensaje, mensaje2);
	// strcat(mensaje,mensaje2);
	// printf("\"%s\"\n",mensaje);

	printf("mi_strcat(\"%s\",\"%s\") = ",mensaje, mensaje2);
	mi_strcat(mensaje,mensaje2);
	printf("\"%s\"\n",mensaje);


	// if (!strcmp(mensaje,mensaje2)) {
	// 	printf("Son iguales\n");
	// }
	// else {
	// 	printf("Son distintas\n");
	// }

	return 0; 

}

