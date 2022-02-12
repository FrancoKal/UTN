#include "thread.h"

int Thread::startThread()
{
    int result = OK;

    if (start_routine != nullptr)
    {
        if (pthread_create(&thread, attributes, start_routine, arguments) != 0)
            result = COULD_NOT_CREATE_THREAD;
    }
    else result = ROUTINE_NOT_SPECIFIED;

    return result;
}

int Thread::joinThread()
{
    return pthread_join(thread, &retval) == 0 ? OK : COULD_NOT_JOIN_THREAD;
}
