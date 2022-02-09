/** 
 * 
\file BMPopen.c
\brief Leer Header BMP
\details
\author Misael Cudek
  - Informática 1 r1001
  - UTN FRBA
\date 
\version 
\note 
* 
*/

#include <stdio.h>

#define headersize 54

union BMP
	  {
	  char header[headersize];
	  struct
		{	
	      char cTipoFichero[2];
	      char Tamano[4];
	      char reservado1[2];
	      char reservado2[2];
	      char InicioData[4];
	      char TamCabecera[4];
	      char AnchuraImagen[4];
	      char AlturaImagen[4];
	      char NumPlanos[2];
	      char TamPuntos[2];
	      char Comprimido[4];
	      char TamImagen[4];
	      char ResolHoriz[4];
	      char ResolVert[4];
	      char TamTablaColor[4];
	      char ContColorImport[4];
		} BMPStrip;
};

int main(int argc, char ** argv )
{
   union BMP mibmp;
   FILE * fdin= NULL;
   
   printf("%li\n",sizeof(mibmp.header));
   printf("%li\n",sizeof(mibmp.BMPStrip));
   printf("%li\n",sizeof(mibmp));
   
   fdin= fopen(argv[1],"r");
   
   if(fdin==0)
   {printf("Error\n");
   return(1);
   }
   
   printf("Leo archivo %s",argv[1]);
        fread( mibmp.header, headersize, 1, fdin );
		 	 
		printf("\ncTipoFichero %c %c\n",mibmp.BMPStrip.cTipoFichero[0],mibmp.BMPStrip.cTipoFichero[1]);
		printf("El Tamano es %d\n",*(int *)mibmp.BMPStrip.Tamano);
		printf("Los datos inician en el byte InicioData %d\n",*(int *)mibmp.BMPStrip.InicioData);
		printf("El Tamano de la cabecera es es %d\n",*(int *)mibmp.BMPStrip.TamCabecera);
		printf("El Tamano del Ancho de Imagen es %d\n",*(int *)mibmp.BMPStrip.AnchuraImagen);
		printf("El Tamano del Altura de Imagen es %d\n",*(int *)mibmp.BMPStrip.AlturaImagen);
		
        printf("Numero de planos %d\n",*(short int *)mibmp.BMPStrip.NumPlanos);
        printf("Tam. Punto. %d\n",*(short int *)mibmp.BMPStrip.TamPuntos);
        
		printf("La resol horiz es %d\n",*(int *)mibmp.BMPStrip.ResolHoriz);
		printf("La resol verti es %d\n",*(int *)mibmp.BMPStrip.ResolVert);
	
        fclose(fdin);
        return (0); /* indica terminación exitosa */

} /* fin de main */







