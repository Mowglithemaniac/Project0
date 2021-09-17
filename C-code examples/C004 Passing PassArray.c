/*============================================================================
 Name        : Test011.c
 Author      : Dunno
 Author      : Declined#8151 (Discord ID), s090116
 Version     : v1.02
 Date        : 27/12-2020
 Last updated: 17/09-2021
 Copyright   : source: https://www.programiz.com/c-programming/c-pointer-functions
 Description : Passing an array through a function
 ============================================================================*/
 
#include <stdio.h>

void T011(int arr[], int size);

int main(){
    int exampleArray[] = {1, 2, 3, 4, 5};
    /**sizeof does not know which datatype is used,
     * and therefore the length of each individual block of data
     * Example:
     * int  = 32 bits of data.
     * char = 8 bits of data.
     * This is a fancy method to figure out the exact bit length
     * and then divide it by the datatype, to find the relative length
     */
    printf("The name of an array, is treated as a pointer, which is what this program is about\n"
           "Size of array:\t%ld\n", (sizeof(exampleArray)/sizeof(exampleArray[0])));    
    printf("Original content:\t");
    for(int i = 0; i < 5; i++){
        printf("%d ", exampleArray[i]);
//        exampleArray[i];
    }
    printf("\n");


    /**
     * Sending the array through a function 
     */
    T011(exampleArray, 5);

    printf("\n\nWhat is the result after returning to main.\nAfter :\t\t");
    for(int i = 0; i < 5; i++){
        printf("%d ", exampleArray[i]);
    }

    
    printf("\n");

    /**
     * When you pass an array as 'array[]' it is treated as a pointer
     * and thus allow the funtion access to the content of that array.
     * However make sure NOT to go beyond the bounds of the array.
     * as there is NO protection against it in C, and you can
     * wreck your computer.
     */
    return 0;
}

void T011(int arr[], int size){
    printf("\nSending the content to a function, to be multiplied by itself.\n");
    printf("Function :\t");
    for(int i = 0; i < size; i++){
        arr[i]*=arr[i];
        printf("%d ", arr[i]);
    }
}
