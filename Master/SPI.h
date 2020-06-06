/* 
 * File:   SPI.h
 * Author: H&M
 *
 * Created on May 17, 2020, 3:16 PM
 */

#ifndef SPI_H
#define	SPI_H

void SPI_Init(char Mode, char SPI_Interrupt, char SCK_Freq);

#define SLAVE       0
#define MASTER      1

#define SCK_F_4      0
#define SCK_F_16     1
#define SCK_F_64     2
#define SCK_F_128    3

#define SS      4
#define MOSI    5
#define MISO    6
#define SCK     7

void SPI_Write_Char(char data);
void SPI_Write_String(char* data);

char SPI_Read_Char(void);
void SPI_Read_String(char* data);

void Comp_Instr(char* buffer);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* SPI_H */

/*              MASTER
 * char start[]="HALLO MOE!";
char ReceivedByte;

ISR(USART_RXC_vect){
   ReceivedByte = UDR;
   SPI_Write_Char(ReceivedByte);
   UCSRA &= ~(1<<RXC);
}

int main(void) {
   
    USART_init(Asynchronous, 9600, TransmitAndReceive, NormalSpd, CSize_8, INTR_RXC, Disable_Polarity);
    SPI_Init(MASTER, 0, SCK_F_128);
    sei();
    SPI_Write_Char('>');
    TransmitString(start);
    while (1) {
        
    }
    return 0;
 * 
 *              SLAVE
 * ISR(SPI_STC_vect){
    char Rec = SPDR;
    TransmitChar(Rec);
    SPSR &= ~(1<<SPIF);
}


int main(){
    
    USART_init(Asynchronous, 9600, Transmit, NormalSpd, CSize_8, INTR_DISC, Disable_Polarity); //GIF should be cleared for INterrupt driven USART operation ????
    SPI_Init(SLAVE, 1, SCK_F_128);
    
    sei();
    while(1){
    }
}
}*/