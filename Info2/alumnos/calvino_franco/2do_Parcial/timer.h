#include <stdint.h>

#define N_TIMERS    32

#define PAUSED      0
#define RUNNING     1

#define DECENAS     100 //A 1ms, 0,1s = 100*1ms
#define SEGUNDOS    10
#define MINUTOS     60

#define DEC         0
#define SEG         1
#define MIN         2

void AnalizarTimers(void);
void TimerEvent();
void TimerStart(uint8_t evento, uint32_t tiempo, void *handler(void), uint8_t base);
void TimerStop(uint8_t evento);