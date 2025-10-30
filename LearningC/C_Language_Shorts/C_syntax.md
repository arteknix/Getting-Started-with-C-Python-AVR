# The essentials of C Language Syntax

C is a language with static strong typing,
This means that you cannot change a variable's type or size once you've declared it.\
You can only use variables you previously declared (or included from other files)
### Index

> [Data Types](#variable-types) 
>   >  numbers \
>   >  arrays \
>   >  struct 
> 
> [Functions](#functions) \
> [Conditional Statements](#conditional) 
>  > if / then / else \
>  > switch / case
>  
> [Loop Statements](#loop)
>  > while / do \
>  > for
>  

## Variable Types

### Numbers:
> [!NOTE]
> **bool** `#include <stdbool.h>`:
>   > true or false 
> 
> **char** (signed/unsigned):
>   > 8-bit = 1 byte 
> 
> **short** (signed/unsigned):
>   > 2-byte 
> 
> **integer** (signed/unsigned):
>   > 4 8 16 byte depending on os/cpu 
> 
> **long** (signed/unsigned):
>   > longer integer. if you need more you can use _long long_
> 
> **float**:
>   > real number (8-bit?)
> 
> **double**:
>   > double precision real number (16-bit?)
>   

>  [!TIP]
>  For **intergers** we specify the size explicitly when it matters `#include <stdint.h>`:
>  -  uint8_t : unsigned 8 bit
>  -  int32_t : signed 32 bit
>    

### Arrays
Records of homogenous data. Technically it's like a **list**\
The classic example would be **char\* argv[]**\
which holds the list of parameters/arguments passed to a program.

### Struct
When we need several variables to describe an entitiy. we use **struct** (records of heterogenous data)

### Unions
Sometimes we need alternatives. A **union** could consist of a number and the text "Not Defined"

### Type defined
You can define your own types with **_typedef_**
```
typedef uint16_t banana;//0-65535
banaba bigNum = 1329:
```

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
Functions have a **prototype** which defines parameters and return value.
When you want to create a function you put the prototype at the beginning of the [source file](C_Files.md#source) or in the [header file](C_Files.md#header)
> [!NOTE]
> **prototype**
>  ```
>  <return-type> <function-name> (<arguments>);
>  ```
>
> **declaration**
>  ``` 
>  <return-type> <function-name> (<arguments>){
>  <function-body>
>  return <return-value>;
>  }
>  ```
>  

## Conditional

## Loop

## Preprocessor Directives
They start with a hash **#** and should be declared at the top of the file.
> [!NOTE]
> Commonly we use:
> ```
> #include <header-file> 
> #define UPPERCASE_NAME <substitution> //Macro definition
> ```
>

> [!TIP]
>  A classical example of Macro definition 
>  `#define MAX(A,B) ((A)>(B)?(A):(B))` \
>  in brackets for the case where A or B is am expresion which has to be evaluated first
>
>  For `#include` [headers](C_Files.md#header)
> 
