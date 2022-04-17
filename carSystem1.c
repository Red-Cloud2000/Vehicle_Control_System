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
#if WITH_ENGINE_TEMP_CONTROLLER
	car.engineTemp=90;
	car.eTempController = 0;
#endif
	//------------------Welcome message----------------------------//
	printf("       Welcome Sir! :-)\n");
	printf("\n");

		//-------------------first list to appear at the monitor--------------------------//
	char choice1;                        //The input chosen by the user at first list
	while(1){                            //After breaking from the second list you return again to the first one.
		printf("a. Turn on the vehicle engine\n");   //             //
		printf("b. Turn off the vehicle engine\n");   //  First List //
		printf("c. Quit the system\n");                //             //
		scanf(" %c",&choice1);
		if(choice1=='c'||choice1=='C'){      //So if 'c' was chosen it quit the system
			break;                       //Breaks out of while then quit system
		}
		else{
			switch(choice1){
			//-------------------second list to appear at the monitor--------------------------//
			case 'a':                   //capital & small letter for validation
			case 'A':                   //if 'a' is chosen engine turns on and the 2nd list(turn on list) appears.
				car.engineState=ON;
				while(1){
					printf("\n");
					printf("a. Turn off the engine\n");                               //                //
					printf("b. Set the traffic light color.\n");                       //                //
					printf("c. Set the room temperature (Temperature Sensor)\n");       // (Turn ON List) //
#if WITH_ENGINE_TEMP_CONTROLLER         //conditional compilation (for engine appearance)                    // Second List    //
					printf("d. Set the engine temperature (Engine Temperature Sensor)\n");//                //
#endif                //end of conditional compilation                                                         //                //

					char choice2;                   //The input chosen by the user at second list
					scanf(" %c",&choice2);
					if(choice2=='a'||choice2=='A'){ //If'a'is chosen engine turns off and the 1st list appears.
						                            //Choice 'a' was made out of switch case for better coding so
						                            //we will break one time to return to first list
						printf("\n");
						printf("    -------------------\n");
						printf("   |Vehicle engine: OFF|\n");
						printf("    -------------------\n");
						car.engineState=OFF;                    //Engine is off
						printf("\n");
						break;                                //Breaks out of the second while(1) to return to 1st list
					}
					else{
						switch(choice2){
						case 'b':                  //If'a'(Traffic light status)is chosen a sensor should detect the light color but
						case 'B':                  //but for now a request would appear to the user and the color would be
							printf("\n");          //taken as an input
							printf("Enter the required light: ");
							light();               //Function that take color as an input then change vehicle speed if necessary
							break;                 //depending on that input.

						case 'c':                  //If'c'(vehicle room temperature)is chosen a sensor should detect it but for now
						case 'C':                  //a request would appear to the user and the room temperature would be
							printf("\n");          //taken as an input.
							printf("Enter the current room temperature: ");
							roomTempCap();         //Function that take room temperature as an input then change it if necessary
							state();               //depending on that input with the help of the AC.
							break;
#if WITH_ENGINE_TEMP_CONTROLLER                                      //conditional compilation (for engine appearance)

						case 'd':                  //If'c'(vehicle engine temperature)is chosen a sensor should detect it but for now
						case 'D':                  //a request would appear to the user and the engine temperature would be
							printf("\n");          //taken as an input.
							printf("Enter the current engine temperature: ");
							engineTempCap();       //Function that take engine temperature as an input then change it if necessary
							state();               //depending on that input with the help of the engine temperature controller.
							break;

#endif                                             //end of conditional compilation

						default:                   //for validation if wrong input in 2nd list.
							printf("\n");
							printf("-----\n");
							printf("| | |\n");
							printf("| | |Worng input!! Try again\n");
							printf("| o |\n");
							printf("-----\n");
						}
					}

				}
				break;                            //break of case'a' of choice1
					
			case 'b':                                 //If'b'is chosen engine turns off and the 1st list appears.
			case 'B':
				printf("\n");
				printf("    -------------------\n");
				printf("   |Vehicle engine: OFF |\n");
				printf("    -------------------\n");
				car.engineState=OFF;               //engine is off
				break;

			default:                                  //for validation if wrong input in 1st list.
				printf("\n");
				printf("-----\n");
				printf("| | |\n");
				printf("| | |Worng input!! Try again\n");
				printf("| o |\n");
				printf("-----\n");
			}
		}
	}

	//------------------shut_down message----------------------------//
	printf("\n");
	printf("    -------------------\n");
	printf("    | See U later! ;->|\n");          //if 'c' was chosen at 1st list, program shut_down
	printf("    -------------------\n");	
	
	return 0;
}

