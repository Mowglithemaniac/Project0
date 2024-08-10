/*============================================================================
 Name        :.find_ascii.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 1.00
 Copyright   : 
 Dato        : 1/11-2023
 Last updated: 1/11-2023
 Description : Take an argument, and display the ascii value of each
               character.
 ============================================================================*/

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    if(argc-2){
        fprintf(stderr, "\x1b[31m[!]\x1b[0m Incorrect usage, program requires an argument, which can be shown as ascii!\n");
        return 1;
    }
    for( int i = 0, j = strlen(argv[1]); i < j; i++ ){
        printf("%c\t: %2d\t: %X\n", argv[1][i], argv[1][i], argv[1][i]);
    }
    return 0;
}