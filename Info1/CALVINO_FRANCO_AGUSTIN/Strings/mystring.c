#include "mystring.h"
#include <stdio.h>

char* strinsert (char *origin, char *strToInsert, int position)
{
    int i, new_len;
    char *str = (char*) malloc (sizeof(char) * (strlen(origin) + strlen(strToInsert) + 1));

    if (str != NULL)
    {
        //Copio la primera parte del origin en str hasta llegar a la posicion en donde quiero insertar el strToInsert
        //strncpy(str, origin, position);
        for (i = 0; i < position && origin[i] != '\0'; i++)
            str[i] = origin[i];

        //Copio strToInsert en str
        //strcat(str, strToInsert);
        for (i = 0; strToInsert[i] != '\0'; i++)
            str[position + i] = strToInsert[i];

        new_len = strlen(str);

        //Continuo copiando en origin en str desde donde lo habia dejado
        for (i = 0; origin[i + position] != '\0'; i++)
            str[i + new_len] = origin[i + position];

        str[i + new_len] = '\0';
    }

    return str;
}

int strstrpos(char *str, char *substr)
{
    char *parsedStr = strstr(str, substr);
    
    //Si el substr se encuentra en str, resto a la direccion del substr la direccion del str. La diferencia resultante es la posicion
    return (parsedStr != NULL)? (int) (parsedStr - str) : -1;
}

char* strreplace (char *str, char *substrToBeReplaced, char *strToReplace)
{
    int i, position, substrToBeReplaced_len = strlen(substrToBeReplaced);
    char *parsedStr = strstr(str, substrToBeReplaced);
    char *newStr = (char*) malloc (sizeof(char) * (strlen(str) + substrToBeReplaced_len - strlen(substrToBeReplaced)));

    if (parsedStr != NULL && newStr != NULL)
    {
        position = (int) (parsedStr - str); //La diferencia entre los dos punteros es la posicion del parsedStr en str

        //Copio la primera parte del origin en str hasta llegar a la posicion en donde quiero insertar el strToInsert
        for (i = 0; i < position && str[i] != '\0'; i++)
            newStr[i] = str[i];

        for (i = 0; strToReplace[i] != '\0'; i++)
            newStr[position + i] = strToReplace[i];

        position += i;

        //Tengo que empezar a copiar substrToBeReplaced_len lugares mas adelante, para ignorar el substrToBeReplaced
        for (i = 0; parsedStr[substrToBeReplaced_len + i] != '\0'; i++)
            newStr[position + i] = parsedStr[substrToBeReplaced_len + i];
    }

    return newStr;
}