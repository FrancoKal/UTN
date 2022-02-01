#include "timer.h"

uint32_t Timer_Run[N_TIMERS];
void (*Timer_Handler[N_TIMERS])(void);
uint8_t Timer_Base[N_TIMERS];
uint32_t Timer_StandBy[N_TIMERS];
uint32_t Timer_Event[N_TIMERS];

void AnalizarTimers(void)
{
    int i;

    for (i = 0; i < N_TIMERS; i++)
    {
        if (Timer_StandBy[i] == RUNNING)
            Timer_Run[i]--;

        if (Timer_Run[i] == 0)
            Timer_Event[i] = 1;
    }
}

void TimerEvent()
{
    int i;

    for (i = 0; i < N_TIMERS; i++)
    {
        if (Timer_Event[i] == 1)
        {
            if (Timer_Handler[i] != NULL)
                Timer_Handler[i]();

            Timer_Event[i] = 0;
        }
    }
}

void TimerStart(uint8_t evento, uint32_t tiempo, void *handler(void), uint8_t base)
{
    switch (base)
    {
        case DEC:
            tiempo *= DEC;
            break;

        case SEG:
            tiempo *= DEC * SEG;
            break;
            
        case MIN:
            tiempo *= DEC * SEG * MIN;
            break;
    }

    Timer_StandBy[evento] = RUNNING;

    if (tiempo > 0)
    {
        Timer_Run[evento] = tiempo;
        Timer_Event[evento] = 0;
    }
    else if (tiempo == 0)
    {
        Timer_Run[evento] = 0;
        Timer_Event[evento] = 1;
    }
    
    if (handler != NULL)
        Timer_Handler[evento] = handler;
}

void TimerStop(uint8_t evento)
{
    Timer_Run[evento] = 0;
    Timer_StandBy[evento] = RUNNING;
    Timer_Event[evento] = 0;
    Timer_Handler[evento] = NULL;
}