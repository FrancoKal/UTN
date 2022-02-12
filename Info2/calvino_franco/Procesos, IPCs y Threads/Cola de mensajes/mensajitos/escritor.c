#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_LENGTH 256
#define MY_ID 1234
#define PERMISOS 0666

typedef struct
{
    char msg[MAX_LENGTH];
} DATO;


typedef struct //estructura para los mensajes
{
	long mtype;
    DATO data;
	//DATO *data; NO se pueden usar punteros para las colas de mensajes ya que el kernel debe conocer el tamaño de los datos (el puntero devuelve siempre 8)
} msgbuf;


int main (int argc, char *argv[])
{
    int qid, msg_length;
    key_t key;
    msgbuf buf = {.mtype = 1};

    printf("Vamos a mandar mensajitos al lector\n");

    key = ftok("escritor.c", MY_ID);

    if (key == -1)
    {
        perror("ftok");
        exit(1);
    }

    qid = msgget(key, IPC_CREAT | PERMISOS);

    if (qid == -1)
    {
        perror("msgget");
        exit(2);
    }

    printf("Cola de mensajes creada con exito. Puede comenzar a escribir...\nPresione Enter para mandar el mensaje o EOF(^D) para salir\n");

    while (fgets(buf.data.msg, sizeof(buf.data.msg), stdin) != NULL)
    {
        msg_length = strlen(buf.data.msg);
        buf.data.msg[msg_length] = '\0';
                
        if (msgsnd(qid, &buf, msg_length, 0) != 0)
        {
            perror("msgnd");
            exit(3);
        }

        printf("Enviado '%s'\n", buf.data.msg);
    }

    msgctl(qid, IPC_RMID, NULL);

    return 0;
}