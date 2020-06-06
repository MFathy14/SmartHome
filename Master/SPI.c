
#include <xc.h>
#include <string.h>
#include "SPI.h"
#include "DIO.h"
#include "Board_Config.h"
extern char dataString[] ;
extern char datachar  ;

void SPI_Init(char Mode, char SPI_Interrupt, char SCK_Freq) {

    if (Mode == MASTER) {
        DDRB |= (1 << SS) | (1 << MOSI) | (1 << SCK);
    } else if (Mode == SLAVE) {
        DDRB |= (1 << MISO);
    }

    SPCR |= (1 << SPE) | (Mode << MSTR) | (SPI_Interrupt << SPIE) | (SCK_Freq << SPR0);
}

void SPI_Write_Char(char data) {
    SPDR = data;
    while (!(SPSR & (1 << SPIF)));
}

void SPI_Write_String(char* data) {
    for (int i = 0; data[i] != '\0'; i++) { //HERE
        SPI_Write_Char(data[i]);
    }
}

char SPI_Read_Char(void) {
    //while (!(SPSR & (1 << SPIF)));
    datachar = SPDR;
    return datachar;
}

void SPI_Read_String(char* buffer) {
    for (int i = 0; buffer[i] != '\0'; i++) {
        buffer[i] = SPI_Read_Char();
    }
}

void Comp_Instr(char* buffer) {
  
    if (strcmp(buffer, "LED 1 ON") == 0) { 
        setPortC_Pin(LED1);
    } else if (strcmp(buffer, "LED 0 ON") == 0) {
        setPortC_Pin(LED0);
    } else if (strcmp(buffer, "LED 2 ON") == 0) {
        setPortD_Pin(LED2);
    }
    else if (strcmp(buffer, "LED 1 OFF") == 0) {
        resetPortC(LED1);
    } else if (strcmp(buffer, "LED 0 OFF") == 0) {
        resetPortC(LED0);
    } else if (strcmp(buffer, "LED 2 OFF") == 0) {
        resetPortD(LED2);
    }
}