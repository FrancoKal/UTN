/*******************************************************************************************************************************//**
 *
 * @file		Cliente_Pide_Archivo.c
 * @brief		Ejemplo de cliente de pedidos de archivos
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
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

/***********************************************************************************************************************************
 *** DEFINES PRIVADOS AL MODULO
 **********************************************************************************************************************************/
#define PORT 			8877 				//!< Puerto de destino
#define BACKLOG 		10 					//!< Cuántas conexiones pendientes se mantienen en cola
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
int main(int argc, char *argv[])
{
    struct in_addr addr ;
    int sockfd, numbytes ;
    char buf[ 100 ] ;
    struct sockaddr_in their_addr ; // informacion de la direccion de destino

    /* Verifica la cantidad de argumentos de linea de comandos
     *  si no son 2 imprime un tutorial */
    if ( argc != 2 )
    {
        printf("Forma de Uso ---------------------------------------------\n" ) ;
        printf("Coloque la IP del Servidor\n" ) ;
        printf("Ejemplo: 127.0.0.1\n" ) ;
        printf("----------------------------------------------------------\n" ) ;
        return 1 ;
    }

    /* Verifica la valides de la direccion IP */
    printf("%s\n"  ,argv[ 1 ] );
    if ( inet_aton( argv[ 1 ] , &addr ) == 0 )
    {
        fprintf( stderr , "Invalid address\n" ) ;
        exit( EXIT_FAILURE ) ;
    }

    /* Crea socket cliente */
    if ( ( sockfd = socket( AF_INET , SOCK_STREAM , 0 ) ) == -1 )
    {
        perror( "socket" );
        exit( 1 );
    }

    /* Carga struc sockaddr_in y se conecta a servidor */
    their_addr.sin_family = AF_INET ; 			//!< Ordenacion de bytes de la maquina
    their_addr.sin_port = htons( PORT ) ;		//!< short, Ordenacion de bytes de la red
    their_addr.sin_addr = addr ;				//!< Direccion IP
    memset( &(their_addr.sin_zero) , 0 , 8 ) ; 	// poner a cero el resto de la estructura

    if ( connect( sockfd , (struct sockaddr *)&their_addr,	sizeof(struct sockaddr)) == -1 )
    {
        perror( "connect" );
        exit( 1 );
    }

    while (1)
    {
        /* Pide ingreso de asiento  a comprar */
        printf("fila y columna, dos digitos cada uno sn espacio\n");
        printf("Ejemplo: 0302\n");
        scanf("%s",buf);

        /* Envia info e asiento al servidor*/
        if ( send( sockfd , buf , strlen( buf ) ,  0 ) == -1 )
            perror( "send" );

        /* Espera respuesta */
        sleep( 1 );

        /* Recibe los datos*/
        if ( ( numbytes = (int) recv( sockfd , buf , MAXDATASIZE-1, 0 ) ) == -1 )
        {
            perror( "recv" );
            exit( 1 );
        }

        buf[ numbytes ] = '\0';

        /* Analiza los datos y da realimentacion de resultado a usuario
         * si compra finalizada con exito cierra socket y termina,
         * si no pide otro asiento */
        if ( !strcmp( buf , "OCUPADO") )
        {
            printf("Asiento Ocupado\n");
            printf("Intentelo Nuevamente\n");
        }

        if ( !strcmp( buf , "RESERVADO") )
        {
            printf("Asiento Reservado\n");
            printf("Intentelo Nuevamente\n");
        }
        if ( !strcmp( buf , "LIBRE") )
        {
            printf("Compra Aceptada\n");
            shutdown( sockfd , 2 );
            return 0 ;
        }
    }
}
