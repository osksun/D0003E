/*
 * simulation.c
 *
 * Created: 2018-03-14 13:51:51
 *  Author: osksun-6
 */ /*
 * D0003ELab5.c
 *
 * Created: 2018-03-14 13:47:46
 * Author : osksun-6
 */ 

//#include <avr/io.h>
#include <stdio.h>

int numberofcarsnorth;
int numberofcarssouth;
int numberofcarsonbridgeNB;
int numberofcarsonbridgeSB;
// red red = 0
// green green = 1
// red green = 2 
// green red = 3
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#define clear() printf("\033[H\033[J")



	void gui(){
		int signal = 3;
		int i;
		int k = 23;
		 if(signal == 0){
			printf("Cars waiting NORTHBOUND: %d        ["RED "0" RESET "]                       ["RED"0"RESET"] Cars waiting SOUTHBOUND: %d\n",numberofcarsnorth,numberofcarssouth);
			printf("Cars on bridge from NORTHBOUND: %d | |                       | | Cars on bridge from SOUTHBOUND: %d\n",numberofcarsonbridgeSB);
			printf("                                  | |",numberofcarsonbridgeNB);
			for(i = 0; i<k;i++){
				
				printf("_");
			}
			printf("| |");
		}
		
		 else if(signal == 1){
			 printf("Cars waiting NORTHBOUND: %d        ["GRN "0" RESET "]                       ["GRN"0"RESET"] Cars waiting SOUTHBOUND: %d\n",numberofcarsnorth,numberofcarssouth);
			 printf("Cars on bridge from NORTHBOUND: %d | |                       | | Cars on bridge from SOUTHBOUND: %d\n",numberofcarsonbridgeSB);
			 printf("                                  | |",numberofcarsonbridgeNB);
			 for(i = 0; i<k;i++){
				 
				 printf("_");
			 }
			 printf("| |");
		 }

		 else if(signal == 2){
			 printf("Cars waiting NORTHBOUND: %d        ["RED "0" RESET "]                       ["GRN"0"RESET"] Cars waiting SOUTHBOUND: %d\n",numberofcarsnorth,numberofcarssouth);
			 printf("Cars on bridge from NORTHBOUND: %d | |                       | | Cars on bridge from SOUTHBOUND: %d\n",numberofcarsonbridgeSB);
			 printf("                                  | |",numberofcarsonbridgeNB);
			 for(i = 0; i<k;i++){
				 
				 printf("_");
			 }
			 printf("| |");
		 }
		 else if(signal == 3){
			 printf("Cars waiting NORTHBOUND: %d        ["GRN "0" RESET "]                       ["RED"0"RESET"] Cars waiting SOUTHBOUND: %d\n",numberofcarsnorth,numberofcarssouth);
			 printf("Cars on bridge from NORTHBOUND: %d | |                       | | Cars on bridge from SOUTHBOUND: %d\n",numberofcarsonbridgeSB);
			 printf("                                  | |",numberofcarsonbridgeNB);
			 for(i = 0; i<k;i++){
				 
				 printf("_");
			 }
			 printf("| |");
		 }
	}
	

int main(void)
{
	gui();

}

