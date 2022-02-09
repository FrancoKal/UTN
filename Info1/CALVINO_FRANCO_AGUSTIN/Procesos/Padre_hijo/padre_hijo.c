#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define HIJO 0

int main (void)
{
	int pid, ppid;

	pid = fork();

	if (pid == HIJO)
	{
		ppid = getpid();
		printf("Soy el hijo. Mi PID es %i y el de mi papa es %i\nAhora me voy a dormir...\n", pid, ppid);
		sleep(30);
		printf("Termine\n");
	}
	else
	{
		printf("Soy el papa, y mi PID es %i\nYo tambien me voy a dormir\n", pid);
		sleep(10);
		wait(NULL);
	}

	return 0;
}
