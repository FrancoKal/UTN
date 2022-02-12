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

int main (int argc, char **argv)
{
	int i=0;
	struct sigaction sa;

	sa.sa_handler = sigusr1_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);

	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(1);
	}

	while (!end_flag)
	{
		printf ("--> %d - %d\n",getpid(),i++);
		sleep (1);
	}
	return 0;
}

