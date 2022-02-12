#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

typedef struct
{
	int Principal;
	int Extra;
} Evento;

int x = 0;

void* char_print (void* parametros)
{
	Evento* Ev = (Evento*) parametros;
	
	printf("Evento: Ppal:%d  -  Extra:%d\n\n", Ev->Principal,  Ev->Extra);
	printf("PID del nuevo thread = %i\n", getpid());
	printf("Direccion de x en el thread = %p\n", &x);
	x++;
	//printf("Ahora el thread se va a dormir...\n");

	//while (1) sleep(1);

	return NULL;
}

int main(void)
{
	Evento Ev_main;
	pthread_t thread_id;
	
	Ev_main.Principal = 1234;	//valor arbitrario
 	Ev_main.Extra = 5678; 		//valor arbitrario
	printf("PID del thread principal = %i\n", getpid());
	printf("Direccion de x en el main = %p\n", &x);
	pthread_create (&thread_id, NULL, &char_print, (void*) &Ev_main);
	pthread_join (thread_id, NULL);
	sleep(1);
	printf("Ahora x vale %i\n", x);
	/*pthread_detach(thread_id);
	printf("El thread acaba de desprenderse\n");*/
	
	return 0;
}
