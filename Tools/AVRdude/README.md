# AVRdude

>[!IMPORTANT]
> the work put in this wonderfull piece of software over the years is amazing

## Commandline
>[!TIP]
> The minimum parameters for uploading your code to an AVR device:
> ```
> avrdude -p <partno> -c <programmer> -P <port> -b <baudrate> -U flash:w:<filename>
> ```
> where file is in intel hex format (format=i), so filename is 'filename.hex'\
> in a **Makefile** (for ***blink/uno***) you would define them so:
> ```
>   TARGET    = blink
>   MCU       = atmega328p // for avr-gcc
>   PART      = m328p 
>   DUDE      = /usr/bin/avrdude -V -p $(PART)
>   PRGMER	= -c arduino -b 115200 -P /dev/ttyACM0 # modify to match your device
>   PRGMERISP	= -c avrispv2 -P /dev/ttyUSB0 # ISP over SPI, modify to match device
>
>   ...
> 
>   upload: $(TARGET).hex
>			$(DUDE) $(PRGMER) -i 8 -U flash:w:$(TARGET).hex
> 
>   isp_upload: $(TARGET).hex
>			$(DUDE) $(PRGMERISP) -i 8 -U flash:w:$(TARGET).hex 
> ```

<details>
  <summary>Cmd Line Options</summary>
  
  ```
    Usage: avrdude [options]
    Options:
      -p <partno>                Specify AVR device
      -p <wildcard>/<flags>      Run developer options for matched AVR devices
      -b <baudrate>              Override RS-232 baud rate
      -B <bitclock>              Specify bit clock period (us)
      -C <config-file>           Specify location of configuration file
      -c <programmer>            Specify programmer type
      -c <wildcard>/<flags>      Run developer options for matched programmers
      -A                         Disable trailing-0xff removal from file and AVR read
      -D                         Disable auto erase for flash memory; implies -A
      -i <delay>                 ISP Clock Delay [in microseconds]
      -P <port>                  Specify connection port
      -F                         Override invalid signature or initialisation check
      -e                         Perform a chip erase
      -O                         Perform RC oscillator calibration (see AVR053)
      -U <memtype>:r|w|v:<filename>[:format]
                                 Memory operation specification
                                 Multiple -U options are allowed, each request
                                 is performed in the order specified
      -n                         Do not write anything to the device
      -V                         Do not verify
      -t                         Enter terminal mode
      -E <exitspec>[,<exitspec>] List programmer exit specifications
      -x <extended_param>        Pass <extended_param> to programmer
      -v                         Verbose output; -v -v for more
      -q                         Quell progress output; -q -q for less
      -l logfile                 Use logfile rather than stderr for diagnostics
      -?                         Display this usage

    avrdude version 7.1, URL: <https://github.com/avrdudes/avrdude>
  ```
</details>

## Boards

<details>
  <summary> <b>314</b> supported boards in version 7.1 </summary>

  ```
Valid parts are:
  uc3a0512   = AT32UC3A0512
  c128       = AT90CAN128
  c32        = AT90CAN32
  c64        = AT90CAN64
  pwm2       = AT90PWM2
  pwm216     = AT90PWM216
  pwm2b      = AT90PWM2B
  pwm3       = AT90PWM3
  pwm316     = AT90PWM316
  pwm3b      = AT90PWM3B
  1200       = AT90S1200
  2313       = AT90S2313
  2333       = AT90S2333
  2343       = AT90S2343
  4414       = AT90S4414
  4433       = AT90S4433
  4434       = AT90S4434
  8515       = AT90S8515
  8535       = AT90S8535
  usb1286    = AT90USB1286
  usb1287    = AT90USB1287
  usb162     = AT90USB162
  usb646     = AT90USB646
  usb647     = AT90USB647
  usb82      = AT90USB82
  m103       = ATmega103
  m128       = ATmega128
  m1280      = ATmega1280
  m1281      = ATmega1281
  m1284      = ATmega1284
  m1284p     = ATmega1284P
  m1284rfr2  = ATmega1284RFR2
  m128a      = ATmega128A
  m128rfa1   = ATmega128RFA1
  m128rfr2   = ATmega128RFR2
  m16        = ATmega16
  m1608      = ATmega1608
  m1609      = ATmega1609
  m161       = ATmega161
  m162       = ATmega162
  m163       = ATmega163
  m164a      = ATmega164A
  m164p      = ATmega164P
  m164pa     = ATmega164PA
  m165       = ATmega165
  m165a      = ATmega165A
  m165p      = ATmega165P
  m165pa     = ATmega165PA
  m168       = ATmega168
  m168a      = ATmega168A
  m168p      = ATmega168P
  m168pa     = ATmega168PA
  m168pb     = ATmega168PB
  m169       = ATmega169
  m169a      = ATmega169A
  m169p      = ATmega169P
  m169pa     = ATmega169PA
  m16a       = ATmega16A
  m16u2      = ATmega16U2
  m16u4      = ATmega16U4
  m2560      = ATmega2560
  m2561      = ATmega2561
  m2564rfr2  = ATmega2564RFR2
  m256rfr2   = ATmega256RFR2
  m32        = ATmega32
  m3208      = ATmega3208
  m3209      = ATmega3209
  m324a      = ATmega324A
  m324p      = ATmega324P
  m324pa     = ATmega324PA
  m324pb     = ATmega324PB
  m325       = ATmega325
  m3250      = ATmega3250
  m3250a     = ATmega3250A
  m3250p     = ATmega3250P
  m3250pa    = ATmega3250PA
  m325a      = ATmega325A
  m325p      = ATmega325P
  m325pa     = ATmega325PA
  m328       = ATmega328
  m328p      = ATmega328P
  m328pb     = ATmega328PB
  m329       = ATmega329
  m3290      = ATmega3290
  m3290a     = ATmega3290A
  m3290p     = ATmega3290P
  m3290pa    = ATmega3290PA
  m329a      = ATmega329A
  m329p      = ATmega329P
  m329pa     = ATmega329PA
  m32a       = ATmega32A
  m32m1      = ATmega32M1
  m32u2      = ATmega32U2
  m32u4      = ATmega32U4
  m406       = ATmega406
  m48        = ATmega48
  m4808      = ATmega4808
  m4809      = ATmega4809
  m48a       = ATmega48A
  m48p       = ATmega48P
  m48pa      = ATmega48PA
  m48pb      = ATmega48PB
  m64        = ATmega64
  m640       = ATmega640
  m644       = ATmega644
  m644a      = ATmega644A
  m644p      = ATmega644P
  m644pa     = ATmega644PA
  m644rfr2   = ATmega644RFR2
  m645       = ATmega645
  m6450      = ATmega6450
  m6450a     = ATmega6450A
  m6450p     = ATmega6450P
  m645a      = ATmega645A
  m645p      = ATmega645P
  m649       = ATmega649
  m6490      = ATmega6490
  m6490a     = ATmega6490A
  m6490p     = ATmega6490P
  m649a      = ATmega649A
  m649p      = ATmega649P
  m64a       = ATmega64A
  m64m1      = ATmega64M1
  m64rfr2    = ATmega64RFR2
  m8         = ATmega8
  m808       = ATmega808
  m809       = ATmega809
  m8515      = ATmega8515
  m8535      = ATmega8535
  m88        = ATmega88
  m88a       = ATmega88A
  m88p       = ATmega88P
  m88pa      = ATmega88PA
  m88pb      = ATmega88PB
  m8a        = ATmega8A
  m8u2       = ATmega8U2
  t10        = ATtiny10
  t102       = ATtiny102
  t104       = ATtiny104
  t11        = ATtiny11
  t12        = ATtiny12
  t13        = ATtiny13
  t13a       = ATtiny13A
  t15        = ATtiny15
  t1604      = ATtiny1604
  t1606      = ATtiny1606
  t1607      = ATtiny1607
  t1614      = ATtiny1614
  t1616      = ATtiny1616
  t1617      = ATtiny1617
  t1624      = ATtiny1624
  t1626      = ATtiny1626
  t1627      = ATtiny1627
  t1634      = ATtiny1634
  t1634r     = ATtiny1634R
  t167       = ATtiny167
  t20        = ATtiny20
  t202       = ATtiny202
  t204       = ATtiny204
  t212       = ATtiny212
  t214       = ATtiny214
  t2313      = ATtiny2313
  t2313a     = ATtiny2313A
  t24        = ATtiny24
  t24a       = ATtiny24A
  t25        = ATtiny25
  t26        = ATtiny26
  t261       = ATtiny261
  t261a      = ATtiny261A
  t28        = ATtiny28
  t3216      = ATtiny3216
  t3217      = ATtiny3217
  t3224      = ATtiny3224
  t3226      = ATtiny3226
  t3227      = ATtiny3227
  t4         = ATtiny4
  t40        = ATtiny40
  t402       = ATtiny402
  t404       = ATtiny404
  t406       = ATtiny406
  t412       = ATtiny412
  t414       = ATtiny414
  t416       = ATtiny416
  t417       = ATtiny417
  t424       = ATtiny424
  t426       = ATtiny426
  t427       = ATtiny427
  t4313      = ATtiny4313
  t43u       = ATtiny43U
  t44        = ATtiny44
  t441       = ATtiny441
  t44a       = ATtiny44A
  t45        = ATtiny45
  t461       = ATtiny461
  t461a      = ATtiny461A
  t48        = ATtiny48
  t5         = ATtiny5
  t804       = ATtiny804
  t806       = ATtiny806
  t807       = ATtiny807
  t814       = ATtiny814
  t816       = ATtiny816
  t817       = ATtiny817
  t824       = ATtiny824
  t826       = ATtiny826
  t827       = ATtiny827
  t828       = ATtiny828
  t828r      = ATtiny828R
  t84        = ATtiny84
  t841       = ATtiny841
  t84a       = ATtiny84A
  t85        = ATtiny85
  t861       = ATtiny861
  t861a      = ATtiny861A
  t87        = ATtiny87
  t88        = ATtiny88
  t9         = ATtiny9
  x128a1     = ATxmega128A1
  x128a1d    = ATxmega128A1revD
  x128a1u    = ATxmega128A1U
  x128a3     = ATxmega128A3
  x128a3u    = ATxmega128A3U
  x128a4     = ATxmega128A4
  x128a4u    = ATxmega128A4U
  x128b1     = ATxmega128B1
  x128b3     = ATxmega128B3
  x128c3     = ATxmega128C3
  x128d3     = ATxmega128D3
  x128d4     = ATxmega128D4
  x16a4      = ATxmega16A4
  x16a4u     = ATxmega16A4U
  x16c4      = ATxmega16C4
  x16d4      = ATxmega16D4
  x16e5      = ATxmega16E5
  x192a1     = ATxmega192A1
  x192a3     = ATxmega192A3
  x192a3u    = ATxmega192A3U
  x192c3     = ATxmega192C3
  x192d3     = ATxmega192D3
  x256a1     = ATxmega256A1
  x256a3     = ATxmega256A3
  x256a3b    = ATxmega256A3B
  x256a3bu   = ATxmega256A3BU
  x256a3u    = ATxmega256A3U
  x256c3     = ATxmega256C3
  x256d3     = ATxmega256D3
  x32a4      = ATxmega32A4
  x32a4u     = ATxmega32A4U
  x32c4      = ATxmega32C4
  x32d4      = ATxmega32D4
  x32e5      = ATxmega32E5
  x384c3     = ATxmega384C3
  x384d3     = ATxmega384D3
  x64a1      = ATxmega64A1
  x64a1u     = ATxmega64A1U
  x64a3      = ATxmega64A3
  x64a3u     = ATxmega64A3U
  x64a4      = ATxmega64A4
  x64a4u     = ATxmega64A4U
  x64b1      = ATxmega64B1
  x64b3      = ATxmega64B3
  x64c3      = ATxmega64C3
  x64d3      = ATxmega64D3
  x64d4      = ATxmega64D4
  x8e5       = ATxmega8E5
  avr128da28 = AVR128DA28
  avr128da32 = AVR128DA32
  avr128da48 = AVR128DA48
  avr128da64 = AVR128DA64
  avr128db28 = AVR128DB28
  avr128db32 = AVR128DB32
  avr128db48 = AVR128DB48
  avr128db64 = AVR128DB64
  avr16dd14  = AVR16DD14
  avr16dd20  = AVR16DD20
  avr16dd28  = AVR16DD28
  avr16dd32  = AVR16DD32
  avr16ea28  = AVR16EA28
  avr16ea32  = AVR16EA32
  avr16ea48  = AVR16EA48
  avr32da28  = AVR32DA28
  avr32da32  = AVR32DA32
  avr32da48  = AVR32DA48
  avr32db28  = AVR32DB28
  avr32db32  = AVR32DB32
  avr32db48  = AVR32DB48
  avr32dd14  = AVR32DD14
  avr32dd20  = AVR32DD20
  avr32dd28  = AVR32DD28
  avr32dd32  = AVR32DD32
  avr32ea28  = AVR32EA28
  avr32ea32  = AVR32EA32
  avr32ea48  = AVR32EA48
  avr64da28  = AVR64DA28
  avr64da32  = AVR64DA32
  avr64da48  = AVR64DA48
  avr64da64  = AVR64DA64
  avr64db28  = AVR64DB28
  avr64db32  = AVR64DB32
  avr64db48  = AVR64DB48
  avr64db64  = AVR64DB64
  avr64dd14  = AVR64DD14
  avr64dd20  = AVR64DD20
  avr64dd28  = AVR64DD28
  avr64dd32  = AVR64DD32
  avr64ea28  = AVR64EA28
  avr64ea32  = AVR64EA32
  avr64ea48  = AVR64EA48
  avr8ea28   = AVR8EA28
  avr8ea32   = AVR8EA32
  ucr2       = deprecated, use 'uc3a0512'
  lgt8f168p  = LGT8F168P
  lgt8f328p  = LGT8F328P
  lgt8f88p   = LGT8F88P
  ```

</details>

## Programmers

<details>
  <summary> <b>126</b> programmers for version 7.1 </summary>

  ```
  Valid programmers are:
  2232hio            = 2232hio based on FT2232H with buffer and LEDs
  4232h              = FT4232H based generic programmer
  adafruit_gemma     = Adafruit Trinket Gemma bootloader disguised as USBtiny
  arduino            = Arduino for bootloader using STK500 v1 protocol
  arduino-ft232r     = Arduino: FT232R connected to ISP
  arduino_gemma      = Arduino Gemma bootloader disguised as USBtiny
  arduinoisp         = Arduino ISP Programmer
  arduinoisporg      = Arduino ISP Programmer
  atmelice           = Atmel-ICE (ARM/AVR) in JTAG mode
  atmelice_dw        = Atmel-ICE (ARM/AVR) in debugWIRE mode
  atmelice_isp       = Atmel-ICE (ARM/AVR) in ISP mode
  atmelice_pdi       = Atmel-ICE (ARM/AVR) in PDI mode
  atmelice_tpi       = Atmel-ICE (ARM/AVR) in TPI mode
  atmelice_updi      = Atmel-ICE (ARM/AVR) in UPDI mode
  avr109             = Atmel for bootloader using AppNote AVR109
  avr910             = Atmel Low Cost Serial Programmer
  avr911             = Atmel for bootloader using AppNote AVR911 AVROSP
  avrftdi            = FT2232D based generic programmer
  avrisp             = Atmel AVR ISP
  avrisp2            = Atmel AVR ISP mkII
  avrispmkII         = Atmel AVR ISP mkII
  avrispv2           = Atmel AVR ISP v2
  buspirate          = The Bus Pirate
  buspirate_bb       = The Bus Pirate (bitbang interface, supports TPI)
  butterfly          = Atmel for bootloader (Butterfly Development Board)
  butterfly_mk       = Mikrokopter.de Butterfly for bootloader
  bwmega             = BitWizard ftdi_atmega builtin programmer
  c232hm             = C232HM cable from FTDI
  c2n232i            = serial port banging, reset=dtr sck=!rts sdo=!txd sdi=!cts
  dasa               = serial port banging, reset=rts sck=dtr sdo=txd sdi=cts
  dasa3              = serial port banging, reset=!dtr sck=rts sdo=txd sdi=cts
  diecimila          = alias for arduino-ft232r
  digilent-hs2       = Digilient JTAG HS2 (MPSSE)
  dragon_dw          = Atmel AVR Dragon in debugWire mode
  dragon_hvsp        = Atmel AVR Dragon in HVSP mode
  dragon_isp         = Atmel AVR Dragon in ISP mode
  dragon_jtag        = Atmel AVR Dragon in JTAG mode
  dragon_pdi         = Atmel AVR Dragon in PDI mode
  dragon_pp          = Atmel AVR Dragon in PP mode
  ehajo-isp          = avr-isp-programmer from eHaJo, http://www.eHaJo.de
  flip1              = FLIP for bootloader using USB DFU protocol version 1 (doc7618)
  flip2              = FLIP for bootloader using USB DFU protocol version 2 (AVR4023)
  ft2232h            = FT2232H based generic programmer
  ft232h             = FT232H based generic programmer
  ft232r             = FT232R based generic programmer
  ft245r             = FT245R based generic programmer
  ft4232h            = FT4232H based generic programmer
  iseavrprog         = USBtiny-based programmer, https://iascaled.com
  jtag1              = Atmel JTAG ICE (mkI)
  jtag1slow          = Atmel JTAG ICE (mkI)
  jtag2              = Atmel JTAG ICE mkII
  jtag2avr32         = Atmel JTAG ICE mkII in AVR32 mode
  jtag2dw            = Atmel JTAG ICE mkII in debugWire mode
  jtag2fast          = Atmel JTAG ICE mkII
  jtag2isp           = Atmel JTAG ICE mkII in ISP mode
  jtag2pdi           = Atmel JTAG ICE mkII in PDI mode
  jtag2slow          = Atmel JTAG ICE mkII
  jtag2updi          = JTAGv2 to UPDI bridge
  jtag3              = Atmel AVR JTAGICE3 in JTAG mode
  jtag3dw            = Atmel AVR JTAGICE3 in debugWIRE mode
  jtag3isp           = Atmel AVR JTAGICE3 in ISP mode
  jtag3pdi           = Atmel AVR JTAGICE3 in PDI mode
  jtag3updi          = Atmel AVR JTAGICE3 in UPDI mode
  jtagkey            = Amontec JTAGKey, JTAGKey-Tiny and JTAGKey2
  jtagmkI            = Atmel JTAG ICE (mkI)
  jtagmkII           = Atmel JTAG ICE mkII
  jtagmkII_avr32     = Atmel JTAG ICE mkII in AVR32 mode
  ktlink             = KT-LINK FT2232H interface with IO switching and voltage buffers.
  linuxspi           = Use Linux SPI device in /dev/spidev*
  lm3s811            = Luminary Micro LM3S811 Eval Board (Rev. A)
  mib510             = Crossbow MIB510 programming board
  micronucleus       = Micronucleus for bootloader
  mkbutterfly        = Mikrokopter.de Butterfly for bootloader
  nibobee            = NIBObee
  o-link             = O-Link, OpenJTAG from www.100ask.net
  openmoko           = Openmoko debug board (v3)
  pavr               = Jason Kyle's pAVR Serial Programmer
  pickit2            = MicroChip's PICkit2 Programmer
  pickit4            = MPLAB(R) PICkit 4 in JTAG mode
  pickit4_isp        = MPLAB(R) PICkit 4 in ISP mode
  pickit4_pdi        = MPLAB(R) PICkit 4 in PDI mode
  pickit4_tpi        = MPLAB(R) PICkit 4 in TPI mode
  pickit4_updi       = MPLAB(R) PICkit 4 in UPDI mode
  pkobn_updi         = Curiosity nano (nEDBG) in UPDI mode
  ponyser            = design ponyprog serial, reset=!txd sck=rts sdo=dtr sdi=cts
  powerdebugger      = Atmel PowerDebugger (ARM/AVR) in JTAG mode
  powerdebugger_dw   = Atmel PowerDebugger (ARM/AVR) in debugWire mode
  powerdebugger_isp  = Atmel PowerDebugger (ARM/AVR) in ISP mode
  powerdebugger_pdi  = Atmel PowerDebugger (ARM/AVR) in PDI mode
  powerdebugger_tpi  = Atmel PowerDebugger (ARM/AVR) in TPI mode
  powerdebugger_updi = Atmel PowerDebugger (ARM/AVR) in UPDI mode
  serialupdi         = SerialUPDI
  siprog             = Lancos SI-Prog <http://www.lancos.com/siprogsch.html>
  snap               = MPLAB(R) Snap in JTAG mode
  snap_isp           = MPLAB(R) SNAP in ISP mode
  snap_pdi           = MPLAB(R) SNAP in PDI mode
  snap_tpi           = MPLAB(R) SNAP in TPI mode
  snap_updi          = MPLAB(R) SNAP in UPDI mode
  stk500             = Atmel STK500
  stk500hvsp         = Atmel STK500 v2 in high-voltage serial programming mode
  stk500pp           = Atmel STK500 v2 in parallel programming mode
  stk500v1           = Atmel STK500 version 1.x firmware
  stk500v2           = Atmel STK500 version 2.x firmware
  stk600             = Atmel STK600
  stk600hvsp         = Atmel STK600 in high-voltage serial programming mode
  stk600pp           = Atmel STK600 in parallel programming mode
  tc2030             = Tag-Connect TC2030
  teensy             = Teensy for bootloader
  tigard             = Tigard interface board
  ttl232r            = FTDI TTL232R-5V with ICSP adapter
  tumpa              = TIAO USB Multi-Protocol Adapter
  um232h             = UM232H module from FTDI
  uncompatino        = uncompatino with all pairs of pins shorted
  urclock            = Urclock programmer for urboot bootloaders using urprotocol
  usbasp             = USBasp, http://www.fischl.de/usbasp/
  usbasp-clone       = Any usbasp clone with correct VID/PID
  usbtiny            = USBtiny simple USB programmer, https://learn.adafruit.com/usbtinyisp
  wiring             = Wiring for bootloader using STK500 v2 protocol
  xbee               = XBee for Series 2 Over-The-Air (XBeeBoot) bootloader using STK500 v1 protocol
  xplainedmini       = Atmel AVR XplainedMini in ISP mode
  xplainedmini_dw    = Atmel AVR XplainedMini in debugWIRE mode
  xplainedmini_tpi   = Atmel AVR XplainedMini in TPI mode
  xplainedmini_updi  = Atmel AVR XplainedMini in UPDI mode
  xplainedpro        = Atmel AVR XplainedPro in JTAG mode
  xplainedpro_pdi    = Atmel AVR XplainedPro in PDI mode
  xplainedpro_updi   = Atmel AVR XplainedPro in UPDI mode
  ```

</details>

## Memory r/w
> ```-U <memtype>:r|w|v:<filename>[:format]```
> 
Mostly used for reading-writing-verifying FLASH and setting FUSES

### saving your sketch to a file
>[!TIP]
> you have some working code on your AVR and you want to save it to a file before flashing new code:\
>```
> avrdude -p m328p -c arduino -P /dev/ttyACM2 -b 115200 -U flash:r:arducam.hex:i
>```
> in this example I had a program for using an ArduCam Camera shield.
 
## Fuses
⚠️ ***dont touch FUSES if you dont know what you're doing, you could LOCK YOUR DEVICE***
...
