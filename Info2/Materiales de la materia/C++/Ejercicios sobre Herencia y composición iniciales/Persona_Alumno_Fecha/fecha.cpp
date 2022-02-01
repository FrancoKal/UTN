#include "fecha.h"

//al ser static, es global solo para este fuente
static int cantDiasXmes[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


Fecha::Fecha(int d, int m, int a){
    setFecha(d, m, a);
}

Fecha::Fecha (const Fecha& f){
    dia_ = f.dia_;
    mes_ = f.mes_;
    anio_ = f.anio_;
}

void Fecha::setFecha (int d, int m, int a){
    if (a >= 1960 && a < 2050)  //especificacion de año supuesta
        if (m > 0 && m < 13)
            if (d <= cantDiasXmes[m]){
                dia_ = d; mes_ = m; anio_ = a;
                return;
    }
    /*Control de Año bisiesto: es divisible entre 4, salvo que sea año secular -último de cada siglo, terminado en «00»-, en cuyo caso ha de ser divisible entre 400. En nuestro caso no nos interesa el año secular*/
    if (d == 29 && m == 2 && (a >= 1960) && (a < 2050) && !(a%4) ){
        dia_ = d; mes_ = m; anio_ = a;
    }
    else{
        cout << "\nNo es posible establecer correctamente los atributos del objeto "
                "con los datos recibidos. Verifique los parámetros." << endl;
        dia_ = 0; mes_ = 0; anio_ = 0;
    }
}

Fecha& Fecha::operator= (const Fecha& f){
    dia_ = f.dia_;
    mes_ = f.mes_;
    anio_ = f.anio_;
    return *this;
}

ostream& operator<< (ostream& o, const Fecha& f){
    o << "Fecha: " << f.dia_ << "/" << f.mes_
      << "/" << f.anio_ << endl;
    return o;
}
