/*============================================================================
 Name        : A027.c
 Author      : Declined#8151 (Discord ID)
 Edited by   : 
 Version     : v1.01
 Date		 : 26/12-2020
 Last updated: 09/11-2021
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
	for (loop = 0; n != 0; loop++){										//testing int
//		printf_s("\nTesting the value of integer: %i", n);				//useful to include.
		n = n * 2;
	}
	printf("\ntest. %i\n", loop);													//I want to know how many times the loop was used.
	return loop;
}



void Method2(){															//This is how I would've written the program, as I personally feel it's simpler to change stuff in.
	int result[7];
	int loop;
	int a = 1;
	unsigned int b = 1;
	short int c = 1;
	long int d = 1;
	long e = 1;
	long long f;
	char g = 1;
	void *h = 0x1;

	
	for(loop = 0; a != 0; loop++){										//testing int
//		printf_s("\nTesting the value of integer: %i", n);				//useful to include.
		a = a * 2;
	}	
	//printf_s("\nShowing the value of int after the loop: %i", n);				//Showing the number after overflow has been achieved
	result[0] = loop;

	for (loop = 0; b != 0; loop++){											//testing unsigned int
		b = b * 2;
	}
	result[1] = loop;

	for (loop = 0; c != 0; loop++){											//testing short int
		c = c * 2;
	}
	result[2] = loop;

	for (loop = 0; d != 0; loop++){											//testing long int
		d = d * 2;
	}
	result[3] = loop;

	for (loop = 0; e != 0; loop++){											//testing long
		e = e * 2;
	}
	result[4] = loop;

	for (loop = 0; f != 0; loop++){											//testing long long
		f = f * 2;
	}
	result[5] = loop;
	
	for (loop = 0; g != 0; loop++){											//testing character
		g = g * 2;
	}
	result[6] = loop;

	void *h = 0x1;
	printf("This program will calculate the bit length of different variable types.\n");
	printf("int:\t\t %.2i\n", result[0]);
	printf("unsigned int:\t %.2i\n", result[1]);
	printf("short int:\t %.2i\n", result[2]);
	printf("long int:\t %.2i\n", result[3]);
	printf("long:\t\t %.2i\n", result[4]);
	printf("long long:\t %.2i\n", result[5]);
	printf("char:\t\t %.2i\n", result[6]);
	printf("And finally, showing what an address looks like.\n");
	printf("Pointer:\t %p\n",h);

}
