#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define HIJO 0

void viejo_insoportable (int sig)
{
	sleep(5);
	printf("¡Espera un poco viejo!\n");
}

void mal_educado (int sig)
{
	sleep(5);
	printf("¡A mi no me contestas asi!\n");
}

int main (void)
{
	int pid;
	struct sigaction sa_hijo, sa_padre;

	pid = fork();

	switch (pid)
	{
		case -1:
			printf("Error generando al hijo\n");
			break;

		case HIJO:
			sa_hijo.sa_handler = &viejo_insoportable;
			sigemptyset(&sa_hijo.sa_mask);
			sigaction(SIGUSR1, &sa_hijo, NULL);
			sleep(5);
			kill(getppid(), SIGUSR2);
			sleep(1);
			
			return 0;

		default:
			sa_padre.sa_handler = &mal_educado;
			sigemptyset(&sa_padre.sa_mask);
			sigaction(SIGUSR2, &sa_padre, NULL);
			printf("¡Hijo, andate a dormir de una vez!\n");
			kill(pid, SIGUSR1);
			wait(NULL);
	}
			
	return 0;
}
