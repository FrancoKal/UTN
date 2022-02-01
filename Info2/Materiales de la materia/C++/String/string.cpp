/*
   Nombre: STRING.CPP
   Compilado sobre: QtCreator 2.1.0
   Autor: Marcelo Horacio Giura
   Fecha:   02/06/09
   Claves: Reserva y liberación de memoria - sobrecarga de funciones y operado-
   res - referencias - puntero this - friend.
   Descripción: Definición de los métodos de la clase STRING.
*/

#include "myString.h"
//------------------------------------------------------------------------------
// Defino un constructor por defecto que me reserva 20 lugares. 20 es arbitrario
// Podría no haber definido ninguna reserva de memoria y esperar a la primera
// inicialización del objeto. Es una cuestión de estrategia.
String::String (){   //constructor x default
        len = 20;
        p = new char [20]; //reservo x defecto 20 bytes arbitrariamente...
        *p = '\0';		     //inicializo la cadena
        //cout << "\n@Constructor x default. \tDirección del objeto en memoria: "
        //     << hex << (unsigned long)this << endl;
}
//------------------------------------------------------------------------------
String::String (const char *cad){ //constructor parametrizado.
    len = strlen(cad);
    p = new char [len+1];
    strcpy(p, cad);
//        cout <<"\n#Constructor parametrizado.\tDirección del objeto en mem.: "
//             << hex << (unsigned long)this << endl;
}
//------------------------------------------------------------------------------
String::String (const String& z){ //constructor de copia
    len = strlen (z.p);
    p = new char [len+1];
    strcpy (p, z.p);
//        cout << "\n$Constructor de copia. \t\tDirección del objeto en memoria: "
//             << hex << (unsigned long)this << endl;
}
//------------------------------------------------------------------------------
String::~String (){  //Destructor: Apreciar el modo de invocar a la función
    delete [] p;      // delete. Si pedí como array, debo liberar como array.
//    cout << "-Destructor. \t\t\tDirección del objeto en memoria: "
//         << hex << (unsigned long)this << endl;
}
//------------------------------------------------------------------------------
// operador de asignación: Un objeto igual a otro objeto
String& String::operator= (const String& z){ //x ejemplo d=a
   if(len < z.len){          //verifico si me alcanza el lugar para alocar
        delete [] p;           //si no alcanza, deleteo y y pido de nuevo
        len = strlen(z.p);
        p = new char [len+1];
    }
    strcpy (p, z.p);
    return *this;  //devuelvo el propio objeto garantizando operaciones
}                 //múltiples (a=b=c=d)

//------------------------------------------------------------------------------
// operador de asignación: Un objeto igual a una cadena
String& String::operator= (const char *cad){ //x ejemplo a="Boca campeon"
    if((unsigned char)len < strlen(cad) ) {  //verifico si me alcanza el lugar para alocar
        delete [] p;             //si no alcanza, deleteo y y pido de nuevo
        len = strlen(cad);
        p = new char [len+1];
    }
    strcpy (p, cad);
    return *this;    //devuelvo el propio objeto garantizando operaciones
}                    //múltiples (a=b=c=d)

//------------------------------------------------------------------------------
//Operador suma: Un objeto + otro objeto (mi operador lo configuro para que me
// planche un espacio entre las dos cadenas a concatenar)
String String::operator+ (const String& z){ //x ejemplo b+a
    String aux;  //no uso referencia pues NO modificará el argumento implícito.
    delete aux.p;  //libero la memoria pues es más fácil que recalcular
    aux.len = strlen(p)+ strlen(z.p) + 2;//calculo cuanto medirán ambas cadenas
    aux.p = new char [aux.len];
    strcpy (aux.p, p);
    strcat (aux.p, " ");//le plancho el separador (por eso sumo 2)
    strcat (aux.p, z.p);//le agrego la cadena recibida en el objeto explícito
    return aux;            //retorno el objeto auxiliar
}
//------------------------------------------------------------------------------
//Operador suma: Un objeto + una cadena  mi operador lo configuro para que me
// planche un espacio entre las dos cadenas a concatenar)
// NO ES NECESARIO IMPLEMENTARLA PUES YA EXISTE UNA SOBRECARGA DEL OPERADOR '+'
// A NIVEL GLOBAL => el compilador 'ya sabe' como trabajar con ambos tipos de
// operandos.
//String String::operator+ (const char *cad){ //x ejemplo b +" frba"
//	String aux;
//	aux.len = strlen(p)+ strlen(cad) + 2; //calculo cuanto medir�n ambas cadenas
//	delete aux.p;
//	aux.p = new char [aux.len];	//pido memoria para almacenarlas
//	strcpy (aux.p, p);
//	strcat (aux.p, " ");			//le plancho el separador
//	strcat (aux.p, cad);
//	return aux;
//}

//------------------------------------------------------------------------------
//Operador suma-igual (entre dos objetos)
//por modificar el argumento implícito, aquí SI devuelvo una referencia
String& String::operator+= (const String& z){ //x ejemplo b+=a
    char* paux = new char [len]; //buffer auxiliar
    strcpy (paux, p);   //almaceno temporalmente en paux la string del argumento implícito.

    delete p;   //es mas fácil que verificar si hay espacio
    len = strlen(paux) + strlen(z.p) + 2; //calculo cuanto medirán ambas cadenas
    p = new char [len];
    strcpy (p, paux);    //guardo la cadena almacenada temporalmente en paux
    strcat (p, " ");	   //le plancho el separador (por eso sumé 2)
    strcat (p, z.p);		//le agrego la cadena del objeto explícito
    delete [] paux;      //libero la memoria pedida temporalmente
    return *this;
}//como aquí modifico el operador implícito, retorno una referencia a 'mi mismo'

//------------------------------------------------------------------------------
//Operador suma-igual (un objeto += una cadena)
//String& String::operator+= (const char*& cad){ //x ejemplo b+="Boca Campeón"
/*¿porqué no es necesario hacerlo? >>> PROMOCION AUTOMÁTICA DE TIPOS: Existe
 * un constructor que sabe construir un String a partir de una cadena */

//------------------------------------------------------------------------------
//devuelve el contenido de lo subindicado
char& String::operator[] (int offset){
    return p[offset];
    //devuelvo una referencia para permitirme hacer en el main cosas como
    //vector[i]=ALGO siendo vector[i] la referencia devuelta por el operador
    //sobrecargado
}
//------------------------------------------------------------------------------
//devuelve un puntero a la primera ocurrencia del caracter enviado como argumen-
//to. Por error, devuelve NULL
char* String::operator() (char c){
    return strchr(p, c);
}

//------------------------------------------------------------------------------
/* ****SOBRECARGA DEL '+' COMO friend****** */
String operator+ (const char *cad, const String& z){
    String aux;                     //no hay argumento implícito pues es friend
    aux.len = strlen(cad) + strlen(z.p)+ 2;
    delete aux.p;                        //elimino para no recalcular
    aux.p = new char [aux.len];
    strcpy (aux.p, cad);
    strcat (aux.p, " ");
    strcat (aux.p, z.p);
    return aux;
}

//------------------------------------------------------------------------------
/* ***** SOBRECARGA DEL OPERADOR de EXTRACCION de FLUJO COMO friend ****** */
ostream& operator<< (ostream& out, const String& z){
    out << " (VALOR CADENA:) " << z.p;
    return out;
}

//------------------------------------------------------------------------------
/* ***** SOBRECARGA DE '==' COMO friend ****** */
int operator== (const String& z1, const String& z2){
   return (!strcmp (z1.p, z2.p)) ? 1 : 0;
} //podría devolver bool, pero por compatibilidad con '!=' devuelve int

//------------------------------------------------------------------------------
//Quiero que sirva como strcmp (3 valores de devolución....)
int operator!= (const String& z1, const String& z2){
   int res = strcmp (z1.p, z2.p);
   if (res < 0)
      return -1;
   return (res == 0) ? 0 : 1;
}
//------------------------------------------------------------------------------

