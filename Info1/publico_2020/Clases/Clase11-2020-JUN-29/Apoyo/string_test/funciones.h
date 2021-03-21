/**
	\file    <Nombre del archivo>
	\brief   <Que contiene el archivo>
	\author  <Apellido y Nombre (mail)>
	\date    <Año.Mes.Día> 
	\version <Versión (ejemplo: 1.0.0)>
*/



#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>

//----------------
//-- Prototipos --
//----------------

size_t mi_strlen(const char *s);
char * mi_strcpy(char *dest, const char *src);
int mi_strcmp(const char *s1, const char *s2);
int mi_strncmp(const char *s1, const char *s2, size_t n);
char * mi_strcat(char *dest, const char *src);


#endif


