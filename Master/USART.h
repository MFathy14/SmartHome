/* 
 * File:   USART.h
 * Author: H&M
 *
 * Created on May 4, 2020, 2:46 PM
 */

#ifndef USART_H
#define	USART_H

void USART_init(char Mode, int BaudRate, char Operation, char TranmSpd, char CharSize, char Interrupt, char Polarity);

#define Asynchronous    0
#define Synchronous     1

#define Transmit                1
#define Receive                 2
#define TransmitAndReceive      3

#define NormalSpd       0
#define DbleSpd         1

#define CSize_5             0
#define CSize_6             1
#define CSize_7             2
#define CSize_8             3
#define CSize_9             9

#define INTR_DISC         0
#define INTR_UDRE         1
#define INTR_TXC          2
#define INTR_TXCandUDRE   3
#define INTR_RXC          4
#define INTR_RXCandUDRE   5
#define INTR_RXCandTXC    6
#define INTR_ALL          7

#define Disable_Polarity        0
#define Enable_EvenPolarity     2
#define Enable_OddPolarity      3

void TransmitChar(char data);
void TransmitString(char *data);
void TransmitInt(int value);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* USART_H */

