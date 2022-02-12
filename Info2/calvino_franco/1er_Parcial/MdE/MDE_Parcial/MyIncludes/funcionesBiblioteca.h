#ifndef FUNCIONESBIBLIOTECA_H
#define FUNCIONESBIBLIOTECA_H

#define OFF		0
#define ON		1
#define FALSE   0
#define TRUE    1

enum baseTiempo {DEC = 0, SEG = 1, MIN = 2};
enum relays {RELAY0 = 0, RELAY1 = 1, RELAY2 = 2};
enum entradas {IN0 = 0, IN1 = 1, IN2 = 2};
enum uart {UART0 = 0, UART1 = 1};
enum leds {ROJO = 0, VERDE = 1, AZUL = 2};

typedef short int int16_t;
typedef unsigned char uint8_t;
typedef short unsigned int uint16_t;
typedef void (*Timer_handler)(void);
typedef unsigned char timer_t;

void Inicializacion(void);
uint8_t Entradas(uint8_t);
void Relays(uint8_t, uint8_t);
void TimerStart(uint8_t, timer_t, void (*handler)(void), uint8_t);
void TimerStop (uint8_t);
void TimerEvent(void);
void LedsRGB(uint8_t, uint8_t);
void Buzzer(uint8_t);
int16_t UART_PopRX(uint8_t);
int16_t Transmitir (const void*, uint8_t);
int16_t Potenciometro (void);
int16_t Temperatura (void);
int16_t ADC_Externa (void);

//#define Recibir (x) ((x == UART0)? (UART_PopRX(UART0)) : (UART_PopRX(UART1)))
#define Recibir() (UART_PopRX(UART0))

#endif
