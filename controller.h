/*
 * USART_handler.h
 *
 * Created: 2018-03-14 13:46:34
 *  Author: albsve-6
 */ 
#include "TinyTimber.h"
#include <avr/io.h>
#ifndef controller_H_
#define controller_H_
#define GREEN 1
#define RED 0


typedef struct{
Object super;
int NBcarq;
int SBcarq;
int SBcarsonbridge;
int NBcarsonbridge;
int carlimit; // limit of cars passing the bridge on 1 side to prevent starvation
int passedcars;
int direction; // NB = 1 , SB = 0;

}controller;

#define initcontroller(){initObject(),0,0,1,8,0,1}

int USART_receive(controller* self, UDR0);
void USART_transmit(controller* self,UDR0);

void NBremovecar(controller* self);
void SBremovecar(controller* self);
void NBaddcar(controller* self);
void SBaddcar(controller* self);
void NBaddcaronbridge(controller* self);
void SBaddcaronbridge(controller* self);
void NBremovecaronbridge(controller* self);
void SBremovecaronbridge(controller* self);
void checkdirection(controller* self);

void updatetrafficlight(controller* self);



#endif /* controller_H_ */