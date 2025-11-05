# C++ in the Arduino world
>[!WARNING]
> No details here\
> Just hints on how the Arduino Magic works
> 
## More features on top of C

C++ is based on C, has the same syntax, apart from a few exceptions, and adds a few features.

Main improvements concern Object Oriented Programming.\
Thus it is possible to use ***classes*** and ***operator overload***.\
A huge difference concerns functions, by allowing the same function name for different signatures (sets of parameters).\
Example for an object representing a serial port:
```
Serial.begin();
Serial.begin(115200);
```
Overloading operators comes in handy for example for adding Strings: 
```
String s1 = "123";
String s2 = "abc";
s1+" "+s2; //ok
```
Memory allocation is handeled with _new_ and _delete_ instead of _malloc_ and _free_.

## Arduino Language

The Arduino language is C++ with a few extras, noticably initializing objects whithout the user having to worry about these details.\
Low-level functions are written in C, which is natural for coding hardware.\
Real genious. Again, using Serial:
```
Serial.begin();
```
Means I can call method begin() of object Serial without having to call the constructor explicitly like I would do in C++:
```
Serial = new SerialClass():
```
In fact this is done in HardwareSerial.h
```
#if defined(UBRRH) || defined(UBRR0H)
  extern HardwareSerial Serial;
  #define HAVE_HWSERIAL0
#endif
```
Inheritance and polymorphism are widely used for functionality in Arduino. 
Once more with Serial:
```
class HardwareSerial : public Stream // inherits Stream
class Stream : public Print  // inherits Print
class Print // has no parent
```
💡 So the print methods in Serial class come from Print class.
