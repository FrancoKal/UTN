#include <iostream>
#include "partida.h"

using namespace std;

int main()
{
    Partida p1, p2("Neuquen", 21), p3(p2);

    cout << p1;
    cout << p2;
    cout << p3;

    return 0;
}
