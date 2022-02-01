#include "lse.h"

//LSE::LSE()
//{

//}

bool LSE::enlistar(DATO &D)
{
    NODO *i = H;
    if (vacio ())
        return Push (D);
    if (D.edad < i->d.edad)
        return Push (D);

    while (i->next){
        if (D.edad < i->next->d.edad)
//            return insertar (i, D);
            break;
        i = i->next;
    }

    //llegué al final y apunto al último nodo
    return insertar (i,D);
}

bool LSE::insertar(NODO *i, DATO & D)
{
    NODO *q;
    if (!(q = new NODO))
        return false;

    q->next = NULL;
    q->d = D;
    //ya tengo armado el nodo

    q->next = i->next;
    i = q;
    return true;
}

istream& operator>>(istream& in, LSE& l)
{
    DATO d;
    cout << "\nIngrese Nombre y Apellido, Edad y Calificacion separado por ENTER:\n";
    cin >> d.N >> d.edad >> d.nota;

    if(!l.enlistar (d)){
       cout << "\nERROR. Adios.";
       exit (1);
    }
    return in;
}

//ostream& operator<< (ostream& sal, const LSE& l)
//{
//    NODO *i;
//    i = l.H;
//    sal << ">> Imprimo la EaD desde H hasta el NULL: " << endl;

//    if(l.vacio ()){
//        cout << "\nLISTA VACIA.";
//    }
//    while(i) {
//        sal << "Nombre y Apellido: " << i->d.N << '\t'
//            << "Edad: " << i->d.edad << '\t'
//            << "Calificacion: " << i->d.nota << endl;
//        i = i->next;
//    }
//    sal << "-----------------------------------" << endl;
//    return sal;
//}

