#include "funciones.h"

void LeerBMP(FILE* file, BMP **datos)
{
    *datos = (BMP*) malloc(sizeof(BMP));

    if (*datos != NULL)
    {
        /*do
        {
            //Para leer cada uno
            //fread((*datos)->cTipoFichero, sizeof(char), 2, file);
            fscanf("%s\n", (*datos)->cTipoFichero, file);
        }
        while (feof(file) == 0);*/
        
        //Para leer todo
        fread(*datos, sizeof(BMP), 1, file);
    }
}