#ifndef COLOR_H
#define COLOR_H

enum color_primario {red = 0, green = 1, blue = 2};
#define MAX_LENGTH 256

#include <string.h>
#include <iostream>

using namespace std;

class Color
{
    protected:
        int R, G, B;

    private:
        char *name;
        float costo; // Costo por litro de color

        void cleanName() { if (name != nullptr) delete name; }

    public:
        Color();
        Color(int rojo, int verde, int azul, char *nombre, float precio) : R(rojo), G(verde), B(azul), name(nombre), costo(precio) {};
        Color(const Color& c) { *this = c; }
        ~Color() { cleanName(); }

        void set_name (char *nombre);
        char* get_name (void) { return name; }
        void set_costo(float precio) { if ( precio > 0) costo = precio; }
        float get_costo(void) { return costo; }
        int get_Color (color_primario c);
        void crear_Color(const Color& c1, const Color& c2);

        Color& operator= (const Color&);
        friend istream& operator>> (istream&, Color& c);

};

void copyStr(char *dest, char *orig);

#endif // COLOR_H
