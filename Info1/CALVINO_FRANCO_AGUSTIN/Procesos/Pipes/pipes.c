#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define HIJO 0
enum estados_pipe {LECTURA = 0, ESCRITURA = 1};

int main (void)
{
	int pid, ppid, p[2], num = 1234, buffer_num = 0;

	pipe(p); //Abro el pipe
	pid = fork();

	if (pid == HIJO)
	{
		ppid = getpid();
		close(p[LECTURA]);
		printf("Soy el hijo. Mi PID es %i y el de mi papa es %i\n", pid, ppid);
		printf("¿Por donde andas viejo?\nTe mando un numero...\n");
		write(p[ESCRITURA], &num, sizeof(int));
		close(p[ESCRITURA]);
	}
	else if (pid != -1)
	{
		sleep(5);
		printf("Soy el papa, y mi PID es %i\n", pid);
		close(p[ESCRITURA]);
		read(p[LECTURA], &buffer_num, sizeof(int));
		printf("Recibi: %i\n", buffer_num);
		close(p[LECTURA]);
	}
	
	return 0;
}
