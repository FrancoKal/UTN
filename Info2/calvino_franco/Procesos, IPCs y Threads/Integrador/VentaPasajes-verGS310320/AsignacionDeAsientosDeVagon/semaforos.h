union semun {
    int val;
    struct semid_ds *buf;
    unsigned short  *array;
};

extern struct sembuf p;
extern struct sembuf v;

int InicializarSemaforos( void );
