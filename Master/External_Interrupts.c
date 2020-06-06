#include <xc.h>
#include "External_Interrupts.h"

void INT0_init(int mode) {

    switch (mode) {
        case(LOW_LVL):
            MCUCR &= ~(1 << ISC00);
            MCUCR &= ~(1 << ISC01);
            GICR |= (1 << INT0);
            break;

        case(TOGGLE):
            MCUCR |= (1 << ISC00);
            MCUCR &= ~(1 << ISC01);
            GICR |= (1 << INT0);
            break;

        case(FALLING):
            MCUCR &= ~(1 << ISC00);
            MCUCR |= (1 << ISC01);
            GICR |= (1 << INT0);
            break;

        case(RISING):
            MCUCR |= (1 << ISC00) | (1 << ISC01);
            GICR |= (1 << INT0);
            break;

        default:
#warning "Choose the Modes Between: LOW_LVL, TOGGLE, FALLING or RISING !"
            break;
    }
}

void INT1_init(int mode) {

    switch (mode) {
        case(LOW_LVL):
            MCUCR &= ~(1 << ISC10);
            MCUCR &= ~(1 << ISC11);
            GICR |= (1 << INT1);
            break;

        case(TOGGLE):
            MCUCR |= (1 << ISC10);
            MCUCR &= ~(1 << ISC11);
            GICR |= (1 << INT1);
            break;

        case(FALLING):
            MCUCR &= ~(1 << ISC10);
            MCUCR |= (1 << ISC11);
            GICR |= (1 << INT1);
            break;

        case(RISING):
            MCUCR |= (1 << ISC10) | (1 << ISC11);
            GICR |= (1 << INT1);
            break;

        default:
#warning "Choose the Modes Between: LOW_LVL, TOGGLE, FALLING or RISING !"
            break;
    }

}

void INT2_init(int mode) {

    switch (mode) {
        case(FALLING):
            MCUCR &= ~(1 << ISC2);
            GICR |= (1 << INT2);
            break;

        case(RISING):
            MCUCR |= (1 << ISC2);
            GICR |= (1 << INT2);
            break;

        default:
#warning "Choose the Modes Between: FALLING or RISING !"
            break;
    }
}

/*int led0_state = 0;
int led1_state = 0;
int led2_state = 0;

char str[] = ">> Hallo  MOE <<";

char led0On[]= ">> LED0 is ON <<";
char led1On[]= ">> LED1 is ON <<";
char led2On[]= ">> LED2 is ON <<";
char buzzOn[]= " >>BUZZER";

char led0OFF[]= ">> LED0 is OFF <<";
char led1OFF[]= ">> LED1 is OFF <<";
char led2OFF[]= ">> LED2 is OFF <<";

ISR(INT0_vect) {
    togglePinD(LED2);
}

ISR(INT1_vect) {
    togglePinC(LED1);
}

ISR(INT2_vect) {
    togglePinC(LED0);
}

int main(void) {
    setDDB(2, IN); //Interrupt 2
    setDDD(3, IN); //Interrupt 1
    setDDD(2, IN); //Interrupt 0
    
    
    setDDC(LED0, OUT);
    setDDC(LED1, OUT);
    setDDD(LED2,OUT);
    
    INT0_init(FALLING);
    INT1_init(FALLING);
    INT2_init(FALLING);
    
    sei();
    */