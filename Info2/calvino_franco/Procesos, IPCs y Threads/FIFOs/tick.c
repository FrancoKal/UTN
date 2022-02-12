/*Lo que speak hace es crear la FIFO, entonces intenta abrirla con open (). Ahora, lo que pasará es que el llamado a open () bloqueará hasta que algún otro proceso abra el otro extremo del pipe para leer. (Hay una manera referida a esto—ver debajo O_NDELAY, ) Ese proceso es tick.c, mostrado aquí,:   */

    #include <stdio.h>
    #include <stdlib.h>
    #include <errno.h>
    #include <string.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>

    #define FIFO_NAME "FIFOinfo2"
    int main (void)
    {
        char s[300];
        int num, fd;

        /* no olvide chequear esto!! */
        mknod(FIFO_NAME, S_IFIFO | 0666, 0);

        printf("esperando a quien escriba...\n");
        fd = open(FIFO_NAME, O_RDONLY);
        printf("conseguí un escritor:\n");

        do {
            if ((num = read(fd, s, 300)) == -1)
                perror("read");
            else {
                s[num] = '\0';
                printf("tick: leí %d bytes: \"%s\"\n", num, s);
            }
        } while (num > 0);
    }

/*Tal como sucedía con speak.c, tick, aquí se bloqueará la ejecución con open ( ) si no hay ni una escritura en la FIFO. En cuanto alguien abra la FIFO para escribir, tick volverá a la vida.   
¡Pruébelo! Ejecute speak  y se bloqueará hasta que usted arranque tick en otra ventana. (Recíprocamente, si usted empieza tick, bloqueará hasta que usted ejecute speak en otra ventana.) Teclee en la ventana de speak y tick lo tomará.   

Ahora, salga de speak. Aviso lo que pasa: los read ( ) en tick retornan 0, lo que significa fin de archivo. De esta manera, el lector puede decir cuando todos los escritores han cerrado su conexión a la FIFO. ¡¿Qué?¡ Pregunta si puede haber escritores múltiples al mismo pipe? Efectivamente! Eso puede ser muy útil. Quizás muestre después en el documento cómo puede explotarse esta ventaja.   
Pero por ahora, permítame terminar este tema viendo lo que pasa cuando sale de tick mientras speak está corriendo. "¡Pipe roto"!  ¿Quién hizo esto? Bien, lo que ha pasado es que cuando todos los lectores de una FIFO cierran y el escritor está todavía abierto, el escritor recibirá la señal SIGPIPE la próxima vez que intente escribir. 
El handler predefinido de la señal escribe "Pipe Roto" y termina. Por supuesto, usted puede manejar esto más airosamente tomando SIGPIPE a través de la llamada a la función signal ().
   
Finalmente ¿qué pasa si tiene lectores múltiples? Bien, las cosas extrañas pasan. A veces uno de los lectores consigue todo. A veces alterna entre los lectores. Sin embargo, ¿Para qué quiere tener lectores múltiples ? */
