/* Headers */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

/* Defines */
#define CANT_TIPOS          3
#define CANT_MENSAJES       10

/* Colors for the console */
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/* Redefines the message structure */
typedef struct my_msgbuf
{
  long mtype;
  int num;
} mess_t;

int main()
{
  int qid;
  key_t msgkey;
  pid_t pid;

  mess_t buf;

  int cont;
  int msgtype;

  msgkey = ftok("msgqueue.c",'a');

  qid = msgget(msgkey, IPC_CREAT | 0660);

  srand (time (0));

  printf("\n\nFormateando didácticamente (COLOR) la salida del padre (Recepción): \n\t" 
			ANSI_COLOR_RED "TIPO1" ANSI_COLOR_RESET "\t"\
			ANSI_COLOR_GREEN "TIPO2" ANSI_COLOR_RESET "\t"\
			ANSI_COLOR_BLUE "TIPO3" ANSI_COLOR_RESET "\n"\
			"********************************************\n\n");
  
  if(!(pid = fork())){

  /******************** Proceso HIJO ******************************/
    printf("Hijo ENVIA - QID = %d\n\n", qid);

    for(cont = 0; cont < CANT_MENSAJES; cont++){
      sleep (rand()%4);                     // Esperamos un x tiempo aleatorio de máximo 3 segundos

      buf.mtype = (rand()%CANT_TIPOS)+1;   // Tipo de mensaje aleatorio entre 1 y 3
      buf.num = rand()%100;                // Numero aleatorio entre 0 y 99
      
      msgsnd(qid, &buf, sizeof(buf.num), 0);        // Cargo el mensaje en la cola

      printf("Hijo - Enviando mensaje numero %d del tipo %ld: %d\n", cont+1, buf.mtype, buf.num);
    }

    return 0;
  }
  /*****************************************************************/

  printf("Padre RECIBE - QID = %d\n\n", qid);

  for(cont = 0; cont < CANT_MENSAJES; cont++){
    sleep (rand()%4);

    msgrcv(qid, &buf, sizeof(buf.num), 0, 0);

    msgtype = buf.mtype;

    switch(msgtype)
    {
      case 1:
        printf(ANSI_COLOR_RED "\t\tPadre - Recibiendo mensaje numero %d: %d" ANSI_COLOR_RESET "\n", cont+1, buf.num);
      break;
      case 2:
        printf(ANSI_COLOR_GREEN "\t\tPadre - Recibiendo mensaje numero %d: %d" ANSI_COLOR_RESET "\n", cont+1, buf.num);
      break;
      case 3:
        printf(ANSI_COLOR_BLUE "\t\tPadre - Recibiendo mensaje numero %d: %d" ANSI_COLOR_RESET "\n", cont+1, buf.num);
      break;
      default:
        printf(ANSI_COLOR_YELLOW "\nPadre - Error de tipo" ANSI_COLOR_RESET "\n");

    }

  }

  msgctl(qid, IPC_RMID, 0);    /* Destruir la cola de mensajes */

  return 0;
}
