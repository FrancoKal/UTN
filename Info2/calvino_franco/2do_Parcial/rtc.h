#include <stdint.h>

typedef struct
{
    uint64_t CTRL;  //Es de 64 bits porque el offset de DATE con respecto a CTRL es de 8 bytes
    union
    {
        typedef struct
        {
            uint32_t DAY:5;         //bits 0 a 4
            uint32_t RESERVED0:7;   //bits 5 a 11
            uint32_t MONTH:4;       //bits 12 a 15
            uint32_t YEAR:12;       //bits 16 a 27
            uint32_t RESERVED1:4;   //bits 28 a 31
        } BITWISE_DATE;

        uint32_t BYTEWISE_DATE;
    } DATE;

    uint32_t HOUR;
    uint32_t STATUS;
} RTC_Type;

#define RTC_BASE        0x40024038
#define RTC             ((RTC_Type*) RTC_BASE)

#define RTC_ENABLE_MASK             (1 << 8)
#define RTC_POOLING_ENABLE_MASK     (1 << 30)

void InicializoRTC(void);
