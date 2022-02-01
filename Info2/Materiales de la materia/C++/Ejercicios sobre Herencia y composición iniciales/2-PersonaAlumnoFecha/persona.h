#ifndef PERSONA_H
#define PERSONA_H

using namespace std;
#include <iostream>
#include <string.h>
#include "fecha.h"

const Fecha fAux (1,1,1960);   //var auxiliar (constante) para inicializar Fecha a valores x defecto


class Persona
{
private:
    char* apeNom_;
    long doc_;
    Fecha fNac_;

public:
    Persona();
    Persona(const char *, const long, const Fecha&);
    Persona(const char*, const long, const int, const int, const int);
    Persona (const Persona&);
    ~Persona() {delete apeNom_;}

    void setPersona(const char*, const long, const Fecha&);
    char* get_apeNom () const {return apeNom_;}
    long get_doc () const {return doc_;}
    Fecha get_fNac () const {return fNac_;}

    Persona& operator= (const Persona&);
    friend ostream& operator<< (ostream&, const Persona& );
};

#endif // PERSONA_H
