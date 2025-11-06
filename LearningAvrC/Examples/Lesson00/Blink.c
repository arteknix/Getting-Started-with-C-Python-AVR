/*  ©arteknix : template for avr programming
    list of includes you might consider
    tow functions for illustration
    initLed and toggleLed
    this sketch needs avr/io.h for pins
    and util/delay.h for _delay_ms
    NB: normally you would use interrupt of TIMER overflow.
    */
//#include <stdint.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <avr/interrupt.h>
#include <avr/io.h>
//#include <avr/pgmspace.h>
//#include <inttypes.h>
#define F_CPU 16000000
#include <util/delay.h>

#define LED_PIN     PB5     //PIN
#define LED_PORT    PORTB   //PORT
#define LED_DDR     DDRB    //IO config
//======== FUNCTIONS ===================
void initLed(){
    LED_DDR  |= _BV(LED_PIN); // LED_PIN as OUTPUT
}
void toggleLed(){
    LED_PORT ^= _BV(LED_PIN); // invert LED_PIN
}
//======== MAIN ========================
int main(void){
    initLed();
    while(1){
        toggleLed();
	    _delay_ms(300);
        toggleLed();
	    _delay_ms(700);
    }
    return 0;
}
