#include "stdio.h"
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h> //linux write and read

#define F_CPU 8000000 //clock speed
#define BAUD 9600
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)

int num_north_cars, num_south_cars, num_passing_cars;

pthread_t id[5];

void* passing_car(void *arg){
	//sleep(5);
	//car is gone
	printf("Hellow world!");
	pthread_exit(0);
}

void reactOnInput(int COM1){
	fd_set rfds;
	FD_ZERO(&rfds); // emtpy set
	FD_SET(0, &rfds); // include keyboard
	FD_SET(COM1, &rfds); // include com1:
	select(4,&rfds,NULL,NULL,NULL); // wait
	if(FD_ISSET(0,&rfds)){
		//handle keypress...
		printf("Hello world!");
	}
}
	
int main(void){
	
	int COM1 = open("/dev/ttyS0",O_RDWR); // open com port
	
	printf("start");
	
	// Read the configuration of the port 
 
	struct termios options;
	tcgetattr( COM1, &options );
 
	/* SEt Baud Rate */
 
	cfsetispeed( &options, B9600 );
	cfsetospeed( &options, B9600 );
	
	/* Set to raw input */
	options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
	
	/* Set to raw output */
	options.c_oflag &= ~OPOST;
	
	/* Set options TCSANOW is immediately */
	tcsetattr(fd, TCSANOW, &options);
	
	// in #include <unistd.h> 
	//write(int fildes, const void *buf, nbytes); writes to file fildes from *buf with size nbytes
	//read(int fildes, void *buf, nbytes); reades from fildes to buf with size nbytes
	
	reactOnInput(COM1);

	int i = 0;
	

	// we only want to create a passing car if we are allowed, to prevent starving
	pthread_create(&id[i], NULL, passing_car, NULL);
	// do other work here
	
	pthread_join(id[i],NULL);
	// here the threads are done and we tell the controller that there are no cars on the bridge and the controller is allowed to change lights
	//ASYNC to interruptHandler maybe?
	
	// send car: create a posix thread and run it (sleep 5) then done
	// when all threads are done, set bridge is empty and change lights
	
	//termios användes för stordatorer
	
}