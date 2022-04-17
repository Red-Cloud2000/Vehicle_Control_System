#include "cabin.h"       //for including functions at cabin header file (Be_careful: it's a " " not < >, ;-> )
#include "myFunctions.h" //for including functions declaration header file
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	//-------For buffer disabling(not to wait at the end of the program to print every thing at one time)-----------//
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	//-------States initial values-----------------------------//
	car.light = 'g';
	car.roomTemp = 35;
	car.engineState = 0;
	car.ACstate = 0;
	car.speed = 100;
#if switching
	car.engineTemp=90;
	car.eTempController = 0;
#endif
	//------------------Welcome message----------------------------//
	printf("       Welcome Sir! :-)\n");
	printf("\n");
