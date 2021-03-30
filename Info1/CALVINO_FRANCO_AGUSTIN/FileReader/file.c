#include "file.h"

char* GetFileContents (FILE* file)
{
    char buffer[MAX_FILE_SIZE], *str = NULL;
    size_t size;

    size = fread(buffer, sizeof(char), MAX_FILE_SIZE, file);
    buffer[size + 1] = '\0';
    str = (char*) malloc(sizeof(char) * (size+1));

    if (str != NULL) strcpy(str, buffer);

    return str;
}

char* ReadFile (char *FileName, char *mode, FILE **fp)
{
    FILE* file = NULL;
    char *contents = NULL;

    file = fopen(FileName, mode);

    if (file != NULL)
    {
        contents = GetFileContents(file);

        //(fp != NULL)? *fp = file : fclose(file); Esto no funciona, no se porque
        if (fp != NULL)
            *fp = file;
        else
            fclose(file);
    }

    return contents;
}

