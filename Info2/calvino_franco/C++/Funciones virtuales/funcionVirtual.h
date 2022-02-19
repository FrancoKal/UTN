#ifndef SINFUNCIONVIRTUAL_H
#define SINFUNCIONVIRTUAL_H

#include <iostream>

namespace SinFuncionVirtual
{
    class Base
    {
        public:
            Base() {};
            ~Base() {};

            void Nombre() { std::cout << "Soy la clase Base\n"; }
    };

    class Derivada: public Base
    {
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
        public:
            Base() {};
            ~Base() {};

            virtual void Nombre() { std::cout << "Soy la clase Base\n"; }
    };

    class Derivada: public Base
    {
        public:
            Derivada() {};
            ~Derivada() {};

            void Nombre() { std::cout << "Soy la clase Derivada\n"; }
    };
}

#endif