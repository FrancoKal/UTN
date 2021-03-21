/**
	\file    funciones.c
	\brief   Contiene las funciones de prueba con cadenas de caracteres
	\author  Fernando Aló fernandoalo@frba.utn.edu.ar
	\date    2020.06.29
	\version 1.0.0
*/



//--------------
//-- Includes --
//--------------
#include "funciones.h"

/**
	\fn     <Prototipo de la función>
	\brief  <Función de la función>
	\author Fernando Aló fernandoalo@frba.utn.edu.ar
	\date   <Año.Mes.Día> 
	\param  <Parámetro A>
	\param  <Parámetro B>
	\return <Lo que retorna>
*/
size_t mi_strlen(const char *s) {
	size_t i;

	for (i=0;s[i];i++);

	return i;
}

/**
	\fn     char * mi_strcpy(char *dest, const char *src)
	\brief  Copia una cadena en tra
	\author <Apellido y Nombre (mail)>
	\date   <Año.Mes.Día> 
	\param  *dest esta es la cadena destino
	\param  *src esta es la cadena origen
	\return char *
*/
char * mi_strcpy(char *dest, const char *src){
	int i;

	for(i=0;src[i]!='\0';i++)
		dest[i]=src[i];

	dest[i]='\0';

	return dest;
}

/**
	\fn     <Prototipo de la función>
	\brief  <Función de la función>
	\author <Apellido y Nombre (mail)>
	\date   <Año.Mes.Día> 
	\param  <Parámetro A>
	\param  <Parámetro B>
	\return <Lo que retorna>
*/
int mi_strcmp(const char *s1, const char *s2){
	int i;

	while(!(s1[i]-s2[i]) && s1[i]!='\0' && s2[i]!='\0')
		i++;

	return s1[i]-s2[i];

}

/**
	\fn     <Prototipo de la función>
	\brief  <Función de la función>
	\author <Apellido y Nombre (mail)>
	\date   <Año.Mes.Día> 
	\param  <Parámetro A>
	\param  <Parámetro B>
	\return <Lo que retorna>
*/
int mi_strncmp(const char *s1, const char *s2, size_t n) {
	int i;

	while(!(s1[i]-s2[i]) && s1[i]!='\0' && s2[i]!='\0' && i<n)
		i++;

	return s1[i]-s2[i];

}

/**
	\fn     <Prototipo de la función>
	\brief  <Función de la función>
	\author <Apellido y Nombre (mail)>
	\date   <Año.Mes.Día> 
	\param  <Parámetro A>
	\param  <Parámetro B>
	\return <Lo que retorna>
*/
char * mi_strcat(char *dest, const char *src){
	int i,len_dest;

	len_dest = mi_strlen(dest);

	for (i=0;src[i]!='\0';i++) {
		dest[i+len_dest] = src[i];
	}

	dest[i+len_dest] = '\0';

	//mi_strcpy(dest+mi_strlen(dest),src);
	return dest;
}
