/*============================================================================
 Name        : Test21.c
 Author      : Dunno, but it's concisely set up.
 Version     : 1.00
 Copyright   : Your copyright notice
 Date        : 01/07-2021
 Source      : https://www.tutorialspoint.com/cprogramming/c_command_line_arguments.htm
 Description : How argc and argv is read in UNIX.
               These are command line options, when executing the compiled code, example:
             > gcc -o temp 021\ ArgcArgv.c
             > ./temp derp
 ============================================================================*/


#include <stdio.h>

int main( int argc, char *argv[] )  {

   if( argc == 2 ) {
      printf("The argument supplied is %s\n", argv[1]);
   }
   else if( argc > 2 ) {
      printf("Too many arguments supplied.\n");
   }
   else {
      printf("One argument expected.\n");
   }
}