#ifndef INTERRUPTSERVICEROUTINES_H_
#define INTERRUPTSERVICEROUTINES_H_
#include <stdio.h>
#include "motor.h"
#include "UART.h"

// If you're using the TI compiler, comment out this #define statement
#define USING_GNU_COMPILER

// Global variables used within ISRs
extern int strlen(char*);
extern int waiting;
extern int state;
// Interrupt handler for port register 1
#ifdef USING_GNU_COMPILER
__attribute__((interrupt(PORT1_VECTOR)))
#else
#pragma vector = PORT1_VECTOR
__interrupt
#endif
void PORT1_ISR(void)
{

}

// Interrupt handler for port register 2
#ifdef USING_GNU_COMPILER
__attribute__((interrupt(PORT2_VECTOR)))
#else
#pragma vector = PORT2_VECTOR
__interrupt
#endif
void PORT2_ISR(void)
{
}

// Interrupt handler for 10-bit ADC
#ifdef USING_GNU_COMPILER
__attribute__((interrupt(ADC10_VECTOR)))
#else
#pragma vector = ADC10_VECTOR
__interrupt
#endif
void ADC10_ISR(void)
{
}

// Interrupt handler for TX on USCI A and B.
#ifdef USING_GNU_COMPILER
__attribute__((interrupt(USCIAB0TX_VECTOR)))
#else
#pragma vector = USCIAB0TX_VECTOR
__interrupt
#endif
void USCIAB0TX_ISR(void)
{
    IE2 &= ~UCA0TXIE;
}

void waitForTX(){
    while(!(IFG2 & UCA0TXIFG)); // Wait until TXREG is empty
}

void printString(char * s){
    IE2 |= UCA0TXIE;
    char buffer[100];
    sprintf(buffer, s);
    waitForTX();
    for(int i = 0; i < strlen(s); i++){
        UCA0TXBUF = s[i];
        waitForTX();
    }
    IE2 &= ~UCA0TXIE;
}

// Interrupt handler for RX on USCI A and B.
#ifdef USING_GNU_COMPILER
__attribute__((interrupt(USCIAB0RX_VECTOR)))
#else
#pragma vector = USCIAB0RX_VECTOR
__interrupt
#endif
void USCIAB0RX_ISR(void)
{
    char c = UCA0RXBUF;
    if(c == 'A'){
        printString("Buffer test");
    }
    UCA0TXBUF = UCA0RXBUF; // Fill the TXREG with the RXREG...simple echo back
    IFG2 &= ~UCA0RXIFG;

}

// Interrupt handler for Timer0_A CCIFG2, CCIFG1 and TAIFG
#ifdef USING_GNU_COMPILER
__attribute__((interrupt(TIMER0_A1_VECTOR)))
#else
#pragma vector = TIMER0_A1_VECTOR
__interrupt
#endif
void TIMER0_A1_ISR(void)
{
}

// Interrupt handler for Timer0_A CCIFG0
#ifdef USING_GNU_COMPILER
__attribute__((interrupt(TIMER0_A0_VECTOR)))
#else
#pragma vector = TIMER0_A0_VECTOR
__interrupt
#endif
void TIMER0_A0_ISR(void)
{
}

// Interrupt handler for watchdog timer
#ifdef USING_GNU_COMPILER
__attribute__((interrupt(WDT_VECTOR)))
#else
#pragma vector = WDT_VECTOR
__interrupt
#endif
void WDT_ISR(void)
{
}

// Interrupt handler for comparator A
#ifdef USING_GNU_COMPILER
__attribute__((interrupt(COMPARATORA_VECTOR)))
#else
#pragma vector = COMPARATORA_VECTOR
__interrupt
#endif
void COMPARATORA_ISR(void)
{
}

// Interrupt handler for Timer0_A CCIFG2, CCIFG1 and TAIFG
#ifdef USING_GNU_COMPILER
__attribute__((interrupt(TIMER1_A1_VECTOR)))
#else
#pragma vector = TIMER1_A1_VECTOR
__interrupt
#endif
void TIMER1_A1_ISR(void)
{
}

// Interrupt handler for Timer0_A CCIFG0
#ifdef USING_GNU_COMPILER
__attribute__((interrupt(TIMER1_A0_VECTOR)))
#else
#pragma vector = TIMER1_A0_VECTOR
__interrupt
#endif
void TIMER1_A0_ISR(void)
{
}

#endif /* INTERRUPTSERVICEROUTINES_H_ */
