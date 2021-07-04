/*============================================================================
 Name        : Test010.c
 Author      : Declined#8151 (Discord ID)
 Edited by   : s090116
 Version     : v1.00
 Copyright   : 
 Description : Working with pointers
 ============================================================================*/

#include <stdio.h>

/**Prototypes*/
void func001(int valueRoman, int valueGreek);
void func002(int *valueRoman, int *valueGreek);
void func003(int firstValue, int secondValue);
void func004(int *firstValue, int *secondValue);

void main(){
    //Setting up the two variables I need
    int a = 10, b = 15;
    //Setting up a pointer to each variable
    int *alpha = &a, *beta = &b;
    printf("'a' is a direct value, 'alpha' is a pointer to 'a'\n");
        printf("'b' is a direct value, 'beta' is a pointer to 'b'\n");

    //Printing initial values
    printf("Original values\na = %d\nb = %d\n", a, b);
    printf("*alpha = %d\nalpha = %p\n", *alpha, alpha);
    printf("*beta = %d\nbeta = %p\n", *beta, beta);
    
    /**Passing as direct value */   
    printf("===================\n");
    printf("Passing a and alpha as direct values to function\n");
    func001(a, alpha);

    /**Passing as pointer value */
    printf("===================\n");
    printf("Passing a and alpha as pointers to function\n");
    func002(b, beta);
    
    /**How to handle if passed as direct value */
    printf("===================\n");
    printf("How they're supposed to be passed, when it's passed directly\n");
    func003(a, *alpha);

    /**How todirect value */
    printf("===================\n");
    printf("How they're supposed to be passed, when it's passed as a pointer\n");
    func004(&b, beta);

}

//Direct value
void func001(int valueRoman, int valueGreek){
    printf("Printing in hex:\n");
    printf("First value = %p\nPointer value = %p\n", valueRoman, valueGreek);
}

//
void func002(int *valueRoman, int *valueGreek){
    printf("Printing in hex:\n");
    printf("First value = %p\nPointer value = %p\n", valueRoman, valueGreek);
}

//
void func003(int firstValue, int secondValue){
    printf("Printing in decimal:\n");
    printf("First value = %d\nValue via pointer = %d\n", firstValue, secondValue);
}

//
void func004(int *firstValue, int *secondValue){
    printf("Printing in decimal:\n");
    printf("First value = %d\nValue via pointer = %d\n", *firstValue, *secondValue);
}
