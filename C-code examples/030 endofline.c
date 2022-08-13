/*============================================================================
 Name        : Test27.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : v1.01
 Date        : 6/11-2019
 Last updated: 6/11-2021
 Copyright   : 
 Description : A simple program to illustrate end of line characters
               such as \n (newline), \r (carriage return)
 ============================================================================*/


#include <stdio.h>


void main(){
    printf("=================================\n");
    printf("Newline x3\n"
           "test\ntest\ntest\n");
    printf("=================================\n");
    printf("Carriage return x3\n"
           "test\rtest\rtest\r");
    printf("=================================\n");
    printf("Newline + Carriage return x3\n\r"
           "test\n\rtest\n\rtest\n\r");
    printf("=================================\n");
    printf("Carriage return + Newlinex3\n"
           "test\r\ntest\r\ntest\r\n");
    printf("=================================\n");


}