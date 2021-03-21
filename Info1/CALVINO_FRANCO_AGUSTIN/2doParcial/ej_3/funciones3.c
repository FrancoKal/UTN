/**
	\file    funciones3.c
	\brief   Funciones basicas que utiliza el main3.c
	\author  Calvino, Franco (francoc.2002@gmail.com)
	\date    2020.11.30
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------
#include "funciones3.h"

/**
	\fn     <Prototipo de la función>
	\brief  <Función de la función>
	\author Calvino, Franco (francoc.2002@gmail.com)
	\date   2020.11.30
	\param  <Parámetro A>
	\param  <Parámetro B>
	\return <Lo que retorna>
*/

void tarea_hijo (int n, int pid)
{
	sleep(n*NUM);
	printf("Hijo %i, PID: %i, PPID: %i acaba de terminar su siesta de %i segundos\n", n, pid, getppid(), n*NUM);
}

void atender(int sig)
{
	while (waitpid(-1, NULL, WNOHANG) > 0);
}

