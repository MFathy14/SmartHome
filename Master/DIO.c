/*
 * File:   DIO.c
 * Author: H&M
 *
 * Created on April 12, 2020, 8:35 PM
 */


#include <xc.h>

void PortAas(int dir){
    if(dir = 1){
        DDRA = 0b11111111;
    }
    else if (dir = 0){
        DDRA = 0b00000000; 
    }
}
void PortBas(int dir){
    if(dir = 1){
        DDRB = 0b11111111;
    }
    else if (dir = 0){
        DDRB = 0b00000000; 
    }
}
void PortCas(int dir){
    if(dir = 1){
        DDRC = 0b11111111;
    }
    else if (dir = 0){
        DDRC = 0b00000000; 
    }
}
void PortDas(int dir){
    if(dir = 1){
        DDRD = 0b11111111;
    }
    else if (dir = 0){
        DDRD = 0b00000000; 
    }
}

void PortAequal(char data){
    PORTA = data;
}
void PortBequal(char data){
     PORTB = data;
}
void PortCequal(char data){
     PORTC = data;
}
void PortDequal(char data){
     PORTD = data;
}

void setPortA_Pin(int num) {
    if (num >= 0 && num <= 7) {
        PORTA |= (1 << num);
    } else {
#warning "Wrong Argument, the Pins values are between 0 and 7, inclusively"
    }
}

void setPortB_Pin(int num) {
    if (num >= 0 && num <= 7) {
        PORTB |= (1 << num);
    } else {
#warning "Wrong Argument, the Pins values are between 0 and 7, inclusively"
    }
}

void setPortC_Pin(int num) {
    if (num >= 0 && num <= 7) {
        PORTC |= (1 << num);
    } else {
#warning "Wrong Argument, the Pins values are between 0 and 7, inclusively"
    }
}

void setPortD_Pin(int num) {
    if (num >= 0 && num <= 7) {
        PORTD |= (1 << num);
    } else {
#warning "Wrong Argument, the Pins values are between 0 and 7, inclusively"
    }
}

void resetPortA(int num) {

    if (num >= 0 && num <= 7) {
        PORTA &= ~(1 << num);
    } else {
#warning "Wrong Argument, the Pins values are between 0 and 7, inclusively"
    }
}

void resetPortB(int num) {
    if (num >= 0 && num <= 7) {
        PORTB &= ~(1 << num);
    } else {
#warning "Wrong Argument, the Pins values are between 0 and 7, inclusively"
    }
}

void resetPortC(int num) {
    if (num >= 0 && num <= 7) {
        PORTC &= ~(1 << num);
    } else {
#warning "Wrong Argument, the Pins values are between 0 and 7, inclusively"
    }
}

void resetPortD(int num) {
    if (num >= 0 && num <= 7) {
        PORTD &= ~(1 << num);
    } else {
#warning "Wrong Argument, the Pins values are between 0 and 7, inclusively"
    }
}

void setDDA(int num, int dir) {
    switch (dir) {

        case(0):
            DDRA &= ~(1 << num);
            break;

        case(1):
            DDRA |= (1 << num);
            break;

        default:
#warning "Wrong Argument, the Direction is whether IN or OUT !"
            break;
    }
}

void setDDB(int num, int dir) {
    switch (dir) {

        case(0):
            DDRB &= ~(1 << num);
            break;

        case(1):
            DDRB |= (1 << num);
            break;

        default:
#warning "Wrong Argument, the Direction is whether IN or OUT !"
            break;
    }
}

void setDDC(int num, int dir) {
    switch (dir) {

        case(0):
            DDRC &= ~(1 << num);
            break;

        case(1):
            DDRC |= (1 << num);
            break;

        default:
#warning "Wrong Argument, the Direction is whether IN or OUT !"
            break;
    }
}

void setDDD(int num, int dir) {
    switch (dir) {

        case(0):
            DDRD &= ~(1 << num);
            break;

        case(1):
            DDRD |= (1 << num);
            break;

        default:
#warning "Wrong Argument, the Direction is whether IN or OUT !"
            break;
    }
}

int isPressedA(int num) {
    
    if(num >=0 && num <= 7){
        if (PINA & (1 << num)) {
            return 1;
        } else {
            return 0;
        }
    }
    else{
        #warning "Wrong Argument, the Pins values are between 0 and 7, inclusively"
        return -1;
    }
}

int isPressedB(int num) {
    
    if(num >=0 && num <= 7){
        if (PINB & (1 << num)) {
            return 1;
        } else {
            return 0;
        }
    }
    else{
        #warning "Wrong Argument, the Pins values are between 0 and 7, inclusively"
        return -1;
    }
}

int isPressedC(int num){
    
    if(num >=0 && num <= 7){
        if (PINC & (1 << num)) {
            return 1;
        } else {
            return 0;
        }
    }
    else{
        #warning "Wrong Argument, the Pins values are between 0 and 7, inclusively"
        return -1;
    }
}

int isPressedD(int num) {
    
    if(num >=0 && num <= 7){
        if (PIND & (1 << num)) {
            return 1;
        } else {
            return 0;
        }
    }
    else{
        #warning "Wrong Argument, the Pins values are between 0 and 7, inclusively"
        return -1;
    }
}

void togglePinA(int num){
    PORTA ^= (1<<num);
}
void togglePinB(int num){
    PORTB ^= (1<<num);
}
void togglePinC(int num){
    PORTC ^= (1<<num);
}
void togglePinD(int num){
    PORTD ^= (1<<num);
}
