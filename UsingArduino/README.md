# Arduino - IDE - ArduinoMK 

Using the IDE and testing alternatives 
>[!NOTE]
> The concept is to make it as easy as possible for 'NotCodingPeople' to get creative results
> in micro-computing and electronics in oreder to **make** _cool stuff_

>[!IMPORTANT]
> Here we'll show what a **'Coder'** would want to know about Arduino®\
> The Arduino Language:
> - is a mix of C and C++
> - includes many definitions so you do not have to worry about them
> - gives you access to many libraries
> - is supported by many board/sensor manufacturers

> [!TIP]
> in [LearningAvrC](../LearningAvrC) (SID:Still In Development)
> we will do some ***massive skimming***

## IDE - Basic Blink Sketch

```
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
```
>[!NOTE]
> this sketch use :
> - pinMode()
> - digitalWrite()
> - delay()
> - LED_BUILTIN / HIGH / LOW
## How can it even work?

Well, the answer to this is in your arduino folder ( /usr/share/arduino on linux ).\
Let's say we give a generic name to this forlder for thurther use:\
``` ARDUINO_DIR='/usr/share/arduino' ```\
You'll find the **Core** of your arduino distribution (collection of software) in:\
``` ARDUINO_DIR/hardware/arduino/avr/cores/arduino/ ```\
For now we take a look at only two files:\
```
Arduino.h // main header file 
main.cpp  // main source file
```
### Do the Magic
***main.cpp*** says (I took out a few lines for clarity):
```
#include <Arduino.h>
...
// Weak empty variant initialization function.
// May be redefined by variant files.
void initVariant() __attribute__((weak));
void initVariant() { }

void setupUSB() __attribute__((weak));
void setupUSB() { }

int main(void)
{
	init();

	initVariant();

#if defined(USBCON)
	USBDevice.attach();
#endif
	
	setup();
    
	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}
        
	return 0;
} 
```
And ***Arduino.h*** contains all the magically coloured commands ( just some example lines here ) :
> ```
> #ifndef Arduino_h
> #define Arduino_h
>
> #include <stdlib.h>
> #include <stdbool.h>
> #include <string.h>
> #include <math.h>
>
> #include <avr/pgmspace.h>
> #include <avr/io.h>
> #include <avr/interrupt.h>
>
> #include "binary.h"
>
> ifdef __cplusplus
> extern "C"{
> #endif
> ...
> #define min(a,b) ((a)<(b)?(a):(b))
> #define max(a,b) ((a)>(b)?(a):(b))
> #define abs(x) ((x)>0?(x):-(x))
> #define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
> #define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
> #define radians(deg) ((deg)*DEG_TO_RAD)
> #define degrees(rad) ((rad)*RAD_TO_DEG)
> #define sq(x) ((x)*(x))
> 
> #define interrupts() sei()
> #define noInterrupts() cli()
> ...
> void pinMode(uint8_t pin, uint8_t mode);
> void digitalWrite(uint8_t pin, uint8_t val);
> int digitalRead(uint8_t pin);
> int analogRead(uint8_t pin);
> void analogReference(uint8_t mode);
> void analogWrite(uint8_t pin, int val);
> 
> unsigned long millis(void);
> unsigned long micros(void);
> void delay(unsigned long ms);
> void delayMicroseconds(unsigned int us);
> ...
> 
> void setup(void);
> void loop(void);
> 
> ...
> 
> ```

>[!NOTE]
> so here we have the ***declarations*** of the **setup** and **loop** [functions](../LearningC/C_Language_Shorts/C_syntax.md#functions) \
> you ***define*** them in your sketch

## ArduinoMk
This a beautifull package based on make-files which allows you to use Arduino code without the "heavyweight" IDE.\
We'll use it for some examples.

## Addendum
In your sketch or temporary folder you will find a file called ***main.cpp.d***
>[!IMPORTANT]
> It contains all the files to include for compiling and linking main.cpp:
>```
> build-uno/core/main.cpp.o: \
>  /usr/share/arduino/hardware/arduino/avr/cores/arduino/main.cpp \
>  /usr/share/arduino/hardware/arduino/avr/cores/arduino/Arduino.h \
>  /usr/share/arduino/hardware/arduino/avr/cores/arduino/binary.h \
>  /usr/share/arduino/hardware/arduino/avr/cores/arduino/WCharacter.h \
>  /usr/share/arduino/hardware/arduino/avr/cores/arduino/WString.h \
>  /usr/share/arduino/hardware/arduino/avr/cores/arduino/HardwareSerial.h \
>  /usr/share/arduino/hardware/arduino/avr/cores/arduino/Stream.h \
>  /usr/share/arduino/hardware/arduino/avr/cores/arduino/Print.h \
>  /usr/share/arduino/hardware/arduino/avr/cores/arduino/Printable.h \
>  /usr/share/arduino/hardware/arduino/avr/cores/arduino/USBAPI.h \
>  /usr/share/arduino/hardware/arduino/avr/cores/arduino/Arduino.h \
>  /usr/share/arduino/hardware/arduino/avr/variants/standard/pins_arduino.h
>```
