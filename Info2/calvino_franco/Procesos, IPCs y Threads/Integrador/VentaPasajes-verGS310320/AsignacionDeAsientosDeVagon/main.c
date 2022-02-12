/*
** shmdemo.c -- read and write to a shared memory segment
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "SharedMemory.h"
#include "pantallas.h"
#include "archivos.h"
#include "socket.h"
#include "Hijos.h"
#include "inicializaciones.h"
#include "semaforos.h"

int main( void )
{
    char *Vagon;

    int sockfd , newSockfd ; 		//!< Escuchar sobre sockfp, nuevas conexiones sobre new_fp
    struct sockaddr_in their_addr ; //!< informacion sobre la direccion del cliente
    socklen_t sin_size ;

    int SalidaHijo;
    pid_t PidHijo;

    int idSem;

    /* Inicializa shared memory, socket y señales */
    if (  ( sockfd = Inicializar ( &Vagon ) ) <= 0 )
        return sockfd ;

    /* Inicializa semaforos */
    idSem = InicializarSemaforos( );

    LecturaVagon( &Vagon );             /* Lee vagon*/
    system("tput reset");               /* Hace clear de la terminal*/
    printf("\033[?2J"); 
    printf("\033[1;1H" );
    printf("\033[?25l");                //!< Desaparece el cursor
    fflush(stdout);
    PrintVagon ( Vagon );               /* Imprime vagon*/

    while( 1 ) //! lazo del accept
    {
         sin_size = sizeof( struct sockaddr_in ) ;

         //! Esperamos una conexión

         if ( ( newSockfd = accept( sockfd , ( struct sockaddr * )&their_addr, &sin_size)) == -1)
         {
             perror( "accept" ) ;
             exit ( 4 );
         }


         /** --------------------------- HIJO --------------------------------*/
         if ( !( PidHijo = fork( ) ) )
         {
             SalidaHijo = Hijos ( sockfd , newSockfd , Vagon , idSem);
             shutdown( newSockfd , 2 );     // Cierra sockets
             exit ( SalidaHijo );           // Termina proceso hijo
         }
         /** ------------------------ FIN DEL HIJO ---------------------------*/
     }
}

