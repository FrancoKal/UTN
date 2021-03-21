/**
	\file    mifrasesf.h
	\brief   Encabezado para el archivo mifrasesm.c
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2020.07.06
	\version 1.0.0
*/


#ifndef MIFRASESF_H
#define MIFRASESF_H

//----------------
//--- Includes ---
//----------------

#include <stdio.h>
#include <stdlib.h>

//----------------
//-- Prototipos --
//----------------

void errorarg (void);
void errormodo (void);
void errorfrase (void);

char * a_mayusc (char * frase);
char * a_minusc (char * frase);

int longitud (char * frase);

//----------------
//---- Define ----
//----------------

#endif


