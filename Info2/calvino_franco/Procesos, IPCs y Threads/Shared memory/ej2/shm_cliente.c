#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/types.h>

#define PROJECT_ID	123		//numero arbitrario para ftok
#define SHM_SIZE    100		//tamaño arbitrario de la shared mem. en bytes

#define SEM1    0			//numero del semaforo que se usara aqui.

// defino las estructuras con las operaciones predefinidas
static struct sembuf giveSem1 = { SEM1, 1, SEM_UNDO };		//intento tomar semáforo
static struct sembuf takeSem1 = { SEM1, -1, SEM_UNDO };		//libero semáforo
/*un puntero a una estructura sembuf es uno de los parámetros de la llamada al sistema semop (int semop (int semid, struct sembuf* sops, unsigned nsops)). Ese puntero puede apuntar a estructuras ailadas, como este caso, o a un array de estructuras sembuf donde cada posición es una "operación" disponible. En caso que apunte a un array, el 3er parámetro es el tamaño del array. En nuestro caso vale 1*/

int main()
{
    key_t key;          // clave del set de recuros obtenida desde ftok()
    int shm_id, sem_id; // identificador de la shared memory y el set de semáforos
    char* shm_ptr = 0;  // puntero local para acceder a la shared memory

    int data[4];        /* array para guardar los datos leídos de la shared memory. En nuestro ejemplo son solo 4 enteros*/

    // genero una clave para el set de recursos system V
    key = ftok("/tmp", PROJECT_ID);
    // crea la shared memory, o pide acceso si ya existe
    shm_id = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget"); 	//sale por aquí en caso de error
    }
    // vincula el puntero local con la shared memory (operación ATTACH)
    shm_ptr = (char *) shmat(shm_id, NULL, 0); //NULL y 0 valores por defecto
    if (shm_ptr == NULL) {
        perror("shmat"); 	//sale por aquí en caso de error
        exit(1);
    }
    printf(" > shared memory [key=0x%X] [shm_id=%d] [ptr=%p]\n", key, shm_id, (void *)shm_ptr);

    // crea un set de semáforos (1 semáforo sólo en este caso)
    sem_id = semget(key, 1, IPC_CREAT | 0666);
    if (sem_id == -1) {
        perror("semget"); 	//sale por aquí en caso de error
        exit(1);
    }
    printf(" > semaphore [key=0x%X] [sem_id=%d]\n\n", key, sem_id);

    while (1) {

        /* intenta acceder al SEMÁFORO (SEM1) para leer el bloque de datos de la SHARED MEMORY (SINCRONIZACIÓN)*/
        semop(sem_id, &takeSem1, 1); //toma el SEM1 (bajar(s)/p(s)/down(s)/wait(s))
		//si no lo logra, se bloquea

        //leo los datos de la SHARED MEMORY (4 variables 'int' en este ej., 16 bytes)
        memcpy(data, shm_ptr, 16);

        // libero el SEMÁFORO 1 una vez que terminé de leer la SHARED MEMORY (SINCRONIZACIÓN)
        semop(sem_id, &giveSem1, 1);//libera el SEM1 (subir(s)/v(s)/up(s)/signal(s))
		
        // imprimo los valores en pantalla
        printf("\r > counter = %06d  /  HOUR = %02d : MIN = %02d : SEC = %02d", data[0], data[1], data[2], data[3]);
        fflush(stdout);

        // genero una demora a modo de ejemplo
        // (podría ser la actualización de una interfaz de usuario o algún tipo de procesamiento)
        sleep(1);
    }

    /* nunca se llega a este punto. En un ejemplo real, habría que desengancharse de la shared memory usando shmdt(). (DETTACH)*/
    return 0;
}
