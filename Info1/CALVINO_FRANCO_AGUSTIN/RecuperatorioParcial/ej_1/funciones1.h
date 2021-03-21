/**
	\file    funciones1.h
	\brief   Prototipos de las funciones que utiliza el main1.c
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.10.26
	\version 1.0.0
*/


#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <stdio.h>

#define CANT_PALABRAS 5
enum estado {SIN_CAMBIO = -1, CONTINUO = -2};

//----------------
//-- Prototipos --
//----------------
void ordenar (char **palabras);
//int cambio (char **string1, char **string2);

#endif


