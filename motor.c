#include <motor.h>
#include "timerA.h"

void InitializeMotorPortPins(void)
{
//    SET_MS1_1_AS_AN_OUTPUT;
//    SET_MS2_1_AS_AN_OUTPUT;
//    SET_ENABLE1_AS_AN_OUTPUT;
//    SET_ENABLE2_AS_AN_OUTPUT;
//    SET_STEP_1_AS_AN_OUTPUT;
//    SET_STEP_2_AS_AN_OUTPUT;
//    SET_DIR_1_AS_AN_OUTPUT;
//    SET_DIR_2_AS_AN_OUTPUT;
//    SET_RESET_1_AS_AN_OUTPUT;
//    SET_RESET_2_AS_AN_OUTPUT;
//    SET_SLEEP_AS_AN_OUTPUT;
//
    P1DIR = 0xFF;
    P2DIR = 0x3F;

    ENABLE1_SET;
    ENABLE2_SET;
    DISABLE_SLEEP_1;
    DISABLE_SLEEP_2;
}

void StepMotor(int count, int motor, int direction){
    //set res, dir, etc.
    SEND_1_RESET;
    CLOSE_RESET;

    MS1_1_LOW;
    MS2_1_LOW;

    MS1_2_LOW;
    MS2_2_LOW;

    if(direction){
        DIR_1_HIGH;
        DIR_2_HIGH;
    }
    else{
        DIR_1_LOW;
        DIR_2_LOW;
    }


    TimeDelay(100, 1000);

    //toggle



    //in a loop...
    for(int i = 0; i < count; i++){
        //send step
        if(motor == 0){
            STEP_1_HIGH;
            TimeDelay(1, 800);
            STEP_1_LOW;
            TimeDelay(1, 800);
        }
        else{
            STEP_2_HIGH;
            //wait
            TimeDelay(1, 800);
            //close step
            STEP_1_LOW;
            STEP_2_LOW;
            //delay
            TimeDelay(1, 800);
        }
    }

    //done
}

void EnableMotors(){

}

void DisableMotors(){

}
