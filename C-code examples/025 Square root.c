/*============================================================================
 Name        : Test23.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : v1.00
 Date        : 15/11-2019
 Copyright   : 
 Description : Create a program that reads y, and calculate 𝑥 = √𝑦
 			   Via the Newton-Raphson method.
			   https://www.quora.com/Using-Newton%E2%80%93Raphson-method-establish-theformula-X_-n+1-frac-1-2-X_n-+-frac-N-X_n-to-calculate-sqrt-N-Hence-find-sqrt-5-correct-to-four-places-ofdecimals
 Formula is  :
	(1)  𝑥𝑛𝑦 = 0.5∗(𝑥𝑔𝑎𝑚𝑚𝑒𝑙 + 𝑦 / 𝑥𝑔𝑎𝑚𝑚𝑒𝑙) 
	(2)  𝑥𝑔𝑎𝑚𝑚𝑒𝑙 = 𝑥𝑛𝑦 
  ============================================================================*/

#include <stdio.h>
#include <math.h>

																//Declaring the types we're going to use in the function
float xga=2;													//This is a predefined value of my choice, used to start the mathematic formula 
int loop;
float xny;
float temp;
float temp2;
int max;

//Function
float ROD(float x, int max){

	for (loop = 0; loop <= max; loop++)							//<= means up to and including the max value we'll ask the user to define.
	{
		temp = x / xga;											//This entire piece can be converted to the Newson Rhapson method
		temp2 = temp + xga;
		xny = 0.50 * temp2;
		xga = xny;
	}
	return xny;													//returning the new value we've discovered
}																//End function


int main(){														//Main

	float b;
	float a;													//This is the value we'll need when we times the number we'll find with itself.
																//The comments from here on out, makes it pretty self explanatory.
	printf_s("This program can be used to find roots using the Newton-Raphson method.\n");
	printf_s("Which number would you like to check?\n");
	scanf_s("%f", &b);
	printf_s("How many times would you like it to run before telling you the number?\n");
	scanf_s("%i", &max);

	ROD(b, max);																		
	printf_s("This is the calculated number:\n%f\n", xny);
	printf_s("This is the number you started with:\n%f\n", b);
	a = xny*xny;
	printf_s("This is what happen when you time the number you found with itself:\n%f", a);

return 0;
}
