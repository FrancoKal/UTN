#include "color.h"

void copyStr (char **dest, char *orig)
{
    int strlen_orig, strlen_dest;

    if (*dest != nullptr && orig != nullptr)
    {
        strlen_orig = strlen(orig);
        strlen_dest = strlen(*dest);

        if (strlen_dest >= strlen_orig) //Si hay suficiente espacio para guardar orig en dest, no pido memoria y copio directamente
        {
            strcpy(*dest, orig);
            (*dest)[strlen_orig + 1] = '\0';
        }
        else
        {
            delete *dest; //free(dest);
            *dest = new char[strlen_orig];

            if (*dest != nullptr)
                strcpy(*dest, orig);
        }
    }
}

Color::Color() : R(33), G(33), B(33), name(nullptr), costo(1000)
{
    set_name((char*) "Blanco");
}

void Color::set_name (char *nuevo_nombre)
{
    copyStr(&name, nuevo_nombre);
}

int Color::get_Color (color_primario c)
{
    /*int color = -1;

    switch (c)
    {
        case red:
            color = R;
            break;

        case green:
            color = G;
            break;

        case blue:
            color = B;
            break;
    }

    return color;*/

    int color[] = {red, green, blue};

    return (c > red && c <= blue)? color[c] : -1;
}

void Color::crear_Color(const Color& c1, const Color& c2)
{
    R = (c1.R + c2.R) / 2;
    G = (c1.G + c2.G) / 2;
    B = (c1.B + c2.B) / 2;
}

Color& Color::operator= (const Color& c)
{
    R = c.R;
    G = c.G;
    B = c.B;
    costo = c.costo; // set_costo(c.costo);

    if (name != c.name)
        set_name(c.name);

    return *this;
}

istream& operator>> (istream& in, Color& c)
{
    char buffer[MAX_LENGTH];

    cout << ">> Ingrese los datos para el color\n";

    cout << "\tRojo(%): ";
    in >> c.R;

    cout << "\tVerde(%): ";
    in >> c.G;

    cout << "\tAzul(%): ";
    in >> c.B;

    cout << "\tNombre: ";
    in.getline(buffer, sizeof (buffer), '\n');
    c.set_name(buffer);

    cout << "\tCosto: ";
    in >> c.costo;

    return in;
}
