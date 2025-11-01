/* arteknix
this is an example with more sources and headers
compiled separately
*/
#include <stdio.h> // first system
#include "extras.h" // then local

int
main(int argc, char* argv[])
{
  printf("\nHello C - %s [%s] -\n", __FILE__, __DATE__);
  printSome();
  printMore(argc,argv);
  return 0;
}



//printf("\nHello C -with args- !\n%d args, for program %s\n", argc, argv[0]);
