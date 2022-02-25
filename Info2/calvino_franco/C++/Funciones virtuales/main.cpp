#include "funcionVirtual.h"

//Descomentar la linea de abajo para usar la version sin funciones virtuales
//using namespace SinFuncionVirtual;

//Descomentar la linea de abajo para usar la version con funciones virtuales
using namespace ConFuncionVirtual;

//Descomentar la linea de abajo para usar la version con funciones puramente virtuales (no compilara)
//using namespace ConFuncionPuramenteVirtual;

int main (void)
{
    Base b, *p1 = nullptr;
    Derivada d, *p2 = nullptr;

    /*
        Una estructura y un objeto con las mismas variables ocupan el mismo espacio en memoria si no hay funciones virtuales
        en la clase de dicho objeto.
        Si la clase contiene alguna funcion virtual, la clase guardara tambien en memoria un puntero a una Vtable, por lo que pesara
        8 bytes mas que antes.
    */
    std::cout << "sizeof DATO = " << sizeof(DATO) << "\n";
    std::cout << "sizeof Base = " << sizeof(Base) << "\n";
    std::cout << "sizeof Derivada = " << sizeof(Derivada) << "\n";

    //Llamo al metodo Nombre de la clase base
    b.Nombre();

    //Llamo al metodo Nombre de la clase Derivada
    d.Nombre();

    //Llamo el metodo Nombre de la clase Base, pero a traves de un objeto de la clase Derivada
    d.Base::Nombre();

    //Llamo el metodo Nombre desde un puntero a un objeto de la clase Base 
    p1 = &b;
    p1->Nombre();

    /*  Como p1 es un puntero a un objeto la clase Base, *p1 es ahora un objeto de la clase Base
        (no importa que tenga la direccion a un objeto de clase Derivada).
        Por lo tanto, al llamar al metodo Nombre del objeto *p1, estoy llamando al metodo correspondiente a la clase Base,
        no al de la clase Derivada  */
    p1 = &d;
    p1->Nombre();

    /*
    Esto no puedo hacerlo porque estoy guardando la direccion a un objeto de la clase Base en un puntero a clase Derivada.
    *p2 es ahora un objeto de la clase Derivada, pero va a tener el metodo Nombre de la clase Base, por lo que el compilador no podra encontrar
    la direccion de memoria del metodo Nombre de la clase Derivada
    
    p2 = &b;
    p2->Nombre();
    */

    /*  --------------------------------------------------------------------------------------------------------------- 
        Output sin funciones virtuales:
        Soy la clase Base
        Soy la clase Derivada
        Soy la clase Base
        Soy la clase Base
        Soy la clase Base
        --------------------------------------------------------------------------------------------------------------- */

    /*  --------------------------------------------------------------------------------------------------------------- 
        Output con funciones virtuales:
        Soy la clase Base
        Soy la clase Derivada
        Soy la clase Base
        Soy la clase Base
        Soy la clase Derivada
        --------------------------------------------------------------------------------------------------------------- */

    return 0;
}