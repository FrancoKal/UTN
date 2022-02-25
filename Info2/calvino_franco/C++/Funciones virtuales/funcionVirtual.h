#ifndef SINFUNCIONVIRTUAL_H
#define SINFUNCIONVIRTUAL_H

#include <iostream>

typedef struct
{
    int x;
    char *p;
} DATO;

namespace SinFuncionVirtual
{
    class Base
    {
        private:
            int x;
            char *p;

        public:
            Base() {};
            ~Base() {};

            void Nombre() { std::cout << "Soy la clase Base\n"; }
    };

    class Derivada: public Base
    {
        private:
            int x;
            char *p;

        public:
            Derivada() {};
            ~Derivada() {};

            void Nombre() { std::cout << "Soy la clase Derivada\n"; }
    };
}

namespace ConFuncionVirtual
{
    class Base
    {
        private:
            int x;
            char *p;

        public:
            Base() {};
            ~Base() {};

            virtual void Nombre() { std::cout << "Soy la clase Base\n"; }
    };

    class Derivada: public Base
    {
        private:
            int x;
            char *p;

        public:
            Derivada() {};
            ~Derivada() {};

            void Nombre() { std::cout << "Soy la clase Derivada\n"; }
    };
}

#endif