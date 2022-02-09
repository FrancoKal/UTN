#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "PinPumPam"
#define FILE_NAME "resultados.bin"

typedef struct data
{
	int pid;
	char productos[32];
	int cantVendida;
} dato;
