#include <carrera.h>

int main (int argc, char *argv[])
{
    int i, pid, shmid, semid, ganador, *shm_ptr = NULL;
    key_t key;
    union sem_union semaphore;

    printf("Vamos a hacer una cerrera entre hijos!!!\n");

    key = ftok(argv[0], MY_ID);

    if (key == -1)
    {
        perror("ftok");
        exit(1);
    }

    /*  Creacion de memoria compartida  */
    shmid = shmget(key, sizeof(int), IPC_CREAT | PERMISOS);

    if (shmid == -1)
    {
        perror("shmget");
        exit(2);
    }
    /*  ------------------------------- */

    /*  Creacion de semaforo    */
    semid = semget(key, 1, IPC_CREAT | PERMISOS);

    if (semid == -1)
    {
        perror("semget");
        exit(3);
    }

    semaphore.val = 1; //Inicializo en 1 para que solo pueda acceder un proceso al la memoria por vez
    if (semctl(semid, 0, SETVAL, semaphore) == -1)
    {
        perror("semctl");
        exit(3);
    }
    /*  ----------------------  */

    shm_ptr = (int*) shmat(shmid, NULL, 0);

    if (shm_ptr != NULL)
    {
        printf("Shared memory creada con exito. A ver quien llegara primero al semaforo??\n");

        for (i = 0; i < 10; i++)
        {
            pid = fork();

            switch (pid)
            {
                case -1:
                    perror("fork");
                    exit(3);
                    break;
                
                case HIJO:
                    LOCK(semid); //El hijo que primero llegue al semaforo podra continuar, los otros quedaran bloqueados
                    memcpy(shm_ptr, &i, sizeof(int)); //Copio a la shared memory el numero del proceso hijo que llego primero al semaforo

                    return 0;
            }
        }

        printf("Soy el padre, y voy a ser el arbitro de la carrera!!!\n");
        wait(NULL); //Padre espera a que el primer hijo que llego al semaforo termine
        sleep(2);
        memcpy(&ganador, shm_ptr, sizeof(int));
        printf("GANO EL HIJO %i!!!\n", ganador);
    }

    /*  Elimino la shared memory para que los hijos que llegaron despues no puedan escribir */
    if (shmdt(shm_ptr) == -1)
    {
        perror("shmdt");
        exit(4);
    }

    if (shmctl(shmid, IPC_RMID, 0) == -1)
    {
        perror("shmctl");
        exit(5);
    }
    /*  ----------------------------------------------------------------------------------- */

    if (semctl(semid, IPC_RMID, 0) == -1)
    {
        perror("semctl");
        exit(6);
    }

    while (waitpid(-1, NULL, WNOHANG) > 0); //Libero todos los hijos

    return 0;
}