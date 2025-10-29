# How to format printf output

`printf(f_string, var_args);`
## Examples

**_f_string_** is the format string, where you tell how to print the following values.\
**_var_args_** means the the number of args is variable and depends on the format string.

### Example 1:
s : string, d : int, f : float or double
```
int age = 123;
double pi=3.14159265358979;//float only goes to 6decimals
char* name = "bugs bunny";
printf("My name is %s, and I'm %d years old. I love %f", name, age, pi);
```
### Example 2:
d : int, c : character, X : upper case hexadecimal
```
unsigned int num = 0x41;
printf(" the number is %d [0x%X], and rerpesents %c \n", num, num, num);
```
## printf 
<details>
 
<summary>Complete List From man 3 printf avr-libc</summary>  

> The format string is composed of zero or more directives: ordinary characters (not %), which are copied unchanged to the output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments. Each conversion specification is introduced by the % character. The arguments must properly correspond (after type promotion) with the conversion specifier. After the %, the following appear in sequence:

       • Zero or more of the following flags:

         • # The value should be converted to an 'alternate form'. For c, d, i, s, and u conversions, this option has no effect. For o conversions, the
           precision of the number is increased to force the first character of the output string to a zero (except if a zero value is printed with an
           explicit precision of zero). For x and X conversions, a non-zero result has the string `0x' (or `0X' for X conversions) prepended to it.
         • 0 (zero) Zero padding. For all conversions, the converted value is padded on the left with zeros rather than blanks. If a precision is given
           with a numeric conversion (d, i, o, u, i, x, and X), the 0 flag is ignored.
         • - A negative field width flag; the converted value is to be left adjusted on the field boundary. The converted value is padded on the right
           with blanks, rather than on the left with blanks or zeros. A - overrides a 0 if both are given.
         •
         • + A sign must always be placed before a number produced by a signed conversion. A + overrides a space if both are used.
       • An optional decimal digit string specifying a minimum field width. If the converted value has fewer characters than the field width, it will be
         padded with spaces on the left (or right, if the left-adjustment flag has been given) to fill out the field width.
       • An optional precision, in the form of a period . followed by an optional digit string. If the digit string is omitted, the precision is taken as
         zero. This gives the minimum number of digits to appear for d, i, o, u, x, and X conversions, or the maximum number of characters to be printed
         from a string for s conversions.
       • An optional l or h length modifier, that specifies that the argument for the d, i, o, u, x, or X conversion is a 'long int' rather than int. The
         h is ignored, as 'short int' is equivalent to int.
       • A character that specifies the type of conversion to be applied.
       The conversion specifiers and their meanings are:
       • diouxX The int (or appropriate variant) argument is converted to signed decimal (d and i), unsigned octal (o), unsigned decimal (u), or unsigned
         hexadecimal (x and X) notation. The letters 'abcdef' are used for x conversions; the letters 'ABCDEF' are used for X conversions. The precision,
         if any, gives the minimum number of digits that must appear; if the converted value requires fewer digits, it is padded on the left with zeros.
       • p The void * argument is taken as an unsigned integer, and converted similarly as a %#x command would do.
       • c The int argument is converted to an 'unsigned char', and the resulting character is written.
       • s The 'char *' argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written
         up to (but not including) a terminating NUL character; if a precision is specified, no more than the number specified are written. If a
         precision is given, no null character need be present; if the precision is not specified, or is greater than the size of the array, the array
         must contain a terminating NUL character.
       • % A % is written. No argument is converted. The complete conversion specification is '%%'.
       • eE The double argument is rounded and converted in the format '[-]d.ddde±dd' where there is one digit before the decimal-point character and the
         number of digits after it is equal to the precision; if the precision is missing, it is taken as 6; if the precision is zero, no decimal-point
         character appears. An E conversion uses the letter 'E' (rather than 'e') to introduce the exponent. The exponent always contains two digits; if
         the value is zero, the exponent is 00.
       • fF The double argument is rounded and converted to decimal notation in the format '[-]ddd.ddd', where the number of digits after the decimal-
         point character is equal to the precision specification. If the precision is missing, it is taken as 6; if the precision is explicitly zero, no
         decimal-point character appears. If a decimal point appears, at least one digit appears before it.
       • gG The double argument is converted in style f or e (or F or E for G conversions). The precision specifies the number of significant digits. If
         the precision is missing, 6 digits are given; if the precision is zero, it is treated as 1. Style e is used if the exponent from its conversion
         is less than -4 or greater than or equal to the precision. Trailing zeros are removed from the fractional part of the result; a decimal point
         appears only if it is followed by at least one digit.
       • S Similar to the s format, except the pointer is expected to point to a program-memory (ROM) string instead of a RAM string.
       In no case does a non-existent or small field width cause truncation of a numeric field; if the result of a conversion is wider than the field
       width, the field is expanded to contain the conversion result.
       
  </details>
