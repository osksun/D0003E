/*
 * controller.c
 *
 * Created: 2018-03-15 14:03:54
 *  Author: osksun-6
 */ 
/*
 * USART_handler.c
 *
 * Created: 2018-03-14 13:46:17
 *  Author: albsve-6
 */ 

#include "controller.h"
#include "tinytimber.h"
#include <unistd.h>

// int numberofcarsnorth;
// int numberofcarssouth;
// int numberofcarsonbridgeNB;
// int numberofcarsonbridgeSB;

// red red = 0
// green green = 1
// red green = 2
// green red = 3

void USART_transmit(controller* self, unsigned int data){
	UDR0 = data;
}
void NBremovecar(controller* self){
	self->NBcarq--;
	
}
void SBremovecar(controller* self){
	self->SBcarq--;
}

void NBaddcar(controller* self){
	self->NBcarq++;
}
void SBaddcar(controller* self){
	self->SBcarq++;
}
void NBaddcaronbridge(controller* self){
	self->NBcarsonbridge++;
	self->passedcars++;
}
void SBaddcaronbridge(controller* self){
	self->SBcarsonbridge++;
	self->passedcars++;
}
void NBremovecaronbridge(controller* self){
	self->NBcarsonbridge--;
	self->passedcars--;
}
void SBremovecaronbridge(controller* self){
	self->SBcarsonbridge--;
	self->passedcars--;
}

void checkdirection(controller* self){
	if(self->NBcarsonbridge > 0){
		self->direction = 1;
	}
	else if (self->SBcarsonbridge > 0){
		self->direction = 0;
	}
}





void updatetrafficlight(controller* self){
	
	
	if(self->direction == 1){ // if there is cars on the bridge coming from SB

		
		if(self->NBcarq > 0 && self->SBcarq > 0 && self->passedcars >= self->carlimit){
			USART_transmit(self,0xA); // NB RED, SB RED 0101
			
		}
		
		else if(self->NBcarq > 0 && self->SBcarq == 0 && self->passedcars >= self->carlimit){
			USART_transmit(self,0xA); // NB RED, SB RED 0101
					
		}
		
		else if(self->NBcarq == 0 && self->SBcarq > 0 && self->passedcars >= self->carlimit){
			USART_transmit(self,0xA); // NB RED, SB RED 0101
			
		}
		else if(self->NBcarq == 0 && self->SBcarq == 0 && >= self->carlimit){
			USART_transmit(self,0xA); // NB RED, SB RED 0101
			
			
		}
		
		else if(self->NBcarq > 0 && self->SBcarq == 0){
			USART_transmit(self,0x06); // NB RED, SB GREEN 0110
		}
				
		else if(self->NBcarq > 0 && self->SBcarq > 0){
				USART_transmit(self,0x06); // NB RED, SB GREEN 0110
		}
		else if(self->NBcarq == 0 && self->SBcarq > 0){
			USART_transmit(self,0x06); // NB RED, SB GREEN 0110
					
					
		}
	}
		
		
		
	else if(self->direction == 0){ // if there is cars on the bridge coming from NB

		
		if(self->NBcarq > 0 && self->SBcarq > 0 && self->passedcars >= self->carlimit){
			USART_transmit(self,0xA); // NB RED, SB RED 0101
			
		}
		
		else if(self->NBcarq > 0 && self->SBcarq == 0 && self->passedcars >= self->carlimit){
			USART_transmit(self,0xA); // NB RED, SB RED 0101
					
		}
		
		else if(self->NBcarq == 0 && self->SBcarq > 0 && self->passedcars >= self->carlimit){
			USART_transmit(self,0xA); // NB RED, SB RED 0101
			
		}
		else if(self->NBcarq == 0 && self->SBcarq == 0 && >= self->carlimit){
			USART_transmit(self,0xA); // NB RED, SB RED 0101
		}
		
		else if(self->NBcarq > 0 && self->SBcarq == 0){
			USART_transmit(self,0x09); // NB GREEN, SB RED 1001
		}
				
		else if(self->NBcarq > 0 && self->SBcarq > 0){ // change
				USART_transmit(self,0x09); // NB GREEN, SB RED 1001
	
		}
		else if(self->NBcarq == 0 && self->SBcarq > 0){
			USART_transmit(self,0x06); //NB GREEN, SB RED 1001
								
		}
	}
		
	if(self->passedcars > 8){
		self->passedcars = 0;
}

}
int USART_receive(controller* self, int arg){
	//check data register for event (UDR0), receive input
	//bit 0 = Northbound car arrival sensor activated
	//bit 1 = Northbound bridge entry sensor activated
	//bit 2 = Southbound car arrival sensor activated
	//bit 3 = Southbound bridge entry sensor activated
	//  UDR0 is the data register

	// 	It must be safe; i.e., cars going in opposite directions must never be allowed on the bridge at the same time. YES
	// 	It may not stop making progress. This means that the situation where the bridge is empty but queued cars are not allowed to enter the bridge must never arise. YES
	// 	It may not cause starvation. That is, the controller must make sure that northbound cars are not indefinitely delayed by a steady stream of southbound cars, 
	//  and vice versa. At the same time, a better utilization of the bridge can be achieved by letting through several cars in one direction with at least 1 second between them.
	// 	For our particular scenario, we will assume that a reasonable time for passing the bridge once it is entered is 5 seconds.
	
	// klocka som kollar hur länge en sida har kört och sen byter ljus (väntar på att alla lämnar bron innan den byter till grönt)
	// if entry set wait to 5 again
	
	//LOGIK part, control output based on sensor input and time
	//if arrive north/south side, add +1 to north/south side
	//if no cars on bridge : if cars on north/south side set green light immediately on north/south side and red on the other side
	//if cars on bridge : if cars on north/south side, set red light on other side immediately then wait until all threads are done running (<=5 seconds) then set green on north/south side
	
	
	//transmit output / change lights.
	//bit 0 = Northbound green light status
	//bit 1 = Northbound red light status
	//bit 2 = Southbound green light status
	//bit 3 = Southbound red light status
	
			
		while( !(UCSR0A & (1<<UDRE0))){
			
		
			//NB car arrival
			if(UDR0 == 0x01){ // 0001
					NBaddcar(self);	
			}
			//NB car bridge entry
			if(UDR0 == 0x02){ //0010
				NBaddcaronbridge(self);
				AFTER(SEC(5),self,NBremovecar,0);
				NBremovecar();	
				
			}
			//SB car arrival
			if(UDR0 == 0x04){ // 0100
				SBaddcar(self);
				
			}
			//SB bridge entry
			if(UDR0 == 0x08){ //1000
				SBaddcaronbridge();
				AFTER(SEC(5),self,SBremovecar,0);
				SBremovecar();
			}
		}
				checkdirection();
				updatetrafficlight(self);
				return 0;
	}
			
		
		
	
}
