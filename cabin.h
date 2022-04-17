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

