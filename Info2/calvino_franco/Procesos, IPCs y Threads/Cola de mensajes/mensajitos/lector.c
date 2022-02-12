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
    int qid;
    key_t key;
    msgbuf buf = {.mtype = 1};

    key = ftok("escritor.c", MY_ID);

    if (key == -1)
    {
        perror("ftok");
        exit(1);
    }

    qid = msgget(key, 0);

    if (qid == -1)
    {
        perror("msgget");
        exit(2);
    }

    printf("Esperando mensajitos del escritor...\n");

    while (1)
    {
        if (msgrcv(qid, &buf, sizeof(DATO), 0, 0) == (ssize_t) -1)
        {
            perror("msgrcv");
            exit(3);
        }

        buf.data.msg[strlen(buf.data.msg)] = '\0';
        printf("Se recibio: '%s'", buf.data.msg);
    }

    return 0;
}
