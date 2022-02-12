#include "colamensajes.h"

ColaMensajes::ColaMensajes(){
    // Valores por defecto
    existe = false;
    qid = -1;
    msgkey = -1;
}

ColaMensajes::~ColaMensajes(){
}


int ColaMensajes::crearCola(const char id){
    if(!existe){
        msgkey = ftok("colamensajes.cpp", id);
        qid = msgget(msgkey, IPC_CREAT | 0660); //(Podría usarse IPC_EXCL y verificar si ya existía (EEXIST))
        existe = true;
        return 0;
    }
    else return COLA_EXISTENTE;
}


int ColaMensajes::eliminarCola(){
    if(existe){
        int res;
        res = msgctl(qid, IPC_RMID, 0);
        if(res == 0){   // Se elimino la cola
            existe = false;
            qid = -1;
            msgkey = -1;
        }
        return res; // 0 Si se elimino, caso contrario -1 errno
    }
    else return COLA_INEXISTENTE;
}

int ColaMensajes::insertarPorTipo(int tipo, int valor){
    mess_t buf;
    buf.mtype = tipo;
    buf.num = valor;
    return msgsnd(qid, &buf, sizeof(buf.num), 0);        // Cargo el mensaje en la cola
    //Retorna error(-1 -> errno) o 0
}

int ColaMensajes::retirarPorTipo(int tipo){
    mess_t buf;
    msgrcv(qid, &buf, sizeof(buf.num), tipo, 0);
    return buf.num;
}

int ColaMensajes::retirarDelPrincipio(){

    mess_t buf;
    msgrcv(qid, &buf, sizeof(buf.num), 0, 0);
    return buf.num;
}
