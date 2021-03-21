#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int filas,columnas;
    float ** mat;
} matriz_st;


matriz_st * inicializar_matriz(int filas,int columnas);
int imprimir_matriz(matriz_st * matriz);
int rellenar_matriz(matriz_st * matriz);
int liberar_matriz (matriz_st ** matriz);
matriz_st * sumar_matrices(matriz_st * A, matriz_st * B, matriz_st * C);
matriz_st * sumar_matrices_nueva(matriz_st * A, matriz_st * B);

int main (void) {
    matriz_st * mat_a,* mat_b,* mat_c,* mat_d;

    srand(time(NULL));    

    mat_a = inicializar_matriz(3,3);
    mat_b = inicializar_matriz(3,3);
    mat_d = inicializar_matriz(3,3);
    
    if (mat_a==NULL || mat_b==NULL) {
        fprintf(stderr,"Error al crear matriz\n");
        return 1;
    }
    
    rellenar_matriz(mat_a);
    rellenar_matriz(mat_b);

    printf("--- Matriz A -------------------\n");
    imprimir_matriz(mat_a);
    printf("--------------------------------\n\n");

    printf("--- Matriz B -------------------\n");
    imprimir_matriz(mat_b);
    printf("--------------------------------\n\n");

    mat_c = sumar_matrices_nueva(mat_a,mat_b);
    
    printf("--- Matriz C = A+B -------------\n");
    imprimir_matriz(mat_c);
    printf("--------------------------------\n\n");


    sumar_matrices(mat_a,mat_b,mat_d);

    printf("--- Matriz D = A+B -------------\n");
    imprimir_matriz(mat_d);
    printf("--------------------------------\n\n");


    liberar_matriz(&mat_a);
    liberar_matriz(&mat_b);
    liberar_matriz(&mat_c);
    liberar_matriz(&mat_d);

    return 0;
}

/***********************************************************/
matriz_st * inicializar_matriz(int filas,int columnas) {
    int i,j;
    matriz_st * matrix;

    //reservo memoria dinámica para la estructura
    matrix = (matriz_st*) malloc(sizeof(matriz_st));
    if (matrix ==NULL)
        return NULL;

    matrix->filas = filas;
    matrix->columnas = columnas;

    //reservo memoria dinamica, para los datos

    matrix->mat = (float**) malloc(sizeof(float*)*filas);
    if (matrix->mat == NULL) {
        free(matrix);
        return NULL;
    }
    
    for (i=0;i<filas;i++) {
        matrix->mat[i] = (float*) malloc(sizeof(float)*columnas);
        if (matrix->mat[i] ==NULL) {
            for(j=0;j<i;j++) {
                free(matrix->mat[j]);
            }
            free(matrix->mat);
            free(matrix);
            matrix=NULL;
            return NULL;
        }
    }

    return matrix;

}
/***********************************************************/
int imprimir_matriz(matriz_st * matriz) {
    int i,j;

    if (matriz==NULL)
        return 1;

    for (i=0;i<matriz->filas;i++) {
        for (j=0;j<matriz->columnas;j++) {
            printf("%5.1f",matriz->mat[i][j]); 
        }
        printf("\n");
    }

    return 0;
}
/***********************************************************/
int rellenar_matriz(matriz_st * matriz) {
    int i,j;

    if (matriz==NULL)
        return 1;



    for (i=0;i<matriz->filas;i++) {
        for(j=0;j<matriz->columnas;j++) {
//            matriz->mat[i][j] = rand()%10 - 5;
            matriz->mat[i][j] = rand()/(float)RAND_MAX*10 - 5;
        }
    }

    return 0;
}

/***********************************************************/
int liberar_matriz (matriz_st ** matriz) {
    int i;

    if (matriz==NULL) 
        return 1;

    for(i=0;i<(*matriz)->filas;i++) {
        free((*matriz)->mat[i]);
    }
    free((*matriz)->mat);
    free((*matriz));

    return 0;
}
/***********************************************************/
matriz_st * sumar_matrices_nueva(matriz_st * A, matriz_st * B){
    int i,j;
    matriz_st * C;

    if (A==NULL || B==NULL) 
        return NULL;

    if (A->filas != B->filas || A->columnas != B->columnas)
        return NULL;

    C = inicializar_matriz(A->filas,A->columnas);
    if (C==NULL)
        return NULL;

    for (i=0;i<C->filas;i++) {
        for (j=0;j<C->columnas;j++){
            C->mat[i][j] = A->mat[i][j] + B->mat[i][j];
        }
    }
    
    return C;
}
/***********************************************************/

matriz_st * sumar_matrices(matriz_st * A, matriz_st * B, matriz_st * C){
    int i,j;

    if (A==NULL || B==NULL || C==NULL) 
        return NULL;

    if (A->filas != B->filas || A->columnas != B->columnas)
        return NULL;

    if (A->filas != C->filas || A->columnas != C->columnas)
        return NULL;

    for (i=0;i<C->filas;i++) {
        for (j=0;j<C->columnas;j++){
            C->mat[i][j] = A->mat[i][j] + B->mat[i][j];
        }
    }
    
    return C;
}
/***********************************************************/




