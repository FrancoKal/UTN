#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>

#define OK 0

typedef struct 
{
    key_t key;
    int ipc_id;
} IPC_data;

key_t createKey(char *pathname, int proj_id);
