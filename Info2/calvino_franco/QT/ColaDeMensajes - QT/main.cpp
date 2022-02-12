#include "iostream"
#include "colamensajes.h"
#include <unistd.h> //Para fork

using namespace std;

#define CANT_TIPOS 2
#define CANT_MENSAJES 10

/* Colores para la consola */
#define ANSI_COLOR_RED            "\x1b[31m"
#define ANSI_COLOR_GREEN          "\x1b[32m"
#define ANSI_COLOR_YELLOW         "\x1b[33m"
#define ANSI_COLOR_BLUE           "\x1b[34m"
#define ANSI_COLOR_MAGENTA        "\x1b[35m"
#define ANSI_COLOR_CYAN           "\x1b[36m"
#define ANSI_COLOR_RESET          "\x1b[0m"

int main(void)
{
    pid_t pid;
    int cont = 0;

    ColaMensajes cola;

    if(cola.crearCola('b') == ColaMensajes::COLA_EXISTENTE){
        cout << "Cola ya existe" << endl;
        exit(-1);
    }


    if(!(pid = fork()))
    {
        /******************** Proceso HIJO ******************************/
        for(cont = 0; cont < CANT_MENSAJES; cont++){
            sleep (rand()%4);                     // Esperamos un x tiempo aleatorio de máximo 3 segundos
            int valor = rand()%100;               // Valor aleatorio entre 0 y 99
            int tipo = 1;
            cola.insertarPorTipo(tipo, valor);
            cout << ANSI_COLOR_RED "Hijo - Enviando mensaje numero " << cont+1 << " del tipo " << tipo << " = " << valor << ANSI_COLOR_RESET  << endl;
        }

        return 0;
    }


    /******************** Proceso PADRE ******************************/
    int valor = 0;
     for(cont = 0; cont < CANT_MENSAJES; cont++){

        valor = cola.retirarPorTipo(1);
        cout <<ANSI_COLOR_GREEN "Padre - Recibiendo mensaje del tipo 1.. numero "<< cont+1 << " = " << valor <<ANSI_COLOR_RESET << endl;

     }


      if(cola.eliminarCola() == ColaMensajes::COLA_INEXISTENTE){
        cout << "Cola inexistente" << endl;
        exit(-1);
      }
      else{
          cout << "Cola eliminada" << endl;
      }

    return 0;
}
