#include <stdint.h>

#define FALSE           0
#define TRUE            1

#define RX_BUFFER_SIZE  256
#define TX_BUFFER_SIZE  256

#define RX_READY    (1 << 0)
#define TX_READY    (1 << 2)

#define START_TX()  (USART2->INTENSET |= (1 << 2))
#define END_TX()    (USART2->INTENCLR |= (1 << 2))

uint8_t UART2_popRx(void);
void UART2_pushRx(uint8_t);
uint8_t UART2_popTx(void);
void UART2_pushTx (uint8_t);
void InicializoUART2(void);