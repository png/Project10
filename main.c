#include <msp430.h>
#include "timerA.h"
#include "InterruptServiceRoutines.h"
// Global Variables
//unsigned int g1msTimer; // Global 1 ms timer used for pushbutton debounce.
//int RotaryEncoderStateCount; // Indicates valid FSM sequences.
//int LEDDisplayValue; // Indicates value to display in the 7-segment displays

#define FALSE 0
#define TRUE 1

int waiting = 0;
int state = 0;
int execute = 1;
char response = '\0';

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
    //waitForTX();

	while(execute == 1) {
	    //StepMotor(10000);
	    /*
	     * If waiting == 1, pass.
	     * Otherwise,
	     * 0 -- Main menu
	     * 1 -- Select motor
	     * 2 -- Spin dir
	     */
	    if (waiting == 0){
	        //print
	        if (response == '\0'){
                if (state == 0){
                    printString("Enter a command - (1) Select motor (2) Spin motor (x) Exit: \r\n");
                    //change state based on input
                }
                else if (state == 1){
                    printString("Which motor? (1) U2 (2) U5\r\n");
                    //change motor bit
                }
                else if (state == 2){
                    printString("Which direction? (1) Clockwise (2) Counterclockwise\r\n");
                    //
                }
                else if (state == 3){
                    printString("Which motor? (1) U2 (2) U5\r\n");                    //
                }

                printString("Which direction? (1) Clockwise (2) Counterclockwise\r\n");
                waiting = 1;
	        }
	        else{
	            if(!(response == '1' || response == '2' || response == 'x')){
	                printString("Error! Incorrect choice\n");
	                waiting = 0;
	                state = 0;
	            }
	            else if (state == 0){
	                if(response == '1'){
	                    state = 1;
	                }
	                if(response == '2'){
	                    state = 2;
                    }
	                if(response == 'x'){
	                    execute = 0;
                    }
                    //change state based on input
                }
                else if (state == 1){
                    state = 3;
                    //change motor based on response
                }
                else if (state == 2){
                    state = 4;
                    //change spin dir var based on response
                }
                else if (state == 3){
                    printString("Selected motor");
                    state = 0;
                    //
                }
                else if (state == 4){
                    printString("Spinning motor\n");
                    //spin motor
                    state = 0;
                    //change motor bit
                }
	            waiting = 0;
	            response = '\0';
	        }

	    }
	    else if (waiting == 1){
	        __nop();

	    }
	}
	return 0;
}


void ConfigureClockModule()
{
    // Configure Digitally Controlled Oscillator (DCO) using factory calibrations
    DCOCTL  = CALDCO_1MHZ;
    BCSCTL1 = CALBC1_1MHZ;
}
