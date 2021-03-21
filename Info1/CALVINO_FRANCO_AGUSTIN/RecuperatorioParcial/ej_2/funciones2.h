/**
	\file    funciones2.h
	\brief   Prototipos de las funciones que utiliza el main2.c
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.10.26
	\version 1.0.0
*/


#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>

#define MAX 10000
enum estado {FINALIZO = 0, ERROR = -1};

//----------------
//-- Prototipos --
//----------------
int crear_vec (int *vector1, int **vector2, int cant);
int * pedir_vec (int *v, int cant1, int *cant2);
void liberar_memoria(int **v);

#endif


