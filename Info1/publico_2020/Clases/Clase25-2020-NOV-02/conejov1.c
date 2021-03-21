//Muchos hijos y waitpid

//Un solo hijo y wait



#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>


#define PROLE 10

int main (void)
{
        int pid;
	int result;
        int i;

        printf("Comenzando la procreación.\n");

        for (i = 0; i < PROLE; i++)
        { 
                pid = fork();

                if(pid > 0)
                {
                        printf("Generado el hijo: %d \n", i);
                }
                else if(pid == -1)
                {
                        printf("Error generando el hijo\n");
                }
                else
                {
					sleep(15*i+15);
        			return 0;
                }
        }

		i = 0;

        while (i < PROLE)
        {
			result = waitpid(-1,NULL,WNOHANG);
			if (result)
			{
				i++;
			}
			printf("Quiero hacer otra cosa. Mientras ya terminaron %i hijos\n", i);
        }

        return 0;
}
