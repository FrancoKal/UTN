#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

volatile char end_flag=0;	//!!!!!!

void sigusr1_handler (int sig)
{
	(void)sig;
	write (1,"Soy el handler de SIGUSR1\n",26);	//asinc safe
	//end_flag=1;
}

void sigint_handler(int sig)
{
	(void)sig; 
	write(1, "Ahhh... llegó Ctrl-C! SIGINT! \n", 30);
}

////////////////////////////////////////

int main (int argc, char **argv)
{
	int i=0;
	struct sigaction sa;
	char s[200];

////////////////////////////////////////////
	sa.sa_handler = sigusr1_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);  //inicializa la máscara de la signal en cero.

	if (sigaction(SIGUSR1, &sa, NULL) == -1) { // instala el nuevo handler para SIGUSR1
		perror("sigaction x SIGUSR1");
		exit(1);
	}
////////////////////////////////////////////
	sa.sa_handler = sigint_handler;
	//sa.sa_handler = SIG_IGN;	//¿Qué pasa si descomentamos esta línea? >>> ignorar el signal al recibirlo
        //sa.sa_handler = SIG_DFL;	//¿Qué pasa si descomentamos esta línea? >>> usa el tratamiento por defecto
	sa.sa_flags = 0;
	
	sigemptyset(&sa.sa_mask);	//inicializa la máscara de la signal en cero.

	if (sigaction(SIGINT, &sa, NULL) == -1) { // instala el nuevo handler para SIGINT
		perror("sigaction x SIGINT");
		exit(1);
	}
///////////////////////////////////////
	while (!end_flag)
	{
		printf ("--> %d - %d\n",getpid(),i++);

		if (fgets(s, sizeof s, stdin) == NULL)
			perror("\nfgets");
		else 
			printf("You entered: %s\n", s);
	}
	return 0;
}
