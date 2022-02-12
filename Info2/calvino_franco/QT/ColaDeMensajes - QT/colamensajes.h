#ifndef COLAMENSAJES_H
#define COLAMENSAJES_H

#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>


class ColaMensajes
{
    public:
        ColaMensajes();
        ~ColaMensajes();

        int crearCola(char);
        inline bool existeCola(void) { return existe;}
        int eliminarCola();

        int insertarPorTipo(int , int);

        int retirarPorTipo(int);
        int retirarDelPrincipio();

        static const int COLA_EXISTENTE = -1;
        static const int COLA_INEXISTENTE = -2;

    private:
        bool existe;
        int qid;
        key_t msgkey;
};

typedef struct my_msgbuf
{
    long mtype;
    int num;
} mess_t;

#endif // COLAMENSAJES_H
