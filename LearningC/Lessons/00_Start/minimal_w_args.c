/* arteknix
this is the version of minimal.c with command-line arguments
the official/historical way for main
*/
#include <stdio.h>
int main(int argc, char* argv[]){
  printf("Hello C!\n%d args, for program %s", argc, argv[0]);
  return 0;
}
