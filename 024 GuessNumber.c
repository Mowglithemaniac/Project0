/*============================================================================
 Name        : Test23.c
 Author      : Declined#8151 (Discord ID)
 Edited by   : s090116
 Version     : v1.00
 Copyright   : 
 Description : Guess the number, and find out how long it took you
 ============================================================================*/

//#include <iostream>										//C++, basic IO
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//#include <cctype>										//I need the isdigit() function,

int main(void)
{
	int loop = 1;										//This is the loop counter, it's set to 1, since you always have to make 1 guess.
	int random1;										//The place where I store the value from the Random Number Generator.
	int guess;											//Users guess


	srand((int)time(0));								// Use the time in seconds to initialize the random number generator:
	random1 = rand() % 100;								// rand() makes a random number. '%' is modulo
	//printf("%i \n", random1);							//add or remove notation to see the number, good for testing purposes

	printf("A random value between 0-99 has been created, can you guess the number?\n");
	scanf_s("%i", &guess);

	while (guess != random1)							//As long as the user hasn't guessed correctly.
	{
		if(guess > random1)
		{
			printf("\nYour guess is higher than the chosen number.");
		}
		if(guess < random1)
		{
			printf("\nYour guess is lower than the chosen number.");
		}
		printf("\nTime to guess again:");				
		scanf_s("%d", &guess);
		loop++;											//Adding 1, to the number of tries used.

	}													//End of while loop.

	printf("This is how many tries it took you: %i\n", loop);

	return 0;                  
}

