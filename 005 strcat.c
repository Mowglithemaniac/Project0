/*============================================================================
 Name        : Test5.c
 Author      : Declined#8151 (Discord ID)
 Version     : v1.00
 Copyright   : Your copyright notice
 Description : strcat implementation, and how dangerous it can be. 
============================================================================*/

#include <string.h>
#include <stdio.h>

void main(){
    char a[5] = "abc";
    char b[5] = "123";
    char c[] = "def";
    printf("========================\n"
           "This program is created to illustrate\n"
           "the use of 'strcat\n");
    printf("------------------------\n\n");

    printf("Initial content:\n");
    printf("String a: %s\n", a);
    printf("String b: %s\n", b);
    printf("String c: %s\n", c);
    printf("------------------------\n\n");

    strcat(a, c);
    printf("After conversion:\n");
    printf("String a: %s\n", a);
    printf("String b: %s\n", b);
    printf("String c: %s\n", c);

    printf("------------------------\n\n");

    int derp = strlen(a);
    printf("Length of a: %d\n", derp);
    printf("Address of a[5]\t: %p\n", &a[5]);
    printf("Address of b\t: %p\n", &b);
    printf("Char at b[0]: %c\n", b[0]);
    printf("Char at b[1]: %c\n", b[1]);
    printf("Char at b[2]: %c\n", b[2]);
    printf("Notice how the use of strcat can cause overflow\n");


}