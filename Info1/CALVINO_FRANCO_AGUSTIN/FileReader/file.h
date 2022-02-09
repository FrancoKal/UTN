#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 4096 //4kb

void* GetFileContents (FILE *file);
unsigned int CountLines (FILE *file);
/*  Si fp == NULL, el archivo abierto es cerrado en la funcion. Sino, se almacena el puntero al archivo en fp.
    Retorno void* para poder retornar cualquier valor dependiendo de lo que retorne la funcion pasada como argumento    */
void* UseFile (char *FileName, char *mode, FILE **fp, void* (*function) (FILE*));