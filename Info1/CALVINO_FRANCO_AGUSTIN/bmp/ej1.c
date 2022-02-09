#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"

int main (int argc, char **argv)
{
    int i, j, opcion, auxTamano;
    BMP **aux = NULL;
    Mi_BMP **lista = NULL, *aux2 = NULL;
    FILE *file = NULL;;

    //Corresponde a la lectura de los archivos
    aux = (BMP**) malloc (sizeof(BMP) * (argc-1));

    if (aux != NULL)
    {
        for (i = 0; i < argc; i++)
        {
            file = fopen(argv[i+1], "r");

            if (file != NULL)
            {
                LeerBMP(file, &aux[i]);
                fclose(file);
            }
        }
    }
    //------------------------------------------------------------

    //Copiamos aux en la estructura que nos interesa
    lista = (Mi_BMP**) malloc (sizeof(Mi_BMP) * (argc-1));

    if (lista != NULL)
    {
        for (i = 0; i < argc; i++)
        {
            lista[i] = (Mi_BMP*) malloc (sizeof(Mi_BMP));

            if (lista[i] != NULL)
            {
                lista[i]->Nombre = argv[i+1];
                lista[i]->TamanoArchivo = aux[i]->Tamano;
                lista[i]->TamanoImagen = aux[i]->TamImagen;
                lista[i]->AlturaImagen = aux[i]->AlturaImagen;
                lista[i]->AnchuraImagen = aux[i]->AnchuraImagen;
            }
        }
    }
    //--------------------------------------------------------------

    printf("1) Ordenar por nombre de archivo e imprimir");
    printf("2) Ordenar por tamano de archivo e imprimir");
    scanf("%i",&opcion);

    switch(opcion)
    {
        case 1:
            for (i = 0; i < argc; i++)
            {
                for (j = i; j < argc; i++)
                {
                    if (strcmp(lista[i]->Nombre, lista[j+1]->Nombre) > 0)
                    {
                        aux2 = lista[j+1];
                        lista[j+1] = lista[i];
                        lista[i] = aux2;
                    }
                }
            }

            break;
        case 2:
            for(i = 0; i < argc; i++)
            {
                auxTamano = atoi(lista[i]->TamanoArchivo);

                for (j = i; j < argc; i++)
                {
                    if (auxTamano > atoi(lista[j+1]->TamanoArchivo))
                    {
                        aux2 = lista[j+1];
                        lista[j+1] = lista[i];
                        lista[i] = aux2;
                    }
                }
            }

            break;
        default:
            printf("Opcion no valida\n");
            break;
    }

    for(i = 0; i < argc; i++)
    {
        free(aux[i]);
        free(lista[i]);
    }

    free(aux);
    free(lista);

    return 0;
}