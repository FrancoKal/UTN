#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string.h>

using namespace std;

class String
{
    private:
        char *p;
        short tam;

    public:
        String() : p(nullptr), tam(0) {};
        String(const char*);
        String(const String&);
        ~String();

        String& operator=(const String&);
        String& operator=(const char*);
        String& operator+= (const char *);
        String operator+ (const String&);
        String operator+= (const String&);
        friend String operator+ (const char*, const String&);
        friend ostream& operator<< (ostream&, const String&);
        friend istream& operator>> (istream&, String&);
};

#endif // STRING_H
