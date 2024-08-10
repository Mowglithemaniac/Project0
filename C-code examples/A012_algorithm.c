/*============================================================================
 Name        : Test17.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : v1.03
 Copyright   : 
 Dato        : 22/01-2020
 Last updated: 23/01-2020
 Description : An algorithm to count up and down from and including/excluding
             : 0, and MaxNumber.
 ============================================================================*/

#include <stdio.h>  //scanf_s


int main(){
    printf("Hello and welcome to a test algorithm\n"
    "Type in a number between 3-9\n");
    int maxNum = 0;
    scanf("%i", &maxNum);
    int currentPlayer = 0;
    int count = 0; //Used to differentiate counting up/down, and a limit to how many times it needs to run
    int count2 = 0; // Safety meassure to prevent it from running wild.

    //counting up from 0 to (but not including) maxNum 
    for (int i = 1; count <= 4; i++) {
        if (maxNum < 2 || maxNum > 10) {
            break;
        }
        if (currentPlayer == maxNum-1) {
            count++;
        }
        if ((count % 2) == 0)  {
            printf("\nCurrent player: %i", currentPlayer);
            currentPlayer = ((currentPlayer +1) % (maxNum)); //+1 player
            count2 += 1; 
        }
        if ((count % 2) == 1) {
            printf("\nCurrent player: %i", currentPlayer);
            currentPlayer = (currentPlayer + maxNum - 1) % maxNum; // - 1 player
            if (currentPlayer == 0){
                count2++;
            }
        }
        if (count2 == 40){
            break;
        }
    }
    printf("\nThe goal was to create and show an algorith that"
        "\nwould count up and down in a loop, from 0, up to (but not including)"
        "\nthe chosen number, once it reached that, it would reverse direction.");

    printf("\n\nTime to try again, counting from 1, up to the chosen number and then reverse back down"
        "\nessentially counting which player comes next, in either direction.");

    currentPlayer = 1;
    count = 0;	// resetting count
    count2 = 0; // resetting count2

    for (int i = 1; count <= 4; i++) {
        if (maxNum < 2 || maxNum > 10) {
            break;
        }
        if (currentPlayer == maxNum) {
            count++;
        }
        if ((count % 2) == 0) {
            printf("\nCurrent player: %i", currentPlayer);
            currentPlayer = (currentPlayer % maxNum) + 1; //+1 spiller
            count2 += 1;
        }
        if ((count % 2) == 1) {
            printf("\nCurrent player: %i", currentPlayer);
//          currentPlayer = (currentPlayer + (maxNum + 1)-1) % (maxNum + 1); // - 1 player, counting from max to 0
            currentPlayer = ((maxNum + currentPlayer -2 ) % maxNum) + 1; // - 1 player, counting from max to 1
            if (currentPlayer == 0) {
                count2++;
            }
        }
        if (count2 == 40) {
            break;
        }
    }
    return 0;
}
