/*============================================================================
 Name        : Test19.c
 Author      : Declined#8151 (Discord ID), s090116
 Edited by   : s090116
 Version     : v1.01
 Date        : 28/12-2020
 Copyright   :
 Description : Minor assignment for 62507 Hardware-nær programmering
             : Type in 4 numbers between 1-100 to determine the final grade.
 ============================================================================*/

#include <stdio.h>


int main(void){

    printf("Welcome to the character program.\nYou can use this to determine the character based on the results of their 4 test results.");

    printf("\nType in the results of his/her first test:\n");           //First test
    int res1;                                                           //short for result1
    scanf_s("%i", &res1);
    while (res1 < 0 || res1 > 100){                                     //Looping until the user enter a valid number
        printf_s("The number you've entered is invalid, you need to enter a number between 0 to 100.\n");
        scanf_s("%i", &res1);                                           //Overwriting the res1 value.
    }

    printf("Type in the results of his/her second test:\n");            //Second test
    int res2;
    scanf_s("%i", &res2);
    while (res2 < 0 || res2 > 100){                                     //Looping until the user enter a valid number
        printf_s("The number you've entered is invalid, you need to enter a number between 0 to 100.\n");
        scanf_s("%i", &res2);
    }

    printf("Type in the results of his/her third test:\n");             //Third test
    int res3;
    scanf_s("%i", &res3);
    while (res3 < 0 || res3 > 100){                                     //Looping until the user enter a valid number
        printf_s("The number you've entered is invalid, you need to enter a number between 0 to 100.\n");
        scanf_s("%i", &res3);
    }

    printf("Type in the results of his/her fourth test:\n");           //Fourth test
    int res4;
    scanf_s("%i", &res4);
    while (res4 < 0 || res4 > 100){
        printf_s("The number you've entered is invalid, you need to enter a number between 0 to 100.\n");
    scanf_s("%i", &res4);
    }

    printf_s("\nThe students scores are: %d", res1);                    //Showing the entered results
    printf_s(" %i", res2);
    printf_s(" %i", res3);
    printf_s(" %i", res4);

	int sum = (res1 + res2 + res3 + res4)/4;                            //Addition of results divided by 4.

    printf_s("\nThe average score is: %d\n", sum);                      //Visual representation of the average score.
//Long row of if and else if statements, and ultimately the last is true :(
    if (sum >= 90){	printf_s("That's a 12!"); }
    else if (sum > 79){ printf_s("That's a 10."); }
    else if (sum > 69){ printf_s("That's a 7."); }
    else if (sum > 59){	printf_s("That's a 04."); }
    else if (sum > 39){ printf_s("That's a 02."); }
    else{ printf_s("That's a 00."); }
}
