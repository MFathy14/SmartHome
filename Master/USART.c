
#include <xc.h>
#include <avr/iom32a.h>
#include <stdlib.h>
#include "USART.h"

void USART_init(char Mode, int BaudRate, char Operation, char TranmSpd, char CharSize, char Interrupt, char Polarity) {

    //               =========DEALING WITH UBRR=========

    UBRRH &= ~(1 << URSEL);
    int rate = (16000000 / 16 / BaudRate) - 1; //BAUD RATE IN PROTUES 9600
    UBRRH |= (rate >> 8);
    UBRRL |= rate;

    //               =========DEALING WITH UCSRC=========
    UCSRC |= (1 << URSEL);
    UCSRC |= (Mode << UMSEL) | (Polarity << UPM0);

    if (CharSize >= 5 && CharSize <= 8) {
        UCSRC |= (CharSize << UCSZ0);
    }
    else if (CharSize == 9) {
        UCSRC |= (3 << UCSZ0);
        UCSRB |= (1 << UCSZ2);
    }

    //               =========DEALING WITH UCSRB=========

    UCSRB |=  (Operation << TXEN) | (Interrupt << UDRIE);

    //               =========DEALING WITH UCSRA=========

    UCSRA |= (TranmSpd << U2X);
}

void TransmitChar(char data) {
    while (!(UCSRA & (1 << UDRE)));
    UDR = data;
}

void TransmitString(char *data) {
    for (int i = 0; data[i] != '\0'; i++) {
        TransmitChar(data[i]);
    }
}

void TransmitInt(int value){
    char buff[20];
    itoa(value,buff,10);
    TransmitString(buff);
}