/**
	\file    Record.c
	\brief   Función principal del programa que se encarga de grabar sonidos.
	\author  Spataro, Hector hspataro@frba.utn.edu.ar
	\date    2019.08.30
	\version 1.1.0
*/


//--------------
//-- Includes --
//--------------

#include <funciones.h>

/**
	\fn      int main(int argc, char ** argv)
	\brief   Función principal para la grabación de archivos a través de la placa de sonido.
	\author  Spataro, Hector hspataro@frba.utn.edu.ar
	\date    2019.08.30
	\param   int argc: Cantidad de parametros que se pasaron por línea de comando
	\param   char ** argv: Vector de punteros a string que apunta a los parámetros pasados por línea de comando.
	\return  salida: Codigo de finalización de la función:
		 0: Todo bien
	 	 1: Error en los argumentos de la línea de comando
		 2: No pudo abrir el archivo a reproducir
		 3: No pudo abrir el dispositivo de audio
		 4: No pudo leer el dispositivo de audio
		 5: No pudo escribir en el archivo a grabar
*/

int main(int argc, char ** argv)
{

	FILE * origfd;      /* Archivo raw file descriptor*/
	FILE * destfd;      /* Archivo raw file descriptor*/
	int status;	/* return status de system calls */

	audio_params config = {{'I','M','F'},RATE, SIZE, CHANNELS};
	int buffsize;
	int salida = 0, i;
	int orig = 0;
	int dest = 0;

 	unsigned char * buf = NULL;

	/*Controlamos los argumentos*/
	if ((argc > 1) && (argc < 7))
	{
		for (i=1; i<argc; i++)
		{
			if((*(*(argv+i)) == '-') && (*(*(argv+i)+1) == 'r'))
				config.v_muestreo = atoi((*(argv+i)+2));
			else if((*(*(argv+i)) == '-') && (*(*(argv+i)+1) == 's'))
				config.t_muestra = atoi((*(argv+i)+2));
			else if((*(*(argv+i)) == '-') && (*(*(argv+i)+1) == 'c'))
				config.c_canales = atoi((*(argv+i)+2));
			else if((*(*(argv+i)) == '-') && (*(*(argv+i)+1) == 'o'))
				orig = i;
			else if((*(*(argv+i)) == '-') && (*(*(argv+i)+1) == 'd'))
				dest = i;
			else salida = 1; 
		}

		/* bufer para el audio */
		buffsize = MSEG*config.v_muestreo*config.t_muestra*config.c_canales/BITS/MILI;
	 	buf = (unsigned char *) malloc(buffsize);
	}
	else
	{
		salida = 1;
	}

	if ((!orig) || (salida) || (!dest))
	{
		printf ("Argumentos erroneos\nUso: %s -o[filename] -d[filename] <-rRATE> <-sSIZE> <-cCHANNELS>\n",argv[0]);
		salida = 1;
	}

	if(!salida)
	{
		/*Creamos el archivo de audio. Si no existe lo creamos. Y si existe lo truncamos*/
		if (!(destfd = fopen(argv[dest]+2, "w")))
		{
		  	fprintf(stderr,"Error en función open\n"); 
			salida = 2;
		}
		if (!(origfd = fopen(argv[orig]+2, "r")))
		{
		  	fprintf(stderr,"Error en función open\n"); 
			salida = 2;
		}
	}

	if (!salida)
	{

		fread(&config, 1, sizeof(config), origfd);

		while ((!salida)&&(!feof(origfd)))
		{ /* Si no hay error en la lectura o grabación se termina con Control-C */

			/*La siguiente función bloquea al proceso hasta que se llene el buffer. Esto con archivos comunes 
			no se nota, pero con un dispositivo de audio en donde se leen 8000 muestras por segundo.....*/

			status = fread(buf, 1, buffsize, origfd); /* lee */

			if (status < 0)
			{
				fprintf(stderr,"Error en función read, Código de error: %s\n",strerror (status));
				salida = 4;
			}

			if (!salida)
			{

				status = fwrite(buf, 1, buffsize, destfd); /* reproduce */
				if (status != buffsize)
				{
					fprintf(stderr,"Error en función write, Código de error: %s\n",strerror (status)); 
					salida = 5;
				}
			}
		}
	}

	if ((salida > 2)||(salida = 0))
	{
		 fclose(destfd);
		 fclose(origfd);
	}

	if (buf) free (buf);
	return salida;
}







