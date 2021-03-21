#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{



	char * f1 = "Como te va chichipio";
	char * f2 = malloc (100);

	strcpy(f2, "Como te va chichipio");

	printf("%s", strstr(f1,"te"));
	printf("%s", strtok(f2,"te"));


	return 0;
}

