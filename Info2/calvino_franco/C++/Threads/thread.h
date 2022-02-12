#ifndef THREAD_H
#define THREAD_H

#define OK 0
#include <pthread.h>

enum pthread_errors {ROUTINE_NOT_SPECIFIED = -1, COULD_NOT_CREATE_THREAD = -2, COULD_NOT_JOIN_THREAD = -3};

class Thread
{
    private:
        pthread_t thread;
        pthread_attr_t *attributes;
        void *arguments;
        void *retval;
        void* (*start_routine) (void*);

    public:
        Thread(void* (*routine) (void*) = nullptr, void* arg = nullptr, pthread_attr_t *attr = nullptr) :
           attributes(attr), arguments(arg), retval(nullptr), start_routine(routine) {};

        ~Thread() {};

        void setRoutine(void *(*routine) (void*)) { if (routine != nullptr) start_routine = routine; }
        void setArguments (void *arg) { if (arg != nullptr) arguments = arg; }
        int startThread();
        int joinThread ();
        void* getThreadResult () { return retval; }
        pthread_t getThreadId () { return thread; }
};

#endif // THREAD_H
