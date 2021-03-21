/**
	\file    funciones2.h
	\brief   Prototipos de las funciones del funciones2.c
	\author  Calvino, Franco (francoc.2002@gmail.com)
	\date    2020.11.30
	\version 1.0.0
*/


#ifndef FUNCIONES_H
#define FUNCIONES_H

#define ERROR -1
#define LARGO_MAX 255
#define DEFAULT_PORT 3490

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>


typedef struct
{
	int codigo;
	float peso;
	long existencia;
} DATOS;

//----------------
//-- Prototipos --
//----------------
int generacion (int * codigos, int cant_codigos, DATOS ** listado, char * nombre_arch);
int solicitar_codigos(int **codigos);

#endif


