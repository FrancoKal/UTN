#include "String.h"

void copyStr(char**, const char*);

void copyStr (char **dest, const char *orig)
{
    int strlen_orig, strlen_dest = 0;

    if (orig != nullptr)
    {
        strlen_orig = strlen(orig);

        if (*dest != nullptr)
            strlen_dest = strlen(*dest);

        if (*dest != nullptr && strlen_dest >= strlen_orig) //Si hay suficiente espacio para guardar orig en dest, no pido memoria y copio directamente
        {
            strcpy(*dest, orig);
            //(*dest)[strlen_orig + 1] = '\0';
        }
        else
        {
            if (*dest != nullptr)
                delete[] *dest; //free(dest);

            *dest = new char[strlen_orig + 1];

            if (*dest != nullptr)
            {
                strcpy(*dest, orig);
                (*dest)[strlen_orig + 1] = '\0';
            }
        }
    }
}

String::String(const char *s) : p(nullptr), tam(0)
{
    *this = s;
}

String::String(const String& s) : p(nullptr), tam(0)
{
    *this = s;
}

String::~String()
{
    if(p != nullptr)
        delete[] p;
}

String& String::operator=(const char *s)
{
    copyStr(&p, s);
    tam = strlen(s);

    return *this;
}

String& String::operator=(const String& s)
{
    copyStr(&p, s.p);
    tam = s.tam;

    return *this;
}

String operator+ (const char *c, const String& s)
{
    String buffer1;
    char *buffer2 = nullptr;
    int c_len = strlen(c);

    buffer2 = new char[c_len + s.tam];

    if (buffer2 != nullptr)
    {
        strcpy(buffer2, c);
        strcat(buffer2, s.p);
        buffer1 = buffer2;
        delete[] buffer2;
    }

    return buffer1;
}

String String::operator+ (const String& s)
{
    String buffer(*this);

    buffer += s.p; // Reutilizo el friend String operator+

    return buffer;
}

String& String::operator+=(const char *s)
{
    return (*this = *this + s); //Reutilizo el friend String operator+ y el operator=
}

ostream& operator<< (ostream& out, const String& s)
{
    out << s.p;

    return out;
}
