#include "rtc.h"

void InicializoRTC(void)
{
    //Pongo la fecha de hoy (23/11/2021)
    RTC->DATE.BITWISE_DATE.DAY = 23;
    RTC->DATE.BITWISE_DATE.MONTH = 11;
    RTC->DATE.BITWISE_DATE.YEAR = 2021;

    //Habilito pooling (con un 0)
    RTC->CTRL &= ~RTC_POOLING_ENABLE_MASK;

    //Habilito el RTC (con un 1)
    RTC->CTRL |= RTC_ENABLE_MASK;
}