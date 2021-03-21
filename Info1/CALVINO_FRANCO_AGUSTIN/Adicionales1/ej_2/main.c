#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define HIJO 0
#define LARGO_MAX 25
enum pipefd {READ = 0, WRITE = 1};

int main (void)
{
	int pid, pipe_padre_hijo[2], pipe_hijo_padre[2];
	char buffer[LARGO_MAX];

	pipe(pipe_padre_hijo);
	pipe(pipe_hijo_padre);
	pid = fork();

	switch (pid)
	{
		case -1:
			printf("Error generando al hijo\n");
			break;

		case HIJO:
			close(pipe_hijo_padre[READ]);
			close(pipe_padre_hijo[WRITE]);
			read(pipe_padre_hijo[READ], buffer, sizeof(buffer));
			close(pipe_padre_hijo[READ]);
			printf("%s\n", buffer); //Imprimo la frase del padre en el hijo para demostrar que funciona el pipe
			sleep(4);
			write(pipe_hijo_padre[WRITE], "Nooooooo!!", sizeof(buffer));
			close(pipe_hijo_padre[WRITE]);
			
			return 0;

		default:
			close(pipe_padre_hijo[READ]);
			close(pipe_hijo_padre[WRITE]);
			write(pipe_padre_hijo[WRITE], "Luke, yo soy tu padre", sizeof(buffer));
			close(pipe_padre_hijo[WRITE]);
			wait(NULL);
			read(pipe_hijo_padre[READ], buffer, sizeof(buffer));
			close(pipe_hijo_padre[READ]);
			printf("%s\n", buffer); //Imprimo la frase del padre en el hijo para demostrar que funciona el pipe
	}
			
	return 0;
}
