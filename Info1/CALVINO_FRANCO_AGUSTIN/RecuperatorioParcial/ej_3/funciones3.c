/**
	\file    funciones3.c
	\brief   Funciones basicas que utiliza el main3.c
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.10.26
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include <math.h>
#include "funciones3.h"

/**
	\fn     <Prototipo de la función>
	\brief  <Función de la función>
	\author Franco Calvino (francoc.2002@gmail.com)
	\date   2020.10.26 
	\param  <Parámetro A>
	\param  <Parámetro B>
	\return <Lo que retorna>
*/

float raiz (int n)
{	
	return (n > 0)? sqrt(n) : ERROR; 
}

float cuadrado (int n)
{
	return n*n;
}

float modulo (int n)
{
	return (n > 0)? n : -n;
}

float signo (int n)
{
	return -n;
}
