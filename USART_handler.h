/*
 * USART_handler.h
 *
 * Created: 2018-03-14 13:46:34
 *  Author: albsve-6
 */ 
#include "TinyTimber.h"
#include <avr/io.h>
#ifndef USART_HANDLER_H_
#define USART_HANDLER_H_
#define GREEN 1
#define RED 0


typedef struct{
Object super;
int numberofcarsnorth;
int numberofcarssouth;
int numberofcarsonbridgeNB;
int numberofcarsonbridgeSB;
int northlight;
int southlight;

// red red = 0
// green green = 1
// red green = 2
// green red = 3
	
}USART_handler;

#define initUSART_handler(){initObject(),0,0,1}
int interruptHandler(USART_handler *self, int arg);
void removecar(int carqueue);



#endif /* USART_HANDLER_H_ */