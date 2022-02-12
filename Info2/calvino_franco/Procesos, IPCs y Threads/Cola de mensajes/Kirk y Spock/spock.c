/*
** spock.c -- lectura desde una cola de mensajes
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msgbuf
{		//estructura para los mensajes
	long mtype;
	char mtext[200];
};

int main(void)
{
	struct my_msgbuf buf;
	int msqid;
	key_t key;

	if ((key = ftok("kirk.c", 'B')) == -1)
	{  /* same key as kirk.c */
		perror("ftok");		//sale por aquí en caso de error
		exit(1);
	}

	if ((msqid = msgget(key, 0644)) == -1)
	{ /* connect to the queue */
		perror("msgget");		//sale por aquí en caso de error
		exit(1);
	}
	
	printf("spock: Listo para recibir mensajes, capitan!\n");

	for(;;)
	{ /* de aquí no salgo!! */
		if (msgrcv(msqid, &buf, sizeof buf.mtext, 0, 0) == -1)
		{
			perror("msgrcv");	//sale por aquí en caso de error
			exit(1);
		}
		
		printf("spock leyó: \"%s\"\n", buf.mtext);
	}

	return 0;
}

