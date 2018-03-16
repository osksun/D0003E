
#include "USART_handler.h"

void readport(USART_handler* self){
	unsigned int data = UDR0;
	ASYNC(self->controller,USART_receive,data);
}