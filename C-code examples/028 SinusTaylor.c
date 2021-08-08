/*============================================================================
 Name        : Test28.c
 Author      : Assignment from course 62507, assignment 6
 Edited by   : s090116
 Version     : v1.00
 Date        : 8/10-2019
 Copyright   : 
 Description : Calculate the integral of a sinus curve, using a Taylor series.
 Taylor 	 : https://en.wikipedia.org/wiki/Taylor_series
 Calculation : https://imgur.com/rrAgS0f.png
 ============================================================================*/

//#include <iostream>													//C++ I/O
#include <stdio.h>
#include <math.h>
#include <stdio.h>

/** PI can be taken directly from the math.h library
 * M_PI
 */
//const double PI = 3.14159265359;

int G = 0;																//Defined outside of main since we'll use it in the functions as well.
																		//Used to limit the amount of rows for Taylor, this is the G value listed in the notes

double Sinus(double x, double g);										//Function definition
double integer(double Y);

int main(void)															//Main
{
	double Xv = 2;														//Value for X (X-Value), we can use it in a test, which is why I've predefined it to 2.


	printf("Welcome to the sinus program!"
		"\nIn here, we'll calculate a sinus curve by using Taylors formula"
		"\nFor reference here is a picture: https://imgur.com/WN46XAl");


	printf("\nYou'll be given a choice of how many Taylor rows you would like to include."
		"\nthe more you add the more precise it become, be aware that "
		"it comes at the cost of efficiency.\n\nNow how many would you like to include?\n");			//recommended 8-10 minimum
	scanf("%i", &G);

	while (G < 1 || G > 201) {
		printf("Please try again, and this time, pick a number between 1-200:\n");
		scanf("%i", &G);
	}

	double derp = Sinus(Xv, G);																			//Test the sinus function with X being 2
	printf("To show an example of the accuracy, I've prechosen 2 as the x-value\n"
		"and we're going to use the accuracy you decided on:\n%f", derp);
	printf("\nThis is the value you're supposed to get when you take the sinus of 2:\n0.90927");


	/*	printf("\nNow that you've chosen a Taylorpolynomial, choose an X value to check:");				//Convert for x
		scanf_s("%f", &Xv);
		while(Xv > -10 || Xv <= 20){
			printf("\nPlease notice that this is a delicate program where we're comparing accuracy against efficiency.\n"
					"because of that, pick a value between -10 and 20.\n");
			scanf("	scanf_s("%f", &Xv);
		}

		while(x < 0){
			return -Sinus(-Xv, G)
			printf("")
		}
		while( x >= PI*2 ){
			return Sinus(Xv-2*PI, G);
		}
		while( x <= PI*2 ){
			return -Sinus(Xv-PI, G);
		}
		while( x >= PI/2 ){
			return Sinus(PI-Xv, G);
		}
	*/

	double sumI = integer(1);											//Task is using 1 in the integer function 
	printf("\nHere is the results of the equation we were asked to solve:\n%f\n", sumI);

	printf("\nType in something and hit enter to close the window.\n");	//To prevent it from closing prematurely.
	scanf(" ");

}																		//End main

//Sinus function
double Sinus(double X, double g) {										//X- is the x-value, G is the g-value
	double tempA = X;													//Starting value listed in the notes
	double tempB = 1;													//Starting value listed in the notes
	double TayRow = 0;
	double sum = tempA / tempB;											//Starting with the values already given to us.
//	double g = 10;														//User is defining this parameter

	for (int i = 1; i <= g; i++) {
		tempA *= -X * X;												//Formel taken from the notes
		tempB *= (2 * i) * (2 * i + 1);									//This is the formel given in the notes
		TayRow = tempA / tempB;											//results from the current row
		sum += TayRow;													//incremental result
	}
	return sum;
}


//Integer function
double integer(double Y) {
	double sum = 0;
	//int G = 310;														//Testing the limit before causing overflow, around 310, we can use this to override the entered G value from the user


	for (int i = 0; i < G; i++) {
		double dx = (M_PI / G);

		sum += Sinus(i * dx, G) * dx;

	}
	return sum;
}



/************************************************************************************
* Notes:																			*
* We've been given a formula to calculate the sinuscurve in a Taylor Series			*
* For (numerator)tælleren A(n) we've got: A(n) = -(x^2)*A(n-1), og A(0) = X			*
* For denominator(nævneren) B(n) we've got: B(n) = B(n-1)*(2n)(2n+1), og B(0) = 1	*
* Using that we need to calculate this: https://imgur.com/rrAgS0f					*
************************************************************************************/