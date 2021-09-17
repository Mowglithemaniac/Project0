/*============================================================================
 Name        : Test7.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : v1.00
 Date        : 26/12-2020
 Description : Forwarding pointers through functions.
 ============================================================================*/

#include <stdio.h>
void displaySwap();
void displayNoGo();
void swap(int *n1, int *n2);
void NoGo(int n1, int *n2);

int main(){
    displayNoGo();
    displaySwap();

    return 0;
}

void displayNoGo(){
    int num1 = 5, num2 = 10;
    printf("===========================\n");
    printf("Submitting 2 arguments of 2 different values.\n"
           "One as the integer, the other as a pointer.\n"
           "Trying to increment the value with 1\n");

    printf("Initial values:\n"
           "num1 = %d\n"
           "num2 = %d\n"
           , num1, num2);
    //Value of num1 is passed, address of num2 is passed
    NoGo(num1, &num2);
    printf("After the incrementation:\n"
           "num1 = %d\n"
           "num2 = %d\n"
           , num1, num2);
}

void displaySwap(){
    int num1 = 5, num2 = 10;
    printf("===========================\n"
           "Here we try again, but this time\n"
           "we're only going to switch the value\n");

    printf("Initial values:\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);
    // address of num1 and num2 is passed
    swap( &num1, &num2);
    printf("Swapped values:\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);

}


void swap(int* n1, int* n2)
{
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void NoGo(int n1, int *n2){
    n1++;
    (*n2)++;                //if you use *n2++, it'll cause unintended behavior,
}
