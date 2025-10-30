# The essentials of C Language Syntax

C is a language with static strong typing,
This means that you cannot change a variable's type or size once you've declared it.\
You can only use variables you previously declared (or included from other files)

## Variable Types

### Numbers:
- bool `#include <stdbool.h>`
  - true or false
- char (signed/unsigned)
  - 8-bit = 1 byte
- short (signed/unsigned)
  - 2-byte 
- integer (signed/unsigned)
  - 4 8 16 byte depending on os/cpu
- long (signed/unsigned)
  - longer integer. if you need more you can use _long long_
- float
  - real number 
- double
  - double precision real number

>  [!NOTE]
>  For **intergers** we specify the size explicitly when it matters:
>  -  uint8_t : unsigned 8 bit
>  -  int32_t : signed 32 bit

### Arrays
Records of homogenous data. Technically it's like a **list**\
The classic example would be ** char* argv[] **\
which holds the list of parameters/arguments passed to a program,
### Struct
When we need several variables to describe an entitiy. we use **struct** (records of heterogenous data)

### Unions
Sometimes we need alternatives. A **union** could consist of a number and the text "Not Defined"

### Type defined
You can define your own types with **_typedef_**

### Other/Any
void: no variable/value

<details>
<summary> More on type "int" </summary>
Check man stdint.h
  
Integers can be prefixed with _unsigned_
- As an example take _char_ which is 8 bit long, 2^8 = 256 values
  - char is from -128 to 127  [ -(2^8) /2 ; ((2^8) /2)-1 ]
  - unsigned char from 0 to 255 [ 0 ; (2^8)-1 ]

Integers can be:
- long (l)
- unsigned long (ul)
- long long (ll)
- unsigned long long (ull)
If you want to know how many bits they are, you can call the _sizeof() function_
</details>

## Functions

## Conditional

## Loop

## Preprocessor Directives
