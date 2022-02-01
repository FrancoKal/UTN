using namespace std;
#include <iostream>
#include <string.h>
#include "fecha.h"
#include "persona.h"

Persona::Persona()/*:fNac_()*/
{
    apeNom_  = NULL;
    doc_     = 0;
}

Persona::Persona(const char* nya, const long dni, const Fecha &f)
    :fNac_(f)
{
    apeNom_ = new char [strlen(nya) +1];
    strcpy (apeNom_, nya);
    doc_ = dni;
}

Persona::Persona (const char * nya, const long dni, const int d, const int m, const int a)
    :fNac_(d, m, a){
    apeNom_ = new char [strlen(nya) +1];
    strcpy (apeNom_, nya);
    doc_ = dni;
}

Persona::Persona (const Persona& p):fNac_(p.fNac_){
    apeNom_ = new char [strlen(p.apeNom_) +1];
    strcpy (apeNom_, p.apeNom_);
    doc_ = p.doc_;
}

void Persona::setPersona(const char* nya, const long dni, const Fecha& f){
    apeNom_ = new char [strlen(nya) +1];
    strcpy (apeNom_, nya);
    doc_     = dni;
    fNac_    = f;
}

Persona& Persona::operator= (const Persona& p){
    apeNom_ = new char [strlen(p.apeNom_) +1];
    strcpy (apeNom_, p.apeNom_);
    doc_     = p.doc_;
    fNac_    = p.fNac_;
    return *this;
}

ostream& operator<< (ostream& o, const Persona& p){
    if (!p.apeNom_)
        o << "La Persona no ha sido inicializada" << endl;
    else {
        o << "Apellido y Nombre: "  << p.apeNom_ << endl;
        o << "\t# Documento: "        << p.doc_    << endl;
        o << "\tNacimiento: "   << p.fNac_   << endl;
    }
    return o;
}
