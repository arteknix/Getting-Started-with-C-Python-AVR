/* ©arteknix
this is the version of minimal.c with some more printf
*/
#include <stdio.h>
int main(void){
  /*variable declarations and initialisations*/
  int   age   = 123;
  float pi    = 3.14159265358979;
  char* name  = "bugs bunny";
  /**/
  printf("My name is %s, and I'm %d years old. I love %f", name, age, pi);
  return 0;
}
