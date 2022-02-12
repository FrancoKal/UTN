#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/sem.h>

#include "strings.h"
#include "socket.h"
#include "Hijos.h"
#include "SharedMemory.h"
#include "pantallas.h"
#include "semaforos.h"

int Hijos ( int sockfd , int newSockfd  , char *Vagon , int id )
{
    char buf[ 100 ];
    int fila,columna;

    ssize_t nbytes;

    close( sockfd ); //!< El hijo no necesita este descriptor

    while( 1 )
    {
        if ( ( nbytes = recv( newSockfd , buf, sizeof( buf ), 0)) <= 0 )
        {
            if ( nbytes == 0 ) // error o conexión cerrada por el cliente
                return 0;
            else
                perror("recv");
            return 1;
        }

        /* Como recibe datos del formato siguiente: 0302
         * donde 03es la fila y 02 es la columna, debajo
         *  extrae fila y columna*/
        buf[nbytes] = '\0';
        fila = atoi ( buf ) / 100;
        columna = atoi ( buf ) % 100;

        /*Decrementa en 1 el valor del semaforo bloqueandolo
         * y con ellos bloqueando shared memory*/
        if( semop( id , &p, 1 ) < 0 )
        {
            perror("semop p");
            return 3;
        }

        /*Revisa el estado del asiento solicitado y contesta
         * LIBRE, OCUPADO o RESERVADO segun sea el estado del asiento */
        switch ( Vagon[ (fila - 1) * N + ( columna - 1) ] )
        {
            case 'L':
                Vagon[ (fila - 1) * N + ( columna - 1) ] = 'O';
                PrintAsiento ( 'O' , fila , columna );
                if ( ( nbytes = ( int ) send( newSockfd , "LIBRE" ,  strlen("LIBRE" ) ,  0 ) ) == -1 )
                {
                    perror( "send" );
                    return 2;
                }

                break;
            case 'O':
                if ( ( nbytes = ( int ) send( newSockfd , "OCUPADO" ,  strlen("OCUPADO") ,  0 ) ) == -1 )
                {
                    perror( "send" );
                    return 2;
                }
                break;
            case 'R':
                if ( ( nbytes = ( int ) send( newSockfd , "RESERVADO" ,  strlen("RESERVADO" ) ,  0 ) ) == -1 )
                {
                    perror( "send" );
                    return 2;
                }
                break;
        }

        /* Libera el semaforo y retorna*/
        if( semop( id , &v , 1 ) < 0)
        {
            perror("semop p");
            return 3;
        }
    }
 }
