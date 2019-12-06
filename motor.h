#ifndef MOTOR_H_
#define MOTOR_H_

#include <msp430.h>

//#define STNDBY_PIN               1
//#define STNDBY_BIT               BIT1
//#define STNDBY_PORT              P1OUT
//#define STNDBY_DDR               P1DIR
//#define SET_STNDBY_AS_AN_OUTPUT  STNDBY_DDR |= STNDBY_BIT
//
//#define PWM_PIN               2
//#define PWM_BIT               BIT2
//#define PWM_PORT              P1OUT
//#define PWM_DDR               P1DIR
//#define SET_PWM_AS_AN_OUTPUT  PWM_DDR |= PWM_BIT
//
//#define RENC_1_PIN               4
//#define RENC_1_BIT               BIT4
//#define RENC_1_PORT              P2OUT
//#define RENC_1_DDR               P2DIR
//#define SET_RENC_1_AS_AN_INPUT   RENC_1_DDR &= ~RENC_1_BIT
//
//#define RENC_2_PIN               3
//#define RENC_2_BIT               BIT3
//#define RENC_2_PORT              P2OUT
//#define RENC_2_DDR               P2DIR
//#define SET_RENC_2_AS_AN_INPUT   RENC_2_DDR &= ~RENC_2_BIT

//MS1 is 1.3, out
#define MS1_1_PIN               3
#define MS1_1_BIT               BIT3
#define MS1_1_PORT              P1OUT
#define MS1_1_DDR               P1DIR
#define SET_MS1_1_AS_AN_OUTPUT  MS1_1_DDR |= MS1_1_BIT
#define MS1_1_HIGH              MS1_1_PORT |= MS1_1_BIT
#define MS1_1_LOW               MS1_1_PORT &= ~MS1_1_BIT

//DIR is 1.2, out
#define DIR_1_PIN               2
#define DIR_1_BIT               BIT2
#define DIR_1_PORT              P1OUT
#define DIR_1_DDR               P1DIR
#define SET_DIR_1_AS_AN_OUTPUT  DIR_1_DDR |= DIR_1_BIT
#define DIR_1_HIGH              DIR_1_PORT |= DIR_1_BIT
#define DIR_1_LOW               DIR_1_PORT &= ~DIR_1_BIT

//SLEEP is 1.0
#define SLEEP_1_PIN               0
#define SLEEP_1_BIT               BIT0
#define SLEEP_1_PORT              P1OUT
#define SLEEP_1_DDR               P1DIR
#define SET_SLEEP_1_AS_AN_OUTPUT  SLEEP_1_DDR |= SLEEP_1_BIT
#define DISABLE_SLEEP_1          SLEEP_1_PORT |= SLEEP_1_BIT


//STEP is 1.1
#define STEP_1_PIN              1
#define STEP_1_BIT              BIT1
#define STEP_1_PORT             P1OUT
#define STEP_1_DDR              P1DIR
#define SET_STEP_1_AS_AN_OUTPUT STEP_1_DDR |= STEP_1_BIT
#define STEP_1_HIGH              STEP_1_PORT |= STEP_1_BIT
#define STEP_1_LOW               STEP_1_PORT &= ~STEP_1_BIT


//RESET is 1.4
#define RESET_1_PIN              4
#define RESET_1_BIT              BIT4
#define RESET_1_PORT             P1OUT
#define RESET_1_DDR              P1DIR
#define SET_RESET_1_AS_AN_OUTPUT RESET_1_DDR |= RESET_1_BIT
#define SEND_1_RESET             RESET_1_PORT &= ~RESET_1_BIT
#define CLOSE_RESET            RESET_1_PORT |= RESET_1_BIT

//ENABLE1 is 1.5
#define ENABLE1_PIN              5
#define ENABLE1_BIT              BIT5
#define ENABLE1_PORT             P1OUT
#define ENABLE1_DDR              P1DIR
#define SET_ENABLE1_AS_AN_OUTPUT ENABLE1_DDR |= ENABLE1_BIT
#define ENABLE1_SET            ENABLE1_PORT &= ~ENABLE1_BIT
#define ENABLE1_UNSET            ENABLE1_PORT |= ENABLE1_BIT

//MS2 is 2.0
#define MS2_1_PIN               0
#define MS2_1_BIT               BIT0
#define MS2_1_PORT              P2OUT
#define MS2_1_DDR               P2DIR
#define SET_MS2_1_AS_AN_OUTPUT  MS2_1_DDR |= MS2_1_BIT
#define MS2_1_HIGH              MS2_1_PORT |= MS2_1_BIT
#define MS2_1_LOW               MS2_1_PORT &= ~MS2_1_BIT




/**
 * U5
 */




//MS1 is 2.4, out
#define MS1_2_PIN               4
#define MS1_2_BIT               BIT4
#define MS1_2_PORT              P2OUT
#define MS1_2_DDR               P2DIR
#define SET_MS1_2_AS_AN_OUTPUT  MS1_2_DDR |= MS1_2_BIT
#define MS1_2_HIGH              MS1_2_PORT |= MS1_2_BIT
#define MS1_2_LOW               MS1_2_PORT &= ~MS1_2_BIT

//DIR is 2.3, out
#define DIR_2_PIN               3
#define DIR_2_BIT               BIT3
#define DIR_2_PORT              P2OUT
#define DIR_2_DDR               P2DIR
#define SET_DIR_2_AS_AN_OUTPUT  DIR_2_DDR |= DIR_2_BIT
#define DIR_2_HIGH              DIR_2_PORT |= DIR_2_BIT
#define DIR_2_LOW               DIR_2_PORT &= ~DIR_2_BIT

//SLEEP is 2.1
#define SLEEP_2_PIN               1
#define SLEEP_2_BIT               BIT1
#define SLEEP_2_PORT              P2OUT
#define SLEEP_2_DDR               P2DIR
#define SET_SLEEP_2_AS_AN_OUTPUT  SLEEP_2_DDR |= SLEEP_2_BIT
#define DISABLE_SLEEP_2          SLEEP_2_PORT |= SLEEP_2_BIT


//STEP is 2.2
#define STEP_2_PIN              2
#define STEP_2_BIT              BIT2
#define STEP_2_PORT             P2OUT
#define STEP_2_DDR              P2DIR
#define SET_STEP_2_AS_AN_OUTPUT STEP_2_DDR |= STEP_2_BIT
#define STEP_2_HIGH              STEP_2_PORT |= STEP_2_BIT
#define STEP_2_LOW               STEP_2_PORT &= ~STEP_2_BIT


//RESET is 2.5
#define RESET_2_PIN              5
#define RESET_2_BIT              BIT5
#define RESET_2_PORT             P2OUT
#define RESET_2_DDR              P2DIR
#define SET_RESET_2_AS_AN_OUTPUT RESET_2_DDR |= RESET_2_BIT
#define SEND_2_RESET             RESET_2_PORT &= ~RESET_2_BIT
#define CLOSE_RESET_2            RESET_2_PORT |= RESET_2_BIT

//ENABLE2 is 1.6
#define ENABLE2_PIN              6
#define ENABLE2_BIT              BIT6
#define ENABLE2_PORT             P1OUT
#define ENABLE2_DDR              P1DIR
#define SET_ENABLE2_AS_AN_OUTPUT ENABLE2_DDR |= ENABLE2_BIT
#define ENABLE2_SET             ENABLE2_PORT &= ~ENABLE2_BIT
#define ENABLE2_UNSET           ENABLE2_PORT |= ENABLE2_BIT

//MS2 is 1.7
#define MS2_2_PIN               7
#define MS2_2_BIT               BIT7
#define MS2_2_PORT              P1OUT
#define MS2_2_DDR               P1DIR
#define SET_MS2_2_AS_AN_OUTPUT  MS2_2_DDR |= MS2_2_BIT
#define MS2_2_HIGH              MS2_2_PORT |= MS2_2_BIT
#define MS2_2_LOW               MS2_2_PORT &= ~MS2_2_BIT


// Function Prototypes
void InitializeMotorPortPins(void);

void StepMotor(int count);

/*
 *  * This function configures and initializes all of the pins associated with the rotary encoder.
 */

#endif /* MOTOR_H_ */
