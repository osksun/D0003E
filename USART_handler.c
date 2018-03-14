/*
 * USART_handler.c
 *
 * Created: 2018-03-14 13:46:17
 *  Author: albsve-6
 */ 

#include "USART_handler.h"
#include "tinytimber"
#include <unistd.h>

// int numberofcarsnorth;
// int numberofcarssouth;
// int numberofcarsonbridgeNB;
// int numberofcarsonbridgeSB;

// red red = 0
// green green = 1
// red green = 2
// green red = 3

void removecar(int arg){
	if (arg == 1)
	
}

int interruptHandler(USART_handler *self, int arg){
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
	

			if(UDR0 == 0x01){ // 0001
					self->numberofcarsnorth++;
					
					
				
			}
			if(UDR0 == 0x02){ //0010
				self->numberofcarsonbridgeNB++;
				sleep(5);
				self->numberofcarsnorth--;
				
				
				
			}
			
			if(UDR0 == 0x04){ // 0100
				self->numberofcarssouth
				
			}
			
			if(UDR0 == 0x08){ //1000
			self->numberofcarsonbridgeSB++;
			sleep(5);
			self->numberofcarssouth--;

			}
		
		
	
}
