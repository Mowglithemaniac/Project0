/*============================================================================
 Name        : Test009.c
 Author      : Declined#8151 (Discord ID), s090116
 Edited by   : 
 Version     : v1.00
 Date        : 28/12-2020
 Copyright   : 
 Description : Sending value and address to a function
 ============================================================================*/


#include <stdio.h>

void T011(int a, int *b);

void main(){

    int derp = 5;;
    T011(derp, &derp);
    printf("Original value after function\nDerp: \t%d\n", derp);

}

void T011(int a, int *b){
    printf("Original values sent to function\n");
    printf("a :\t%p\n", a);
    printf("*b :\t%p\n", *b);
    a++;
    (*b)++;
    printf("Values after conversion\n");
    printf("a :\t%p\n", a);
    printf("*b :\t%p\n", *b);
}


