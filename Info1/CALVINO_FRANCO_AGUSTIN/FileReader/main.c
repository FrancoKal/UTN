#include "file.h"

int main (void)
{
    FILE *fp = NULL;
    char *result = UseFile("main.c", "r", &fp, GetFileContents);
    unsigned int lines = CountLines(fp);

    printf("%s\n\nN of lines = %i\n", result, lines);

    return 0;
}