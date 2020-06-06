/*
 * File:   Board_Config.c
 * Author: H&M
 *
 * Created on April 13, 2020, 2:04 PM
 */


#include <avr/io.h>
#include "DIO.h"
#include "Board_Config.h"
void BuzzerOn(void){
    setDDA(BUZZER,OUT);
    setPortA_Pin(BUZZER);
}
void BuzzerOff(void){
    resetPortA(BUZZER);
}

void RelayOn(void){
    setDDA(RELAY,OUT);
    setPortA_Pin(RELAY);
}
void RelayOff(void){
    resetPortA(RELAY);
}
