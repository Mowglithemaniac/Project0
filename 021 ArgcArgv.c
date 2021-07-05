/*============================================================================
 Name        : Test21.c
 Author      : Dunno, but it's concisely set up.
 Edited by   : Declined#8151 (Discord ID), s090116
 Version     : 1.00
 Copyright   : Your copyright notice
 Date        : 01/07-2021
 Source      : https://www.tutorialspoint.com/cprogramming/c_command_line_arguments.htm
 Description : How argc and argv is read in UNIX.
               These are command line options, when executing the compiled code, example:
             > gcc -o temp 021\ ArgcArgv.c
             > ./temp derp
             : Here you can see that the argument is './temp' and 'derp'
 ============================================================================*/


#include <stdio.h>

void test01(int howMany, char **words);                  // Passing the details to a function 
void test02(int howMany, char **words);                  // How to print all arguments.

int main( int argc, char *argv[] )  {
/** How to work with argc/argv directly within main*/
   if( argc == 2 ) {
      printf("The argument supplied is %s\n", argv[1]);
   }
   else if( argc > 2 ) {
      printf("Too many arguments supplied.\n");
   }
   else {
      printf("One argument expected.\n");
   }


   test01(argc, argv);
   test02(argc, argv);

}


void test01(int howMany, char **words){
   printf("\nLet's try again, while inside a function.\n");
   if( howMany == 2 ) {
      printf("The argument supplied is %s\n", words[1]);
   }
   else if( howMany > 2 ) {
      printf("Too many arguments supplied.\n");
   }
   else {
      printf("One argument expected.\n");
   }

}

/** 
 * argv is a doubly pointer, each index points to a
 * complete string.
 * Remember that strings are considered char pointers
 * where the variable name of the string points to the
 * address of the first character
 */
void test02(int howMany, char **words){
   printf("\nAnother test.\n");
   for (int i = 0; i < howMany; i++){
      printf("Argument %.2d:\t%s\n", i, words[i]);
   }
}
