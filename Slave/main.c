/*
 * File:   main.c
 * Author: H&M
 *  LAB4 SLAVE
 * Created on May 1, 2020, 11:32 AM
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Board_Config.h"
#include "DIO.h"
#include "USART.h"
#include "SPI.h"


char buffer[10];


ISR(SPI_STC_vect) {

    static int counter = 0;
    if (SPDR != 13) {
        buffer[counter++] = SPDR;
    }
    else {
        Comp_Instr(buffer);
        counter = 0;
        buffer[8] = 0;
    }
    TransmitChar(SPDR);
    SPSR &= ~(1 << SPIF);
}

int main() {

    USART_init(Asynchronous, 9600, Transmit, NormalSpd, CSize_8, INTR_DISC, Disable_Polarity);
    SPI_Init(SLAVE, 1, SCK_F_128);
    setDDC(LED0, OUT);
    setDDC(LED1, OUT);
    setDDD(LED2, OUT);
    sei();
    while (1) {
    }
}