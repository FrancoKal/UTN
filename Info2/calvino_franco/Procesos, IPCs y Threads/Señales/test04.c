/*Se agrega la captura la señal SIGALRM que se obtiene con la función alarm. El valor entre paréntesis – alarm (5) – indica el tiempo
 en segundos en que se disparará la alarma. En este caso en 5 segundos se generará la señal SIGALRM.
 -alarm (0), cancela la alarma pendiente.
Si había una alarma pendiente un nuevo llamado a alarm renueva el contador.
Ejemplos de uso:  temporizar funciones bloqueantes (p/ej read) o funciones que eventualmente podrían demorar demasiado ante algún error. 
­­*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

volatile char end_flag=0;	//!!!!!!

 void sigalrm_handler (int sig)
 {
	 (void)sig;
	 write (1,"\n\n ***** Soy el handler de SIGALRM\n\n",37);	

 }

void sigusr1_handler (int sig)
{
	(void)sig;
	write (1,"\n\n ##### Soy el handler de SIGUSR1\n\n",36);	
	
	//end_flag=1;
}

void sigint_handler(int sig)
{
	(void)sig; 

	write(1, "\n\n $$$$$ Ahhh... llegó Ctrl-C! SIGINT!\n\n", 42);
}

////////////////////////////////////////

int main (int argc, char **argv)
{
	int i=0;
	struct sigaction sa;
	char s[200];

//////////////////////////////////////////// USR1
	sa.sa_handler = sigusr1_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);	//inicializa la máscara de la signal en cero.

	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{  // instala el nuevo handler para SIGUSR1
		perror("sigaction x SIGUSR1");
		exit(1);
	}
//////////////////////////////////////////// INT
	sa.sa_handler = sigint_handler;
	//sa.sa_flags = SA_RESTART;
        sa.sa_flags = 0;
        
	sigemptyset(&sa.sa_mask);	//inicializa la máscara de la signal en cero.

	if (sigaction(SIGINT, &sa, NULL) == -1)
	{  // instala el nuevo handler para SIGINT
		perror("sigaction x SIGINT");
		exit(1);
	}
	
//////////////////////////////////////////// ALRM
	sa.sa_handler = sigalrm_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);	//inicializa la máscara de la signal en cero.

	if (sigaction(SIGALRM, &sa, NULL) == -1)
	{  // instala el nuevo handler para SIGALRM
		perror("sigaction x SIGALRM");
		exit(1);
	}	
	
///////////////////////////////////////
	while (!end_flag)
	{
		printf ("--> %d - %d\n",getpid(),i++);
		printf ("--+ Primer Ingreso (antes de X segundos):");
		
		alarm(10);	// --- 5 segundos

		if (fgets(s, sizeof s, stdin) == NULL)
		{
			perror("fgets");
			continue;
		}
		else 
			printf("You entered: %s\n", s);
			

		alarm(0);	// --- Se cancela la alarma
		printf ("--+ Sedundo Ingreso:");
		


		if (fgets(s, sizeof s, stdin) == NULL)
			perror("fgets");
		else 
			printf("You entered: %s\n", s);
	}
	
	return 0;
}
