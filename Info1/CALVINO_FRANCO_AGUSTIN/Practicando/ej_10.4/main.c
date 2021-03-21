#include "funciones.h"
#include <stdlib.h>

/*	El archivo MAESTRO.DAT tiene los registros de todos los clientes acumulados (es decir, importe total y viajes totales).
	En el archivo NUEVOS.DAT se ecuentran los viajes recientemente realizados.
	Con la opcion 'VIAJES' (0) registro los nuevos viajes en el archivo NUEVOS.DAT. Con 'Actualizacion' (1), actualizo el archivo MAESTRO.DAT, añadiendo a cada cliente los viajes de NUEVO.DAT. 		En caso de que un cliente supere los 10 viajes, el siguiente es gratis y su ultimo importe sera $0 */

int main (void)
{
	clientes **listado = NULL, **nuevos = NULL;
	FILE *archivo = NULL;
	int opcion, cant, cant_nuevos;

	do
	{
		opcion = menu();

		switch (opcion)
		{
			case VIAJES:
				cant_nuevos = ingresar_nuevos(&nuevos);
				
				if (cant_nuevos > 0)
				{
					archivo = fopen(REGISTROS_FILENAME, "r");

					if (archivo != NULL)
					{
						cant = registrar_viajes(&listado, archivo);
						fclose(archivo);
						printf("Se leyeron %i registros\n", cant);
						archivo = fopen(NUEVOS_FILENAME, "w");

						if (archivo != NULL)
						{
							escribir_nuevos(nuevos, cant_nuevos, listado, cant, archivo);
							fclose(archivo);
						} 
						
					}
				}
				
				break;
				
			/*case ACTUALIZACION:
				archivo = fopen(REGISTROS_FILENAME, "r+");
				
				if (archivo != NULL)
				{
					if (cant_nuevos > 0 && nuevos != NULL)
					{
						cant = actualizar(nuevos, cant_nuevos, archivo);
					}
					
					fclose(archivo);
				}
				
				break;*/
				
		}


	}
	while (opcion != SALIR);
	
	if (nuevos != NULL) liberar_nuevos(&nuevos, cant_nuevos);

	return 0;
}
