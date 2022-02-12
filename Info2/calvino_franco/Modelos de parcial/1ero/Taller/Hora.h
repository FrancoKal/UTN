#ifndef HORA_H
#define HORA_H

#include <iostream>

using namespace std;

class Hora
{
    private:
        int hora, min;

        void addMinutes (int m = 1);
        void addHours (int h = 1);

    public:
        /*Hora() : hora(0), min(0) {};
        Hora(int h, int m = 0) : hora(h), min(m) {};*/
        Hora(int h = 0, int m = 0) { setTime(h, m); }
        ~Hora() {};

        void setTime(int, int);

        friend ostream& operator<< (ostream&, Hora&);

};

#endif