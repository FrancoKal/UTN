#include <string.h>
#include <stdlib.h>

char* strinsert (char *origin, char *ToInsert, int position); //Inserta 'ToInsert' en la posicion 'position' dentro de 'origin' 
int strstrpos (char *str, char *substr); //Devuelve la posicion del inicio del 'substr' en 'str' si lo encontro. Caso contrario, retorna -1
char* strreplace (char *str, char *substrToBeReplaced, char *strToReplace);