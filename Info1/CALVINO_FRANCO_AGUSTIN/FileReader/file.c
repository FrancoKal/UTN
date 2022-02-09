#include "file.h"

void* GetFileContents (FILE* file)
{
    char buffer[MAX_FILE_SIZE], *str = NULL;
    size_t size;

    size = fread(buffer, sizeof(char), MAX_FILE_SIZE, file) + 1; //Agrego 1 para almacenar el '\0'
    buffer[size] = '\0';
    str = (char*) malloc(sizeof(char) * size);

    if (str != NULL) strcpy(str, buffer);

    return (void*) str; //Lo casteo a void* para no generar problemas
}

unsigned int CountLines (FILE* file)
{
    unsigned int c, lines = 0, EndOfLine = (int) '\n';

    do
    {
        c = fgetc(file);

        if (c == EndOfLine) lines++;

    } while (c != EOF);

    return lines;
}

//Con el puntero a funcion, paso como parametro lo que quiero hacer con el archivo
void* UseFile (char *FileName, char *mode, FILE **fp, void* (*function) (FILE*))
{
    FILE* file = NULL;
    void *contents = NULL;

    file = fopen(FileName, mode);

    if (file != NULL)
    {
        contents = function(file);//GetFileContents(file);

        //(fp != NULL)? *fp = file : fclose(file); Esto no funciona, no se porque
        if (fp != NULL)
            *fp = file;
        else
            fclose(file);
    }

    return contents;
}

