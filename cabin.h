#include <stdio.h>
#include "myFunctions.h"      //for including the functions declaration header file (Be_careful: it's a " " not < >, ;-> )
#define WITH_ENGINE_TEMP_CONTROLLER 1           //for conditional compilation (for engine appearance)
							  //if you want engine work make it 1 if not make it 0

enum devices_state{           //for ON/OFF states
	OFF=0 , ON=1
};
enum speed_state{             //for speed states
	go=100 , calm_down=30 , stop=0
};

	//------------------Structure of dash board values----------------------------//

struct{
	char light;               //Traffic light color
	int roomTemp;             //Room temperature read
	int engineState;          //Engine state (ON/OFF)
	int ACstate;              //AC state (ON/OFF)
	int speed;                //Speed read

#if WITH_ENGINE_TEMP_CONTROLLER                 //conditional compilation (for engine appearance)

	int eTempController;      //Engine temperature controller state (ON/OFF)
	int engineTemp;           //Engine temperature read

#endif                        //end of conditional compilation

}car;

	//------------------State updating function----------------------------//

void state(void){
	printf("\n");
	printf("\n");

	if(ON==car.engineState)                 //check if engine is ON or OFF
		printf("Engine is ON \n");
	else
		printf("Engine is OFF \n");
	if(ON==car.ACstate)                              //check if AC is ON or OFF
		printf("AC is ON \n");
	else
		printf("AC is OFF \n");

	printf("Vehicle Speed: %d Km/Hr\n",car.speed);  //show vehicle speed
	printf("Room Temperature: %d C\n",car.roomTemp);//show vehicle room temperature
#if WITH_ENGINE_TEMP_CONTROLLER < 1                         //conditional compilation if engine appearance is disabled so do this for better UI
	printf("\n");
	printf("\n");
#endif                                    //end of conditional compilation

#if WITH_ENGINE_TEMP_CONTROLLER                             //conditional compilation (for engine appearance)

	if(ON==car.eTempController)            //check if engine temperature controller is ON or OFF
		printf("Engine Temperature Controller is ON \n");
	else
		printf("Engine Temperature Controller is OFF \n");

	printf("Engine Temperature: %d C\n",car.engineTemp); //show vehicle engine temperature
	printf("\n");
	printf("\n");
#endif                                   //end of conditional compilation
}


//------------------Traffic Light function----------------------------//

void light(){
	char flag;                          //flag for validation to break from while loop with it
	char color;
	while(1){                           //for continuous validation
		scanf(" %c",&color);
		switch(color){
		case 'g':                       //if 'g' was chosen speed became 100 Km/Hr
		case 'G':
			car.light='g';
			car.speed=go;
			state();
			flag=1;
			break;
		case 'o':                       //if 'o' was chosen speed became 30 Km/Hr and:
		case 'O':                       //  - AC & engine temperature controller turn ON
			//  - room & engine(if compiled "WITH_ENGINE_TEMP_CONTROLLER=1") temperature became same value*(5/4)+1

			color='o';                  //for better validation
			car.speed=calm_down;
			if(car.light!='o'){         //for validation so not each time 'o' is chosen many times without any change between, temperature will change
				car.light='o';
				car.ACstate=ON;
				car.roomTemp=car.roomTemp*(5/4)+1;
#if WITH_ENGINE_TEMP_CONTROLLER                           //conditional compilation (for engine appearance)
				car.eTempController=ON;
				car.engineTemp=car.engineTemp*(5/4)+1;
#endif                                  //end of conditional compilation
			}
			state();
			flag=1;
			break;

		case 'r':                       //if 'r' was chosen speed became 0 Km/Hr
		case 'R':
			car.light='r';
			car.speed=stop;
			state();
			flag=1;
			break;

		default:                        //for validation if wrong input
			printf("\n");
			printf("-----\n");
			printf("| | |\n");
			printf("| | |Worng input!! Try again\n");
			printf("| o |\n");
			printf("-----\n");
			flag=0;

			printf("Enter the rehquired light: ");
		}
		if(1==flag)
			break;
	}
}

//------------------Room temperature cabin function----------------------------//

void roomTempCap(void){                //function that controls room temperature
	scanf(" %d",&car.roomTemp);
	if(car.roomTemp<10){               //if room temperature is less than 10:
		car.ACstate=ON;                // - Turn AC ON
		car.roomTemp=20;               // - make it 20 C
	}
	else if(car.roomTemp>30){          //if room temperature is more than 30:
		car.ACstate=ON;                // - Turn AC ON
		car.roomTemp=20;               // - make it 20 C
	}
	else
		car.ACstate=OFF;               //else turn off AC and leave temperature as it is

}

//------------------Engine temperature cabin function----------------------------//

#if WITH_ENGINE_TEMP_CONTROLLER                         //conditional compilation (for engine appearance)

void engineTempCap(void){             //function that controls engine temperature
	scanf(" %d",&car.engineTemp);
	if(car.engineTemp<100){           //if engine temperature is less than 100:
		car.eTempController=ON;       // - Turn engine temperature controller ON
		car.engineTemp=125;           // - make it 125 C
	}
	else if(car.engineTemp>150){      //if engine temperature is more than 150:
		car.eTempController=ON;       // - Turn engine temperature controller ON
		car.engineTemp=125;           // - make it 125 C
	}
	else
		car.eTempController=OFF;      //else turn off engine temperature controller and leave temperature as it is

}
#endif                                //end of conditional compilation
