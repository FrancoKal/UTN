#include "funciones.h"
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (void)
{
	FILE *archivo = NULL;
	char buffer_nombre[LARGO];
	int cant, i, pid, estado;
	void (*ordenar[]) (numeros*, int, FILE*) = {may_a_men, primos/*, floats*/};
	numeros *buffer = NULL;
	time_t tiempo;
	proc tareas[3] = {
				{"may_a_men.txt"},
				{"primos.txt"},
				/*{"floats.txt"}*/};	

	printf("Ingresa el nombre del archivo y te lo ordeno ---> ");
	fgets(buffer_nombre, sizeof(char) * LARGO, stdin);
	buffer_nombre[strlen(buffer_nombre) - 1] = '\0';
	archivo = fopen(buffer_nombre, "r");

	if (archivo != NULL)
	{
		cant = leer_numeros(archivo, &buffer);
		fclose(archivo);
		
		if (cant > 0)
		{
			printf("Se leyeron %i elementos. Comienza el proceso de ordenamiento\n", cant);
			pipe(tareas[0].pipefd);
			pipe(tareas[1].pipefd);
			//pipe(tareas[2].pipefd);
			
			for (i = 0; i </*CANT_TAREAS*/ 2; i++)
			{
				pid = fork();
								
				switch (pid)
				{
					case -1:
						printf("Error en la generacion del hijo");
						break;
					
					case HIJO:
						close((tareas[i]).pipefd[READ]);
						archivo = fopen((tareas[i]).name, "w");
						tiempo = time(NULL); //Comienzo a contar el tiempo
					
						if (archivo != NULL)
						{
							ordenar[i] (buffer, cant, archivo);
							fclose(archivo);
						}
						
						tiempo = time(NULL) - tiempo; //Resto el tiempo actual - el inicial
						write((tareas[i]).pipefd[WRITE], &tiempo, sizeof(time_t));
						close((tareas[i]).pipefd[WRITE]);
						
						if (buffer != NULL) free(buffer);
						
						return 0;
					
					default:
						close((tareas[i]).pipefd[WRITE]);
						break;		
				}
			}
			
			if (buffer != NULL) free(buffer);
			
			i = 0;
			
			while (i < /*CANT_TAREAS*/ 2)
			{
				estado = waitpid(-1, NULL, WNOHANG);
				
				if (estado > 0)
				{
					read((tareas[i]).pipefd[READ], &tiempo, sizeof(time_t));
					printf("Archivo '%s' generado, tiempo utilizado: %li\n", (tareas[i]).name, tiempo);
					close((tareas[i]).pipefd[READ]);
					i++;
				}
			}
		}
	}

	return 0;
}
