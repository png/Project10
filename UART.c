#include <msp430.h>
#include "UART.h"

void InitializeUART(){
    P1SEL = BIT1 | BIT2;
    P1SEL2 = BIT1 | BIT2;

    UCA0CTL1 = UCSWRST;

    UCA0CTL1 |= UCSSEL_2;
    UCA0BR0 = 104;
    UCA0BR1 = 0;
    UCA0MCTL = UCBRS0;

    UCA0CTL1 &= ~UCSWRST;

    IE2 |= UCA0RXIE;
    IE2 |= UCA0TXIE;

//    __bis_SR_register(LPM0_bits + GIE);

//    UCA0TXBUF = 'A';

}

void DisableUART(){
    P1SEL &= ~BIT1;
    P1SEL &= ~BIT2;
    P1SEL2 &= ~BIT1;
    P1SEL2 &= ~BIT2;
}

void EnableUART(){
    P1SEL = BIT1 | BIT2;
    P1SEL2 = BIT1 | BIT2;
}

//__interrupt void USCI0RX_ISR(void){
//    while(!(IFG2&UCA0TXIFG)){
//        UCA0TXBUF = UCA0RXBUF;
//    }
//}
