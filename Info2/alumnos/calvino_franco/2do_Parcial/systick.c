#include "timer.h"
#include "teclado.h"

void SysTick_IRQHandler (void);

void SysTick_Inic (uint32_t ticks)
{
    if ((ticks - 1) <= 0x00FFFFFF)
        SYSTICK->SYST_RVR = (ticks - 1);

    //Habilito interrupciones
    SYSTICK->SYST_CSR |= (1 << 1);

    //Uso como clock el FRO
    SYSTICK->SYST_CSR |= (1 << 2);

    //Habilito a contar
    SYSTICK->SYST_CSR |= (1 << 0);
}

void SysTick_IRQHandler (void)
{
    AnalizarTimers();
    DriverTeclado();
    BarridoDisplay();
}