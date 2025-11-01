#include "extras.h"

/**/
void
printSome(void)
{
  //variable declarations and initialisations
  int   age = 123;
  float pi = 3.14159265358979;
  char* name  = "bugs bunny";
  banana bigNum = 1329;
  printf("%d\n",bigNum);
  printf("\nHello C - %s - !\nMy name is %s, and I'm %d years old. I love %f π \n", __FILE__,  name, age, pi);
}

/**/
void
printMore(int num, char* table[])
{
    for(int i = 0; i<num; i++)
    {
      printf("table[%d] = %s \n",i,table[i]);
    }
}

