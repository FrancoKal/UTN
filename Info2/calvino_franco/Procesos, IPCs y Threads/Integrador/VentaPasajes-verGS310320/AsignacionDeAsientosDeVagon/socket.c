/*******************************************************************************************************************************
 *
 * @file		Servidor_Envia_archivo.c
 * @brief		Ejemplo de servidor para envio de archivos
 * @date		16-03-19
 * @author		Ing. Marcelo Tujillo - Beej
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
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

/***********************************************************************************************************************************
 *** DEFINES PRIVADOS AL MODULO
 **********************************************************************************************************************************/
#define MYPORT          8877	//!< Puerto al que conectarán los usuarios
#define BACKLOG         10	//!< Cuántas conexiones pendientes se mantienen en cola
#define MAXDATASIZE 	100

/***********************************************************************************************************************************
 *** MACROS PRIVADAS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TIPOS DE DATOS PRIVADOS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TABLAS PRIVADAS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES PUBLICAS
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES PRIVADAS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** PROTOTIPO DE FUNCIONES PRIVADAS AL MODULO
 **********************************************************************************************************************************/

 /***********************************************************************************************************************************
 *** FUNCIONES PRIVADAS AL MODULO
 **********************************************************************************************************************************/

 /***********************************************************************************************************************************
 *** FUNCIONES GLOBALES AL MODULO
 **********************************************************************************************************************************/
int InicializarSocket(void)
{
    int sockfp ;//, new_fp ; 				//!< Escuchar sobre sock_fp, nuevas conexiones sobre new_fp
    struct sockaddr_in my_addr ; 			//!< informacion sobre mi direcciÃ³n
    int yes = 1 ;

    if ( ( sockfp = socket( AF_INET , SOCK_STREAM , 0 ) ) == -1 )
    {
        perror("socket");
        return -1;
    }

    /** En ocasiones, puedes encontrarte con que, al volver a ejecutar bind() en un servidor obtienes
    el error "Address already in use" (La direcciÃ³n ya se estÃ¡ usando). Â¿QuÃ© significa? Bueno, una
    parte de un socket que estuvo conectado, estÃ¡ todavÃ­a colgando en el nÃºcleo y estÃ¡
    bloqueando el puerto. Puedes esperar a que se libere (alrededor de un minuto) o aÃ±adirle
    cÃ³digo a tu programa permitiendo reutilizar el puerto, de este modo:*/

    if ( setsockopt( sockfp , SOL_SOCKET , SO_REUSEADDR , &yes , sizeof(int) ) == -1 )
    {
        perror("setsockopt");
        return -1;
    }

    my_addr.sin_family = AF_INET ;                  //!< Addrres family
    my_addr.sin_port = htons( MYPORT ) ;            //!< Port
    my_addr.sin_addr.s_addr = htonl( INADDR_ANY ) ; //!< Mi dirección IP
    memset( & ( my_addr.sin_zero ), '\0', 8 ) ; 	//!< Poner a cero el resto de la estructura

    /*Vinculamos socket con addr*/
    if ( bind( sockfp , (struct sockaddr *)&my_addr, sizeof( struct sockaddr ) ) == -1 )
    {
        perror("bind");
        return -1;
    }

    /*Dejamos socket en escucha a la espera por conexiones*/
    if ( listen( sockfp , SOMAXCONN ) == -1 )
    {
        perror( "listen" ) ;
        return -1;
    }

    return sockfp;
}
