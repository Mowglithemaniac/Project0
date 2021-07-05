/*============================================================================
 Name        : Test6.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : v1.00
 Date        : 27/12-2020
 Copyright   : Your copyright notice
 Description : double pointers
============================================================================*/

void main() { 
    // pointer for var 
    // double pointer for ptr1 
    int var = 789; 
    int *ptr1; 
    int **ptr2; 
  
    // storing address of var in ptr1
    // Storing address of ptr1 in ptr2 
    ptr1 = &var; 
    ptr2 = &ptr1; 
      
    // Displaying value of var using 
    // both single and double pointers 
    printf("Value of var = %d\n", var ); 
    printf("Value of var using single pointer = %d\n", *ptr1 ); 
    printf("Value of var using double pointer = %d\n", **ptr2); 

}

