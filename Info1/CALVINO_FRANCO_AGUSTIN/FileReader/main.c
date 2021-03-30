#include "file.h"

int main (void)
{
    char *str = NULL;
    
    str = ReadFile("main.c", "r", NULL);
    printf("%s\n", str);
    free(str);

    return 0;
}