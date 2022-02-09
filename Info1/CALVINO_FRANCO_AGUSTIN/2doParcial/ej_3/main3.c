/**
	\file    main3.c
	\brief   Rutina principal (main) del programa
	\author  Calvino, Franco (francoc.2002@gmail.com)
	\date    2020.11.30
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------
#include "funciones3.h"

int contador = 0;

void func_padre (int sig)
{	
	contador++;
}

/**
	\fn      int main (---)
	\brief   <Función de la función>
	\author  Calvino, Franco (francoc.2002@gmail.com)
	\date    2020.11.30
	\param   <Parámetro A (si no tiene no se pone)>
	\param   <Parámetro B (si no tiene no se pone)>
	\return  0
*/

int main (void)
{
	int pid, i, cant_max, cant_final;
	struct sigaction sa, sa_atender;
	sa_atender.sa_handler = &atender;
	sa_atender.sa_flags = 0;
	sigemptyset(&sa_atender.sa_mask);
	
	sa.sa_handler = &func_padre;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	
	printf("Cantidad maxima de hijos---> ");
	scanf("%i", &cant_max);
	
	if (cant_max > 0)
	{
		srandom(time(NULL));
		cant_final = rand() % cant_max;
		printf("Una lastima, vamos a generar %i hijos\n", cant_final);
		
		if (sigaction(SIGCHLD, &sa_atender, NULL) == -1)
		{
			perror("sigaction");
			exit(1);
		}
		
		for (i = 0; i < cant_final; i++)
		{
			pid = fork();
			
			switch (pid)
			{
				case -1:
					printf("Error generando al hijo %i\n", i);
					
					return 0;
					
				case HIJO:
					sleep(i*NUM);
					tarea_hijo(i, getpid());
					
					return 0;
					
				default:
					break;
			}
		}
		

		if (sigaction(CTRLC, &sa, NULL) == -1 /*|| sigaction(SIGCHLD, &sa_atender, NULL) == -1*/)
		{
			perror("sigaction");
			exit(1);
		}
		
		//while(1) sleep(1);
		while(contador != 5) sleep(1);
		
		printf("\n");
	}
					
	return 0;
}

