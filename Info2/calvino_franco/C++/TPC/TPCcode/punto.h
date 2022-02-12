#ifndef PUNTO_H
#define PUNTO_H

#include <math.h>
#include <iostream>

using namespace std;

#define DEFAULT_LIMIT 1000

class Punto
{
    private:
        double mx, my;
        static size_t CantCreada, CantExistente;
        static float min_, max_;
        double CheckInput (double x);

    public:
        Punto (double x = 0, double y = 0); //Puedo pasar 0, 1 o 2 parametros. Los que no paso inicializan en 0
        Punto (const Punto&);
        ~Punto () { CantExistente--; }
        
        /*          Sobrecarga de operadores            */
        Punto& operator= (const Punto&);
        Punto operator+ (const Punto& p);
        Punto operator- (const Punto& p);
        Punto& operator++ (); //pre-incremento ++p
        Punto operator++ (int); //pos-incremento p++
        /*Punto operator+ (const double a);
        Punto operator- (const double a);
        No los necesito porque el compilador compilador realiza la conversion de floats a Punto automaticamente al llamar a una funcion del tipo operator */
        bool operator== (const Punto& p);
        bool operator!= (const Punto& p);
        bool operator> (const Punto& p);
        bool operator< (const Punto& p);
        friend ostream& operator<< (ostream& out, Punto& p);
        friend istream& operator>> (istream& in, Punto& p);
        /*  ------------------------------------------   */

        /*          Seteadores          */
        void setPunto (double x, double y)
        {
            setX(x);
            setY(y);
        }

        void setPunto (const Punto& p);
        Punto& getPunto() { return *this; }
        void setX(double x) { mx = CheckInput(x); }
        void setY(double y) { my = CheckInput(y); }
        static void set_limites (float min, float max);
        /*  ---------------------------  */

        /*          Geteadores          */
        double getX() const { return mx; }
        double getY() const { return my; }
        /*  Necesito hacer ambas funciones static para poder accederlas sin miembro (es decir, usando Punto::), ya que de lo contrario, el compilador
            asumira que se trata de un miembro de un objeto en especifico, y no de uno comun a toda la clase    */
        static size_t getCantCreada() { return CantCreada; }
        static size_t getCantExistente() { return CantExistente; }
        static float getLimiteSup() { return max_; }
        static float getLimiteInf() { return min_; }
        /*  --------------------------   */
};

float distance (double x, double y);

#endif // PUNTO_H
