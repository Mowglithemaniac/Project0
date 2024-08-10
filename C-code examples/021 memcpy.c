/*============================================================================
 Name        : memcpy
 Author      : Declined#8151 (Discord ID), s090116
 Version     : v1.02
 Copyright   : Your copyright notice
 Date        : 29/10-2021
 Last updated: 06/11-2021
 Description : What is memcpy, and how does it work?
 ============================================================================*/


 #include <stdio.h>
 #include <string.h>

void function1(); //weird memory thing.
void function2(); // clean test. 

void main(void){
    function1();
    function2();
}


void function1(){
     char string1[] = "yolo";
     char string2[] = "0123456789ABCDEF";
     char string3[] = "abcdefghijklmnopqrstuvwxyz";
//    memset(string2, '\0', 20);
    printf("String1\t: %s\n", string1);
    printf("String2\t: %s\n", string2);
    printf("String3\t: %s\n", string3);
    printf("----------------------\n");
    printf("Copying string 1 into string 2\n");
    printf("Copying part of string 3 into string 3 to replace upper with lower case.\n");
    memcpy(string3, string1, strlen(string1));
    memcpy(&string2[10], &string3[0], 6);
    printf("----------------------\n");
    printf("String3\t: %s\n", string3);

}
void function2(){
    char string1[] = "To be, or not to be, that is the question\n";
    char string2[] = "And thus I clothe my naked villany in odd old end's stol'n\n";
    printf("String 1\t: %s", string1);
    printf("String 2\t: %s", string2);

}




/*
Format of void memcpy
void *memcpy(void *dest, const void * src, size_t n)







*/