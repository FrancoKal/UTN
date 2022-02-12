#include <pthread.h>
#include <stdio.h>

void* print_xs (void* unused)
{
	while(1)
		fputc('t', stdout);
		
	return NULL;
}

int main ()
{
	pthread_t thread_id;
	
	pthread_create(&thread_id,NULL,&print_xs,NULL);
	
	while(1)
		fputc('m', stdout);
		
	return 0;
}
