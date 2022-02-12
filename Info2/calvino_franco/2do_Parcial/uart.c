#include "uart.h"

uint8_t rxOutIndex = 0, rxInIndex = 0;
uint8_t txOutIndex = 0, txInIndex = 0;
uint8_t transmitiendo = 0;
uint8_t rxBuffer[RX_BUFFER_SIZE], txBuffer[TX_BUFFER_SIZE];

void USART2_IRQHandler(void);

uint8_t UART2_popRx(void)
{
    uint8_t dato = -1;

    //Si los indices son distintos, es que aun hay datos por sacar del buffer de lectura
    if (rxOutIndex != rxInIndex)
    {
        dato = rxBuffer[rxOutIndex];
        rxOutIndex++;
        rxOutIndex %= RX_BUFFER_SIZE;
    }

    return dato;
}

void UART2_pushRx(uint8_t dato)
{
    rxBuffer[rxInIndex] = dato;
    rxInIndex++;
    rxInIndex %= RX_BUFFER_SIZE;
}

uint8_t UART2_popTx(void)
{
    uint8_t dato = -1;

    //Si los indices son distintos, es que aun hay datos por enviar del buffer de transmision
    if (txOutIndex != txInIndex)
    {
        dato = txBuffer[txOutIndex];
        txOutIndex++;
        txOutIndex %= TX_BUFFER_SIZE;

        //Si no se esta transmitiendo, habilito la interrupcion recien ahora
        if (!transmitiendo)
        {
            transmitiendo = TRUE;

            //Habilito interrupciones para TX ready
            START_TX();
        }
    }

    return dato;
}

void UART2_pushTx (uint8_t dato)
{
    txBuffer[txInIndex] = dato;
    txInIndex++;
    txInIndex %= TX_BUFFER_SIZE;
}

void InicializoUART2(void)
{
    //Que la trama tenga 8 bits de largo
    USART2->CFG |= (0x1 << 2);

    //Que la trama tenga paridad par (even/E)
    USART2->CFG |= (0x2 << 4);

    //2 bits de stop
    USART2->CFG |= (1 << 6);

    //Habilita la uart
    USART2->CFG |= (1 << 0);
}



void USART2_IRQHandler(void)
{
    uint32_t estado = USART2->STAT;
    uint8_t dato;

    //Debo recibir un dato
    if (estado & RX_READY)
    {
        //Guardo el dato
        dato = USART2->RXDAT;

        //Lo guardo en el buffer
        UART2_pushRx(dato);
    }
    
    //Debo enviar un dato
    if (estado & TX_READY)
    {
        //Retiro el ultimo dato del buffer
        dato = UART2_popTx();

        if (dato != -1)
            USART2->TXDAT = dato;
        else END_TX();
    }
}