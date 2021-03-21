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
        int i;

        printf("Comenzando la procreación.\n");

        for (i = 0; i < PROLE; i++)
        { 
                pid = fork();

                if(pid > 0)
                {
                        printf("Generado el hijo: %d (pid: %d)\n", i, pid);
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

        for (i = 0; i < PROLE; i++)
        {
			wait(NULL);
    		printf("Quiero hacer otra cosa\n");
        }

        return 0;
}
