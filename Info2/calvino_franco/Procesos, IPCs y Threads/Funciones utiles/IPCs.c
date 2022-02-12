#include "IPCs.h"

key_t createKey (char *pathname, int proj_id)
{
    key_t key = ftok(pathname, proj_id);;

    if (key == -1)
    {
        perror("ftok");
        exit(1);
    }

    return key;
}

