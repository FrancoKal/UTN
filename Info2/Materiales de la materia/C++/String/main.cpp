/*
   Nombre: principal.cpp
   Compilado sobre: QtCreator 2.1.0
   Autor: Marcelo Horacio Giura
   Fecha:   02/06/09
   Claves: Uso de operadores y funciones sobrecargadas. Uso de macros.

   Descripción: Definición de los métodos de la clase STRING.
*/

# include "myString.h"
# define _STOP_ cout<<"------------------------------------------------------"\
                <<endl<<endl; cout<<"Oprima ENTER para continuar\n"; getchar();

int main (void){
    cout <<"INSTRUCCION: String a(\"Informatica II\"),b(\"R2001\"),c(b),d,e;\n";
    String a("Informatica II"), b("R2001"), c(b), d, e;
    _STOP_  //detengo la ejecución
//------------------------------------------------------------------------------
    cout << "Prueba de sobrecarga de operador de flujo de insercion\n";

    cout << "Al escribir: \"cout << a << endl;\" obtengo:\t" << a << endl;
    cout << "Al escribir: \"cout << b << endl;\" obtengo:\t" << b << endl;
    cout << "Al escribir: \"cout << c << endl;\" obtengo:\t" << c << endl;
    cout << "Al escribir: \"cout << d << endl;\" obtengo:\t" << d << endl;
    cout << "Al escribir: \"cout << e << endl;\" obtengo:\t" << e << endl;

    _STOP_  //detengo la ejecución
//------------------------------------------------------------------------------
    cout << "[d=a]" << endl;
    d = a;
    cout << "\nd="<< d << "\na="<< a << endl;

    cout << "\n[c=b+a]";
    //c = b + a;                //c.operator= (b.operator+(a) )
    c.operator =(b.operator +(a)); //<<<<<<<<<<<<se crea un objeto y se destruye!!!! (con el +)
    cout << "\nc="<< c << endl;

    cout << "\n[b+=\"frba\"]" << endl;
    b += "frba";
    cout << b << endl;

    cout << "\n[\"Informatica2\"+b]" << endl;
    cout << "Informatica2"+b << endl;
    _STOP_  //detengo la ejecución
//------------------------------------------------------------------------------
    cout << "INSTRUCCION: String objeto(\"Informatica II\");";
    String objeto1 ("Informatica II");
    cout << endl;

    cout << "char* puntero;" << endl;
    char* puntero = NULL;
//    cout << "dirección del puntero (&puntero)" << (unsigned long)puntero
//        << endl << endl;

    //sobrecarga del operador '()'
    cout << "\"puntero = objeto('m');\"";
    puntero = objeto1('m');
//    cout << "\n(después)\tdireccion del puntero= " << hex
//         << (unsigned long)puntero << endl << endl;

    //sobrecarga del operador '[]'
    char car = 'X'; //inicializo en valor arbitrario
    cout << "\"car = objeto[7];\"";
    cout<<"\n(antes)\t\tcar= "<< car;
    car = objeto1[7];
    cout<<"\n(después)\tcar= "<< car << endl;
    _STOP_   //detengo la ejecución
//------------------------------------------------------------------------------

    String A("electronica"), B("electricidad"), C;
    cout << "\nOprima ENTER para saber si A es IGUAL a B: ";
    getchar();
    (A == B) ? cout << "SI" : cout << "NO";

    cout << "\n\nOprima ENTER para saber si A es DISTINTO de B: ";
    getchar();
    cout << endl;
    _STOP_   //detengo la ejecución
//------------------------------------------------------------------------------
    return 0;
}

