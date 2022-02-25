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

namespace ConFuncionPuramenteVirtual
{
    class Base
    {
        private:
            int x;
            char *p;

        public:
            Base() {};
            ~Base() {};

            /*
                Declaro una funcion puramente virtual. Esto provoca que no se pueda instanciar un objeto de la clase Base ya que
                no existira el metodo Nombre(), por lo que el programa no sabra a que funcion llamar si se ejecuta este metodo.

                Las funciones puramente virtuales me obligan a redefinir el metodo Nombre() en la clase Derivada para poder instanciar un objeto
                de dicha clase. Si no redefino el metodo, seguire en la misma y tampoco podre instanciar un objeto de la clase Derivada
            */
            virtual void Nombre() = 0;
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