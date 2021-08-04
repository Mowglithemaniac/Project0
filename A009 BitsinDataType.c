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




int Method1();
void Method2();

int main(void){
//	Method1();															//Calling the function
	Method2();
}

int Method1(){
	int loop;
	int n = 1;
	short int b = 1;
	long int c = 1;
	char d = 1;																//function
	n = 1;
	for (loop = 0; n != 0; loop++){										//testing int
//		printf_s("\nTesting the value of integer: %i", n);				//useful to include.
		n = n * 2;
	}
	printf("\ntest. %i\n", loop);													//I want to know how many times the loop was used.
	return loop;
}



void Method2(){															//This is how I would've written the program, as I personally feel it's simpler to change stuff in.
	int loop;
	int n = 1;
	short int a = 1;
	long int b = 1;
	char c = 1;

	printf("Testing the value of an integer first, starting at 1.\n");
	
	for(loop = 0; n != 0; loop++){										//testing int
	 
//		printf_s("\nTesting the value of integer: %i", n);				//useful to include.
		n = n * 2;
	}	
	//printf_s("\nShowing the value of int after the loop: %i", n);				//Showing the number after overflow has been achieved
	printf("int:\t\t %.2i\n", loop);
		

	for (loop = 0; a != 0; loop++){											//testing short int
//		printf_s("\nTesting the value of short int: %i", n);
		a = a * 2;
	}
	printf("short int:\t %.2i\n", loop);

	for (loop = 0; b != 0; loop++){											//testing long int
//		printf_s("\nTesting the value of long int: %i", n);
		b = b * 2;
	}
	printf("long int:\t %.2i\n", loop);


	for (loop = 0; c != 0; loop++){											//testing character
//		printf_s("\nTesting the value of character: %i", n);
		c = c * 2;
	}
	printf("char:\t\t %.2i\n", loop);


	unsigned int d = 1;
	for (loop = 0; d != 0; loop++){											//testing unsigned int
//		printf_s("\nTesting the value of character: %i", n);
		d = d * 2;
	}
	printf("unsigned int:\t %.2i\n", loop);

}																			//It's nice being able to test it as needed.
