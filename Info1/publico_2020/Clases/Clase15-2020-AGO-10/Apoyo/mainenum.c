
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define CANT 100

enum color{ ROJO, VERDE, AZUL };

void printColor(enum color chosenColor);

//---------------------------------------------------------------------------------------------

int main(void)
{
    	enum color chosenColor;
	int i;

	srand(time(NULL));

	for (i=0; i< CANT; i++)
	{
		chosenColor = rand()%4;
		printf("[%d]: ", i);
		printColor(chosenColor);
	}

	return 0;
}

//---------------------------------------------------------------------------------------------

void printColor(enum color chosenColor)
{
    char * color_name = "Color elegido no válido";
    switch (chosenColor)
    {
       case ROJO:
         color_name = "ROJO";
         break;

       case VERDE:
        color_name = "VERDE";
        break;

       case AZUL:
        color_name = "AZUL";
        break;
    }
    printf("%s (%d)\n", color_name, chosenColor);
}

//---------------------------------------------------------------------------------------------
