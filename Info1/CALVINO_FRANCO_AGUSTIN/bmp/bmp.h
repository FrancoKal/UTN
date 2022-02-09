#define headersize 54

typedef struct
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
} BMP;

typedef struct {
    char Nombre[2];
    char TamanoArchivo[4];
    char TamanoImagen[4];
    char AnchuraImagen[4];
    char AlturaImagen[4];
} Mi_BMP;