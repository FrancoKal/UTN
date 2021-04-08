#include <stdio.h>
#include "mystring.h"

int main (void)
{
    char str1[] = "Hola como anda todo?", str2[] = "fiy", *str3 = NULL;
    
    printf("%s\n", str3 = strreplace(str1, "como", str2));
    free(str3);

    return 0;
}