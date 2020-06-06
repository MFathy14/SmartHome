/*
 * File:   main.c
 * Author: H&M
 *  LAB1 MASTER
 * Created on April 12, 2020, 2:04 PM
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Board_Config.h"
#include "DIO.h"
#include "External_Interrupts.h"
#include "ADC.h"
#include "SPI.h"
#include "USART.h"


ISR(USART_RXC_vect) {
    
    SPI_Write_Char(UDR);
    UCSRA &= ~(1<<RXC);
}


int main(void) {

    USART_init(Asynchronous, 9600, Receive, NormalSpd, CSize_8, INTR_RXC, Disable_Polarity);
    SPI_Init(MASTER, 0, SCK_F_128);

    sei();

    while (1) {

    }
    return 0;
}

