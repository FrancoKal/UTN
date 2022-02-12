#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/types.h>

#define PROJECT_ID	123     //numero arbitrario para ftok
#define SHM_SIZE    100     //tamaño arbitrario de la shared mem. en bytes

#define LIFE_COUNTER_BASE   0	//offset de la shared memory
#define DATA_HOUR_BASE      4	//offset de la shared memory
#define DATA_MIN_BASE       8	//offset de la shared memory
#define DATA_SEC_BASE       12	//offset de la shared memory

#define SEM1    0			//numero del semaforo que se usara aqui.

// defino las estructuras con las operaciones predefinidas
static struct sembuf giveSem1 = { SEM1, 1, SEM_UNDO };  //intento tomar semáforo
static struct sembuf takeSem1 = { SEM1, -1, SEM_UNDO }; //libero semáforo
/*un puntero a una estructura sembuf es uno de los parámetros de la llamada al sistema semop (int semop (int semid, struct sembuf* sops, unsigned nsops)). Ese puntero puede apuntar a estructuras ailadas, como este caso, o a un array de estructuras sembuf donde cada posición es una "operación" disponible. En caso que apunte a un array, el 3er parámetro es el tamaño del array. En nuestro caso vale 1*/

union sem_union {
  int              val;    /* Value for SETVAL */
  struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
  unsigned short  *array;  /* Array for GETALL, SETALL */
  struct seminfo  *__buf;  /* Buffer for IPC_INFO
                  (Linux-specific) */
};

int main()
{
    key_t key;             // clave del set de recuros obtenida desde ftok()
    int shm_id, sem_id;    // identificador de la shared memory y el set de semáforos
    char *shm_ptr = 0;     // puntero local para acceder a la shared memory
    union sem_union init_sem;  // inicialización de semáforos (se usa con semctl())

    time_t timer;               // variable para obtener el tiempo actual del sistema
    struct tm *current_time;    // variable para convertir el tiempo a formato local
    int life_counter = 0;       // variable para contabilizar los ciclos de escritura

    // genero una clave para el set de recursos system V
    key = ftok("/tmp", PROJECT_ID);
    // crea la shared memory, o pide acceso si ya existe
    shm_id = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget"); 	//sale por aquí en caso de error
        exit(1);
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
    /*inicializo el semáforo. La variable init_sem es de tipo 'union sem_union'. En miembro val es el valor del semaforo*/
    init_sem.val = 1; // disponible
    if (semctl(sem_id, SEM1, SETVAL, init_sem) == -1) {
        perror("semctl"); 	//sale por aquí en caso de error
        exit(1);
    }
    printf(" > semaphore [key=0x%X] [sem_id=%d]\n\n", key, sem_id);

    while (1) {
        /* este loop simula el funcionamiento de un proceso destinado a manejar una
        comunicación con algún otro dispositivo remoto, por ejemplo a través de un
        socket o un puerto serie. Luego de recibir los datos, el proceso se encarga
        de escribir todos los valores actualizados de los parámetros recibidos en la
        SHARED MEMORY para que otros procesos puedan acceder a dichos parámetros.

        NOTA: a modo de ejemplo, cada 1 seg escribe valores nuevos en la shared memory como si fuesen los mensajes recibidos...*/

        //incremento un contador para reflejar la actividad del proceso
        life_counter++;
        if(life_counter >= 0x0FFFFFFF)
            life_counter = 0;
        // obtengo el tiempo actual del sistema como si fuesen parámetros recibidos
        timer = time(NULL);
        
        current_time = localtime(&timer); // convierto el tiempo a formato local

        /* intenta acceder al SEMÁFORO (SEM1) para actualizar con nueva info el bloque de datos de la SHARED MEMORY (SINCRONIZACIÓN)*/
        semop(sem_id, &takeSem1, 1); //toma el SEM1 (bajar(s)/p(s)/down(s)/wait(s))
		//si no lo logra, se bloquea

        // escribo el nuevo valor del contador en la shared memory
        memcpy(shm_ptr+LIFE_COUNTER_BASE, &life_counter, 4);
        // escribo el valor del parámetro horas en la shared memory
        memcpy(shm_ptr+DATA_HOUR_BASE, &(current_time->tm_hour), 4);
        // escribo el valor del parámetro minutos en la shared memory
        memcpy(shm_ptr+DATA_MIN_BASE, &(current_time->tm_min), 4);
        // escribo el valor del parámetro segundos en la shared memory
        memcpy(shm_ptr+DATA_SEC_BASE, &(current_time->tm_sec), 4);

        // libero el SEMÁFORO 1 una vez que terminé de escribir la SHARED MEMORY (SINCRONIZACIÓN)
        semop(sem_id, &giveSem1, 1); //libera el SEM1 (subir(s)/v(s)/up(s)/signal(s))

        printf("\r > life_counter = %d", life_counter);
        fflush(stdout);

        // genero una demora a modo de ejemplo para simular una comunicación con un dispositivo
        usleep(200000);
    }

    /* nunca se llega a este punto. En un ejemplo real, habría que desengancharse de la shared memory usando shmdt(). (DETTACH)*/
    return 0;
}
