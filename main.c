#include <msp430.h>
#include "timerA.h"
#include "motor.h"
#include "UART.h"
#include "InterruptServiceRoutines.h"
// Global Variables
//unsigned int g1msTimer; // Global 1 ms timer used for pushbutton debounce.
//int RotaryEncoderStateCount; // Indicates valid FSM sequences.
//int LEDDisplayValue; // Indicates value to display in the 7-segment displays

#define FALSE 0
#define TRUE 1

int waiting = 0;
int state = 0;

// Function Prototypes
void ConfigureClockModule();
//SwitchStatus DebounceSwitch(SwitchDefine *Switch);

int main(void)
{
//	FSMType RotaryEncoder_FSM;
//    SwitchDefine RotaryEncoderReset;
//    SwitchDefine RotaryEncoderSwitchA;
//    SwitchDefine RotaryEncoderSwitchB;

	WDTCTL = WDTPW | WDTHOLD;
	// Stop watchdog timer
    ConfigureClockModule();
//
//    // Initialize hardware.
//    ConfigureTimerA();
    InitializeUART();
	InitializeMotorPortPins();
//	InitializePushButtonPortPin();
//	InitializeRotaryEncoderPortPins();
//	InitializeSPI();
//	InitializeLEDDisplay();
//
//    // Initialize Finite State Machine (FSM) state variables.
//	InitializeFSM(&RotaryEncoder_FSM);
//
//    // Initialize active-low switch for pushbutton.
//    InitializeSwitch(&RotaryEncoderReset,(char *) &PUSHBUTTON_PORT_IN,(unsigned char) PUSHBUTTON_BIT,
//            Active, Inactive, ACTIVE_THRESHOLD,INACTIVE_THRESHOLD);
//
//    // Initialize active-low switches for rotary encoder.
//    InitializeSwitch(&RotaryEncoderSwitchA,(char *) &P2IN,(unsigned char) BIT4,
//            Active, Inactive, ACTIVE_THRESHOLD,INACTIVE_THRESHOLD);
//    InitializeSwitch(&RotaryEncoderSwitchB,(char *) &P2IN,(unsigned char) BIT3,
//            Active, Inactive, ACTIVE_THRESHOLD,INACTIVE_THRESHOLD);

    _enable_interrupts();

	// Loop forever
    //int motor = 0;
    waitForTX();
    printString("here!");
	while(TRUE) {
	    //StepMotor(10000);
	    /*
	     * If waiting == 1, pass.
	     * Otherwise,
	     * 0 -- Main menu
	     * 1 -- Select motor
	     * 2 -- Spin dir
	     */
	    if (waiting == 1){
	        //pass
	        //printString("waiting");
	    }
	    else{
	        switch(state){
	        case 0:
	            //print guide

	            printString("welcome!");
	            waiting = 1;
	        }
	    }
	    //TimeDelay(5, 1000);
	}
	return 0;
}


void ConfigureClockModule()
{
    // Configure Digitally Controlled Oscillator (DCO) using factory calibrations
    DCOCTL  = CALDCO_1MHZ;
    BCSCTL1 = CALBC1_1MHZ;
}
