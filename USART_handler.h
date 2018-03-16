


#ifndef USART_handler_H_
#define USART_handler_H_
#include "Tinytimber.h"
#include "controller.h"
typedef struct{
	Object super;
	controller* controller;
	} USART_handler;
	
#define initUSART_handler(controller){initObject()},controller}
void readport(USART_handler* self);	
#endif /* USART_handler_H_ */