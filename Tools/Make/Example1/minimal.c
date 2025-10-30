/*
©arteknix
example with more printf formatting
*/
#include <stdio.h>

int main(void){
	unsigned int num = 0x41;
	int age = 123;
	double pi=3.14159265358979;
	char * name = "bugs bunny";

	printf("\nHello C\n");	// "\n" means newline
	printf(" the number is %d [0x%X], and rerpesents \'%c\' \n", num, num, num);
	printf(" My name is %s, and I'm %d years old.\n I love %14.14f\n", name, age, pi);
	return 0;
}
