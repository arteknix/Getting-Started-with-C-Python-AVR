# @arteknix: Atmel AVR: compile - build - upload - list symbols
# rather complete MAKEFILE for AVR using debian Linux file paths
MCU 		= atmega328p    #avr-gcc and AVRdude
PART		= m328p         #AVRdude alternative
TARGET_ARCH	= -mmcu=$(MCU)
TARGET 		= blink
CC		= avr-gcc
CPPFLAGS	= -mmcu=$(MCU)
CFLAGS		= -Os -g -Wall -I./includes, -DF_CPU=16000000
LDFLAGS		= -g -mmcu=$(MCU) -lm -Wl,--gc-sections -Os
#PRGMER		= -c wiring -b 115200 -P /dev/ttyUSB0
PRGMER		= -c arduino -b 115200 -P /dev/ttyACM1
PRGMERISP	= -c avrispv2 -P /dev/ttyUSB0
#DUDE		= /usr/bin/avrdude -v -V -p $(MCU)
DUDE		= /usr/bin/avrdude -V -p $(MCU)

C_SRCS		= $(wildcard *.c)
OBJ_FILES	= $(C_SRCS:.c=.o)

all:		$(TARGET).hex

clean:	
			rm -f $(TARGET).elf *.o *.hex
			@echo $@ done

%.o: %.c
			@echo $@ 
			@echo $<
			$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

$(TARGET).elf: $(OBJ_FILES)
			$(CC) $(LDFLAGS) -o $@ $(OBJ_FILES)

$(TARGET).hex: $(TARGET).elf
			avr-objcopy -j .text -j .data -O ihex $(TARGET).elf $(TARGET).hex
			avr-objcopy -j .eeprom --set-section-flags=.eeprom="alloc,load" \
                        --change-section-lma .eeprom=0 -O ihex $(TARGET).elf eeprom.hex

upload: $(TARGET).hex size
			$(DUDE) $(PRGMER) -i 8 -U flash:w:$(TARGET).hex 

size: $(TARGET).elf
			avr-size -C --mcu=$(MCU) $(TARGET).elf

sizeofhex: $(TARGET).hex
			avr-size $(TARGET).hex

symbols: $(TARGET).elf
			@echo "\n---" headers and symbols for $< "---\n"
			avr-readelf -hs $(TARGET).elf | less
