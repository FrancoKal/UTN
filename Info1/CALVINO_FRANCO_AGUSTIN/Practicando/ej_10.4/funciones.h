#include <stdio.h>

enum opciones {VIAJES = 0, ACTUALIZACION = 1, SALIR = 2};
enum errores {ERROR_MEMORIA = -1};

#define REGISTROS_FILENAME "MAESTRO.DAT"
#define NUEVOS_FILENAME "NUEVOS.DAT"
#define LARGO_MAX 60
#define MAX_LINE_SIZE 256
#define OK 0

struct cliente
{
	char *tel, *nombre, *direccion;
	int viajes;
	float importe;
};

typedef struct cliente clientes;

int menu (void);
int ingresar_nuevos (clientes ***nuevos);
int registrar_viajes (clientes ***listado, FILE* archivo);
void escribir_nuevos (clientes **nuevos, int cant_nuevos, clientes **listado, int cant, FILE *archivo);
void liberar_nuevos (clientes ***nuevos, int cant_nuevos);

