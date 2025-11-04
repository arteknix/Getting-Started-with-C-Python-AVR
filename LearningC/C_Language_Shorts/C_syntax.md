# The essentials of C Language Syntax

C is a language with static strong typing,
This means that you cannot change a variable's type or size once you've declared it.\
You can only use variables you previously declared (or included from other files)

## Instructions and blocs
>[!IMPORTANT]
> every instruction ends with a **semi-colon** **;**\
> a bloc contains instructions and is delimted by **{** and **}**\
> variables defined inside a block, are not known outside of this bloc\
> ==> there will be a separate part on **scope of variables**

>[!TIP]
> Start using a good coding style for readability right from the start
> examples:
> ```
> for(;;){// loop other ....
>   ...
> }
> if () {// condition1
>   ...
> }
> else {// condition2 
>   ...
> }//endif
> 
> ```
> 

>[!NOTE]
> Use comments to document immediately
> ```
> if () // we use option 1
> {
>  ...
> }
> else // default
> {
>  ...
> }//endif
> ```
  
## Index

> [Data Types](#variable-types) 
>   >  numbers \
>   >  arrays \
>   >  struct \
>   >  union  \
>   >  enum \
>   >  void \
>   >  pointer
> 
> [Operators](#operators) 
> 
> [Functions](#functions)
>  
> [Conditional Statements](#conditional) 
>  > if / else \
>  > switch / case
>  
> [Loop Statements](#loop)
>  > while / do \
>  > for
>
> [Preprocessor Directives](#preprocessor-directives)
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
>   > real number (4 byte)
> 
> **double**:
>   > double precision real number (8 byte)
>   

>  [!TIP]
>  For **intergers** we specify the size explicitly when it matters `#include <stdint.h>`:
>  -  uint8_t : unsigned 8 bit
>  -  int32_t : signed 32 bit
>    

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

### Enums
This is a handy type, for example for tracking states of a device:
```
enum device_status{
  DEVICE_OK = 0,
  DEVICE_CONNECTED,
  DEVICE_LOST = 10
}
...
  if (device_status == DEVICE_OK) {...}
```
  enums are NAMES for constants. It's like:  
```
#define DEVICE_OK 0
#define DEVICE_CONNECTED 1
```

### Arrays
Records of homogenous data. Technically it's like a **list**\
The classic example would be **char\* argv[]**\
which holds the list of parameters/arguments passed to a program.
```
  char buffer[26] = "the dark side of the moon";
  buffer[2] : would be "e", because indices start at 0 
```

### Struct
When we need several variables to describe an entitiy, we use **struct** (records of heterogenous data)
```
struct{
  float x = 0.707;
  float y = 0.707;
} point; // defines point as a struct containing 2 real values (coordinates)
point.x is 0.707 (sqrt(2)/2 ;-))  
```

### Unions
Sometimes we need alternatives. A **union** could consist of a number and the text "Not Defined" \
Both variables are stored in the same memory location, so I can have one or the other \
Perfect in this case:

```
union test{
    char* status;
    int value ;
};
```

### Type defined
You can define your own types with **_typedef_**
```
typedef uint16_t banana;//0-65535
banana bigNum = 1329:
```

### Other/Any
```
void : no variable/value
<datatype>* p : is a pointer to variable of type <datatype>
pointer : an address in memory
*pointer : value stored at this address
&<variable> : memory address of <variable>
```

## Operators

### arithmetic
```
a <op> b, where <op> is one of:
  + - * / % (modulo)
```
### assignment
```
  = : a = b, assign value of b to a
  += : a+=3 <=> a = a + 3;
  -= , *= , /= , ...
```
### comparison
```
  == : is equal
  != : is not equal
  <= : is less or equal
  => : is greater or equal
  <  : less
  >  : more 
```
### unary
```
<op>a, where <op> is one of:
  & * ~ -
```

### incremental
```
<op>a or a<op>, where <op> is one of:
  ++ (+=1) -- (-=1) 
```
### accessing
```
A.a where A is a struct
  returns elemement a
*A.a == A->a : where A is a pointer to a struct
  returns elemement a
A[i] where A is an array
  returns the i-th element of A
```

### bitwise
```
a<op>b, where <op> is one of:
  & (and) | (or) ^ (xor) ~ (not)
```
These are extremely important for configuring µControllers,\
Ther will be an exercise just for this topic

### logic
```
a<op>b, where <op> is one of:
  && (and) || (or) ^ (xor) ! (not)
```

## Functions
Functions have a **prototype** which defines parameters and return value.
When you want to create a function you put the prototype at the beginning of the [source file](C_Files.md#source) or in the [header file](C_Files.md#header)
> [!NOTE]
> **prototype declaration**
>  ```
>  <return-type> <function-name> (<arguments>);
>  ```
>
> **definition**
>  ``` 
>  <return-type> <function-name> (<arguments>){
>  <function-body>
>  return <return-value>;
>  }
>  ```
>
> example:
> > in header
> > ```
> > float norm(float x, float y);
> > ```
> > in source
> > ```
> > float norm(float x, float y){ 
> >   return sqrt(x*x + y*y);
> > }
> >```
> 

>  [!TIP]
>  **main** from the _main program_ is the **main function** \
>  taking **argc, argv** as arguments and \
>  **returning an int** as status  ( 0 = success)
>    

## Conditional

Conditional statements are only executed under certain conditions
> ***Conditions wear bras***
> parenthesize

### if-else
```
  if (condition1)
  {}
  else if (condition2)
  {}
  ...
  else
  {} 
```
### switch-case
```
  switch (<test>):
    case (result A):
        ...
        break;
    case (result B):
        ...
        break;
    case (result C):
        ...
        break;
    ...
    default: // unexpected or obvious
        ...
        break;
``` 

## Loop
Loops run several times depending on an exit condition

### while-do
```
while (<condition>) do {}
  only if condition true
  checks condition BEFORE execution
do {} while (<condition>)
  at least once
  checks condition AFTER execution
```
### for
⚠️ **semi-colon** **;**
```
  for(iterator; end_condition; increment){}
  for(int i = 0; i<10; i++){}
```
### break and continue
```
  break;// get out of the loop (if some condition is met)
  continue;// go to next iteration of the loop (if some condition is met)
```

## Preprocessor Directives
They start with a hash **#** and should be declared at the top of the file.
> [!NOTE]
> Commonly we use:
> ```
> #include <header-file> 
> #define UPPERCASE_NAME <substitution> //Macro definition
> ```

> [!IMPORTANT]
> we use the following to compile only code we need
> ```
> #if
> #else // or #elseif
> #endif
> #if defined
> #ifdef
> #if not defined
> #ifndef
> ```
> we use the following to avoid multiple inclusdion of headers
> ```
> #ifndef _THIS_HEADER_H_ //first line of this_header.h
> #define _THIS_HEADER_H_
> ...
> #endif //last line of this_header.h
> ```

> [!TIP]
>  A classical example of Macro definition 
>  `#define MAX(A,B) ((A)>(B)?(A):(B))` \
>  in brackets for the case where A or B is am expresion which has to be evaluated first
>
>  For `#include` [headers](C_Files.md#header)
>

## Further Reference
>[!NOTE]
> This document is more a C cheat-sheet \
> If you want a complete tutorial, there are many
> A good starting point would be on [geeksforgeeks](https://www.geeksforgeeks.org/c/c-programming-language/)
