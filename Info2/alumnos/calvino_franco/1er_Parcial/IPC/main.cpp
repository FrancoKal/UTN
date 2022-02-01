#include <iostream>
#include "shmem.h"

using namespace std;

int main(int argc, char *argv[])
{
    ShMem mem(argv[0], (char) argc);
    return 0;
}
