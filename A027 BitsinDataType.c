/*============================================================================
 Name        : A027.c
 Author      : Declined#8151 (Discord ID)
 Edited by   : 
 Version     : v1.00
 Date		 : 26/12-2020
 Copyright   : 
 Description : How many bits are used for a specific datatype.
 ============================================================================*/


//#include <iostream>													//C++ functionality
#include <stdio.h>
#include <string.h>

/*
int loop;
int n = 1;
short int b = 1;
long int c = 1;
char d = 1;

int FUNKT();

int main(void){
	FUNKT();															//Calling the function
	printf_s("\ntest. %i", loop);
}

int FUNKT(){																//function
	n = 1;
	for (loop = 1; n > 0; loop++){										//testing int
//		printf_s("\nTesting the value of integer: %i", n);				//useful to include.
		n = n * 2;
	}
	return loop;														//I want to know how many times the loop was used.
}

*/

int main(void){															//This is how I would've written the program, as I personally feel it's simpler to change stuff in.
	int loop;
	int n = 1;
	short int a = 1;
	long int b = 1;
	char c = 1;

	printf("Testing the value of an integer first, starting at 1.");
	
	for(loop = 1; n > 0; loop++){										//testing int
	 
//		printf_s("\nTesting the value of integer: %i", n);				//useful to include.
		n = n * 2;
	}	
	//printf_s("\nShowing the value of int after the loop: %i", n);				//Showing the number after overflow has been achieved
	printf("\nNumber of bits used for int: %i", loop);
		

	for (loop = 1; a > 0; loop++){											//testing short int
//		printf_s("\nTesting the value of short int: %i", n);
		a = a * 2;
	}
	printf("\nNumber of bits used for short int: %i", loop);

	for (loop = 1; b > 0; loop++){											//testing long int
//		printf_s("\nTesting the value of long int: %i", n);
		b = b * 2;
	}
	printf("\nNumber of bits used for long int: %i", loop);


	for (loop = 1; c > 0; loop++){											//testing character
//		printf_s("\nTesting the value of character: %i", n);
		c = c * 2;
	}
	printf("\nNumber of bits used for character: %i", loop);


	unsigned int d = 1;
	for (loop = 1; d > 0; loop++){											//testing unsigned int
//		printf_s("\nTesting the value of character: %i", n);
		d = d * 2;
	}
	printf("\nNumber of bits used for unsigned int: %i\n", loop);


	return 0;
}																			//It's nice being able to test it as needed.
