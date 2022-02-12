#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* char_print (void* parameters)
{
	int i;
	for(i = 0; i < 3000; ++i)
      		fputc('t', stderr);
      		
	return NULL;
}

int main(void)
{
	pthread_t thread_id;
	
	pthread_create(&thread_id, NULL, &char_print, NULL);
	pthread_join (thread_id, NULL);
	
	return 0;
}
