#include <stdio.h>
#include <stdlib.h>


int main (int argc, char * argv [])
{

	int i;
	int suma = 0;


	if (argc < 3)
	{
		printf("Ponete las piletas, por los menos dos numeros para sumar.\n");
	}
	else
	{
		printf("Sumando.........\n\n");
		for (i=1; i<argc; i++)
		{
			if (i==2)
			{
				printf("+%7d\n", atoi(argv[i]));
			}
			else
			{
				printf("%8d\n", atoi(argv[i]));
				suma = suma + atoi(argv[i]);
			}
		}
		printf("_____________\n%8d\n\n", suma);
	}
	return 0;

}
