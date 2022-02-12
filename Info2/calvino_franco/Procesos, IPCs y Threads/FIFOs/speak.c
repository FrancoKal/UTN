/*Una vez que la FIFO se ha creado, el proceso puede comenzar y puede abrirla para leerla  o escribirla usando la system call estándar open( ).   
Puesto que es más fácil entender el proceso una vez que se tiene algún código concebido, presentaré aquí dos programas que enviarán datos a través de un FIFO. Uno es speak.c que envía datos a través del FIFO, y el otro se llama tick.c, que saca datos de la FIFO.   
Aquí está  speak.c:   
*/
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

        /* no olvide chequear errores!! */
        mknod(FIFO_NAME, S_IFIFO | 0666, 0);

        printf("esperando lectores...\n");
        fd = open(FIFO_NAME, O_WRONLY);
        printf("tengo un lector—tipee algo\n");

        while (gets(s), !feof(stdin)) {
            if ((num = write(fd, s, strlen(s))) == -1)
                perror("escribir");
            else
                printf("speak: escribió %d bytes\n", num);
        }
        
        return 0;
    }
