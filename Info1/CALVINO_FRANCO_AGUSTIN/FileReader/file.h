#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 4096 //4kb

char* getFileContents (FILE *file);
//Si fp == NULL, el archivo abierto es cerrado en la funcion. Sino, se almacena el puntero al archivo en fp
char* ReadFile (char *FileName, char *mode, FILE **fp);