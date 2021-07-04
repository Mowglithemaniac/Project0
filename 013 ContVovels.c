/*============================================================================
 Name        : Test13.c 
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 1.01
 Copyright   : Your copyright notice
 Date        : 01/07-2021
 Description : 
 ============================================================================*/


#include <stdio.h>																				//Standard input output library
#include <string.h>																				//Need this library to use the 'string length' operator

int countCharactersInSet(const char * text, const char * set);									//function definition

int main(void){                     															//main

	const int maxlength = 100;																	// define array size
	char mytext[maxlength];																		// array to contain text

	printf("Welcome to the vovel count program!\n"
		"This program can handle max 100 characters at a time\n"
		"Please type in a sentence:");
	fgets(mytext, maxlength, stdin);
//	gets_s(mytext, maxlength);			//c++

	int vowel = countCharactersInSet(mytext, "aeiouyAEIOUY");									//Function call, with the information we send to the function


	printf("\n\nThe text you've decided on, has this amount of vowels: %i\n", vowel);		
	
/*		//use this to print the text the user entered, although I would probably define the length of the input in the main if that was the case.
	printf("This is the text you've entered:\n");
	for (int i = 0; mytext[i] != 0; i++) {
		printf("%c", mytext[i]);
	} */
	return 0;
}																								//End main

int countCharactersInSet(const char * text, const char * set) {									//Function
	int counter = 0;																			//Memory used to counting vovels
	int length = strlen(text);																	//Defining the lenght of the 1st array
	int length2 = strlen(set);																	//Defining the length of the 2nd array
    if(length >=100){ return -1; }
	for (int i = 0; i < length; i++) {															//Looping the 1st array
		for (int k = 0; k < length2; k++) {														//Looping the 2nd array, to check each value against each value of of the first array
			if (text[i] == set[k])																//Comparing the values at each iteration. If true, increase counter by 1.
				counter++;																		
		}
	}
	return counter;
}