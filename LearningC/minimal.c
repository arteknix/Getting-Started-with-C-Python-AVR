/* ©arteknix : code in C/minimal.c 
 * simplest C program
 * using printf (man printf)
 * to print a string to stdout (terminal)
 * 
 * compile it:  gcc minimal.c -o minimal 
 * run it:	./minimal */

/* header files 
 * std 	= standard
 * io 	= input/output */

#include <stdio.h> //printf 

/* main function: compulsary for program
 * if there is no main, you create a library
 * takes no argument (void)
 * has to return an "int" for exit status */

int main(void){
	printf("\nHello C\n");	// "\n" means newline
	return 0;
}

/* Notes :
 * two types of comments 
 * */

/* ***********************
 * Traditional C comments, 
 * multiline 
 * ***********************/
// C++ comments. single line
