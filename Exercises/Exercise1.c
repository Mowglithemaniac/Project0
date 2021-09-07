/*============================================================================
 Name        : Exercise1.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 1.00
 Date        : 11/07-2021
 Copyright   : Your copyright notice
 Description : Program to illustrate problems when inserting strings into
               an expected integer.
 ============================================================================*/


#include <stdio.h>
//#include <>

/** Prototypes*/
//Menu options
void menu();                    // Info from the menu,
unsigned int enterChoice();

//List of functions to be placed in the menu
void Overview();                                                                // Prints the entire list of LC3 commands, and their bit setup
void studentHelp(int derping);                                                  // A simple help for students

int main(void) {
     menu();
}																				// End main


void menu(){

	unsigned int decision;														// For the loop, users choice		
	while ((decision = enterChoice()) != 0) {									// Enable user to specify which action should be taken next
		switch (decision) {
		case 1:																	// What happened in option 1
           //....
//			break;
		case 2:																	// Another function 2
           //....
//			break;
		case 3:																	// ...
           //....
//			break;
		case 4:																	// ...
           //....
//			break;
		case 5:
           //....
//			break;
		case 6:
           //....
           studentHelp(decision);
			break;
		default:																// Follow instructions, or else you'll be stuck.
			printf("Leaving so soon?\n");
			break;
		}
	}
}


//text format to find out what the user wanted in the switch
unsigned int enterChoice() {
	//display available options
	printf("\n\n--------------------------------"
	       "\nMain menu, enter your choice:\n"
	       "0 - Terminate the program.\n"
	       "1 - Option 1.\n"
	       "2 - Option 2.\n"
	       "3 - Option 3.\n"
	       "4 - Option 4.\n"
	       "5 - Option 5.\n"
	       "6 - Option 6.\n\n");

	unsigned int choice;
	scanf("%u", &choice);
	printf("\n--------------------------------\n\n");
	if (choice == 0) {
		printf("Storing the values within and terminating the program.\n\n");
	}
	return choice;																//Making sure a value is returned
}

void studentHelp(int derping){
    printf("You entered: %d\n", derping);
    printf("If this message is running in a loop, to terminate hit:\n"
    "\t\tCTRL + C\n"
    "\t\tCTRL + C\n"
    "\t\tCTRL + C\n"
    "\t\tCTRL + C\n");
    //Written multiple times, so it's easier to see during a fast loop.
}


