#include "funciones.h"

void burbuja (int **v, int cant);
void escribir (int *v, int cant, FILE *archivo);
int es_primo (int n);

int leer_numeros(FILE *archivo, numeros **v)
{
	numeros buffer, *aux = NULL;
	int i = 0;

	do
	{
		fscanf(archivo, "%i\n%i\n%f", &(buffer.n[0]), &(buffer.n[1]), &buffer.f);

		if (feof(archivo) == 0)
		{
			aux = (i == 0)? (numeros *) malloc (sizeof(numeros)) : (numeros *) realloc (aux, sizeof(numeros) * (i+1));

			if (aux != NULL)
			{
				aux[i] = buffer;
				printf("Registrado: n1 = %i, n2 = %i, f = %f\n", (aux+i)->n[0], (aux+i)->n[1], (aux+i)->f);
				i++;
			}
			else i = ERROR_MEMORIA;
		}
	}
	while (feof(archivo) == 0 && i != ERROR_MEMORIA);
		
	if (i != ERROR_MEMORIA) *v = aux;

	return i;
}

void may_a_men (numeros *v, int cant, FILE *archivo)
{
	int i, *primeros = NULL, *segundos = NULL;
	
	primeros = (int *) malloc (sizeof(int) * cant);
	segundos = (int *) malloc (sizeof(int) * cant);
	
	if (primeros != NULL && segundos != NULL)
	{
		for (i = 0; i < cant; i++)
		{
			primeros[i] = (v+i)->n[0];
			segundos[i] = (v+i)->n[1];
		}

		burbuja(&primeros, cant);
		burbuja(&segundos, cant);
		
		/*for (i = 0; i < cant && estado == CONTINUO; i++)
		{
			estado = FINALIZO;
			
			for (j = 0; j < cant - i; j++)
			{	
				if (primeros[j] < primeros[j+1])
				{
					aux = primeros[j];
					primeros[j] = primeros[j+1];
					primeros[j+1] = aux;
					estado = CONTINUO;
				}
			}
		}*/
		
		fprintf(archivo, "Primeros:\n");
		escribir(primeros, cant, archivo);
		free(primeros);
		
		/*for (i = 0; i < cant && estado == CONTINUO; i++)
		{
			estado = FINALIZO;
			
			for (j = 0; j < cant - i; j++)
			{	
				if (segundos[j] < segundos[j+1])
				{
					aux = segundos[j];
					segundos[j] = segundos[j+1];
					segundos[j+1] = aux;
					estado = CONTINUO;
				}
			}
		}*/
		
		fprintf(archivo, "\nSegundos:\n");
		escribir(segundos, cant, archivo);
		free(segundos);
	}
}

void primos (numeros *v, int cant, FILE *archivo)
{
	int i, j = 0, k, *v_primos = NULL;
	
	for (k = 0; k < 2; k++)
	{
		for (i = 0; i < cant; i++)
		{
			if (es_primo((v+i)->n[k]) == PRIMO) //Junto los dos vectores
			{
				v_primos = (j == 0)? (int *) malloc (sizeof(int)) : (int *) realloc (v_primos, sizeof(int) * (j+1));
				
				if (v_primos != NULL)
				{
					v_primos[j] = (v+i)->n[k];
					j++;
				}
			}
		}
	}
	
	if (v_primos != NULL)
	{
		escribir(v_primos, j, archivo);
		free(v_primos);
	}
}

void escribir (int *v, int cant, FILE *archivo)
{
	int i;

	for (i = 0; i < cant; i++)
	{
		fprintf(archivo, "%i\n", v[i]);
	}
}

int es_primo (int n)
{
	int i, divisores = PRIMO;

	for (i = 2; i <= n/2 && divisores == PRIMO; i++)
	{
		if (n % i == 0) divisores = COMPUESTO;
	}

	return divisores;
}

void burbuja (int **v, int cant)
{
	int aux, estado = CONTINUO, i, j;
	
	for (i = 0; i < cant && estado == CONTINUO; i++)
	{
		estado = FINALIZO;
			
		for (j = 0; j < cant - i; j++)
		{	
			if ((*v)[j] < (*v)[j+1])
			{
				aux = (*v)[j];
				(*v)[j] = (*v)[j+1];
				(*v)[j+1] = aux;
				estado = CONTINUO;
			}
		}
	}
}
