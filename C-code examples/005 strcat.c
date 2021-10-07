/*============================================================================
 Name        : Test5.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : v1.00
 Date        : 28/12-2020
 Copyright   : Your copyright notice
 Description : strcat implementation, and how dangerous it can be. 
============================================================================*/

#include <string.h>
#include <stdio.h>

void main(){
    char a[5] = "abc";
    char b[5] = "1234";
    char c[5] = "def";
    printf("========================\n"
           "This program is created to illustrate\n"
           "the use of 'strcat', which to append 1 string to another.\n");
    printf("------------------------\n\n");
    int derpA = strlen(a), derpB= strlen(b), derpC = strlen(c);
    printf("3 arrays, a, b & c, each with spaces\n"
           "Initial content:\n");
    printf("String a: %s\n", a);
    printf("String b: %s\n", b);
    printf("String c: %s\n", c);
    printf("------------------------\n\n");

    strcat(a, c);
    printf("Appending string c to string a.\n"
           "After conversion:\n");
    printf("String a: %s\n", a);
    printf("String b: %s\n", b);
    printf("String c: %s\n", c);

    derpA = strlen(a);
    derpB = strlen(b);
    derpC = strlen(c);
    printf("------------------------\n\n"
           "So, what happened to b?\n"
           "...\n\nDisplaying the entire content of the 3 arrays\n");
    printf("=========================================================================\n"
           "  Array\t| Length || Content at:\t|  [0]\t|  [1]\t|  [2]\t|  [3]\t|  [4]\t|\n");
    printf("     a\t|%5d\t ||\t\t|%4c\t|%4c\t|%4c\t|%4c\t|%4c\t|\n", derpA, a[0], a[1], a[2], a[3], a[4]);
    printf("     b\t|%5d\t ||\t\t|%4c\t|%4c\t|%4c\t|%4c\t|%4c\t|\n", derpB, b[0], b[1], b[2], b[3], b[4]);
    printf("     c\t|%5d\t ||\t\t|%4c\t|%4c\t|%4c\t|%4c\t|%4c\t|\n", derpC, c[0], c[1], c[2], c[3], c[4]);
    printf("=========================================================================\n\n");
    
    printf("As you can see, both 3 & 4 remains within the memory, but it \n"
           "isn't reachable because of the null character.\n"
           "Notice how the use of strcat can cause overflow\n"
           "The trick to realize, is that within the memory, the address of\n"
           "a[5] is the same as the address of b[0]\n");

    printf("Address of a[5]\t: %p\n", &a[5]);
    printf("Address of b\t: %p\n", &b);

}