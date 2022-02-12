/*
** kirk.c -- escritura en una cola de mensajes
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msgbuf
{	//estructura para los mensajes
	long mtype;
	char mtext[200];
};

int main(void)
{
	struct my_msgbuf buf;
	int msqid, len;
	key_t key;

	if ((key = ftok("kirk.c", 'B')) == -1)
	{
		perror("ftok");	//sale por aquí en caso de error
		exit(1);
	}

	if ((msqid = msgget(key, 0644 | IPC_CREAT)) == -1)
	{
		perror("msgget");	//sale por aquí en caso de error
		exit(1);
	}
	
	printf("Ingrese líneas de texto finalizadas en ENTER.\nPara finalizar el ingreso envie EOF (^D):\n");

	buf.mtype = 1; /* dado que hay un solo productor y un solo consumidor en este caso, no tiene importancia*/

	while(fgets(buf.mtext, sizeof buf.mtext, stdin) != NULL) 
	{
		len = strlen(buf.mtext);

		/* convierto el '\n' en un nul ('\0') para trabajarlo como string */
		if (buf.mtext[len-1] == '\n') buf.mtext[len-1] = '\0';

		if (msgsnd(msqid, &buf, len+1, 0) == -1) /* +1 por el '\0' */
			perror("msgsnd");	//sale por aquí en caso de error
	}
	//terminé el trabajo, remuevo la cola de msg
	if (msgctl(msqid, IPC_RMID, NULL) == -1)
	{
		perror("msgctl");	//sale por aquí en caso de error
		exit(1);
	}

	return 0;
}

