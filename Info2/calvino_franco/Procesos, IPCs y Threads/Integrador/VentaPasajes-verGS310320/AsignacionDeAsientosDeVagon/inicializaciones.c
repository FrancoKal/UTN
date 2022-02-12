
#include <stdio.h>

#include "SharedMemory.h"
#include "socket.h"
#include "señales.h"

int Inicializar ( char ** Vagon )
{
    int shmid ;         //!< Shared Memory
    int sockfd ; 		//!< Escuchar sobre sockfp, nuevas conexiones sobre new_fp

    /* conectar ( y crear ) el segmento de memoria */
    if ( ( shmid = ConectarSharedMemori( Vagon  ) ) == -1)
        return -1;

    /* Crea socket tcp y lo deja en listen*/
    sockfd = InicializarSocket( );

    if ( sockfd < 0 )
        return -2;

    InicializarSenales( );

    return sockfd;
}
