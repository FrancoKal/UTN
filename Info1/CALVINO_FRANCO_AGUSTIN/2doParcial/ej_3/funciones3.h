/**
	\file    funciones3.h
	\brief   Prototipos de las funciones del funciones3.c
	\author  Calvino, Franco (francoc.2002@gmail.com)
	\date    2020.11.30
	\version 1.0.0
*/


#ifndef FUNCIONES_H
#define FUNCIONES_H

#define HIJO 0
#define CTRLC SIGINT
enum pipefd {READ = 0, WRITE = 1};

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#define NUM 10


//----------------
//-- Prototipos --
//----------------
void tarea_hijo (int numero, int pid);
void atender(int sig);

//Acá poner los prototipos.

#endif


