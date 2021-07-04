/********'**********************************************************************
* Opg10.cpp
* Programmer : Daniel Silbermann, s090116
* Date : 12 - 11 - 2019
* Last modified : 16 - 11 - 2019
* Version : 1.03
* Description : Database i en klasse.
* Extended description: Multiple specs, details at the bottom.
* *****************************************************************************/


#include <stdio.h>

const int maxlength = 25;                       // maximum length of name string
const int maxSize = 200;						// maximum number of people  in the database

// Structure for database
struct derpiDerp {									// Definitionen på en post i databasen
	char firstName[maxlength];						// first name
	char lastName[maxlength];						// last name
	unsigned int telephone;							// telephone number
};

//A class including variables and prototypes
class Database {
public:
	Database();									//Constructor
	void readFile(const char* filename);
	void writeFile(const char* filename);
	void userIO();								// User Input Output (mostly input, only output are the text requests)
	void searchRemove();						// Searh function, void since the number we'll search for is only used within the function, and doesn't return anything
	void results();								// Same, prints within the function, hense the void.
	void testEntry();							// Giving the user a choice to add a test entry
	void binarySearch();						// Binary Search function
	void sortBubble();							// Sorting the database using Bubble Sort

public:
	derpiDerp derp[maxSize];					// Array used within the class.
private:
	int currentNum;								// Number of persons in database
	bool inOrder;								// Has the array been organized or not
	unsigned int removeEntry;
};

Database::Database() {
	currentNum = 0;
	inOrder = false;
	removeEntry = maxSize + 1;
}

//Prototype for the switch
unsigned int enterChoice();

int main(void) {
	const char* filename = "derp.txt";				// file name

	Database classyDerp;							// make an instance of class Database
	classyDerp.readFile(filename);					// read the file into classyDerp

	unsigned int decision;														// For the loop, users choice		
	while ((decision = enterChoice()) != 0) {									// Enable user to specify which action should be taken next
		switch (decision) {
		case 1:																	// Posting results
			classyDerp.userIO();
			break;
		case 2:																	// Type in another entry
			classyDerp.results();
			break;
		case 3:																	// Reserved for search funtion
			classyDerp.searchRemove();
			break;
		case 4:																	// Adding some test entries
			classyDerp.testEntry();
			break;
		case 5:
			classyDerp.binarySearch();							// Using a binary search method
			break;
		case 6:
			classyDerp.sortBubble();								// Sorting the database using bubblesort
			break;
		default:																// Follow instructions, or else you'll be stuck.
			printf("Leaving so soon?\n");
			break;
		}
		classyDerp.writeFile(filename);
	}
	return 0;
}																				// End main


//text format to find out what the user wanted in the switch
unsigned int enterChoice() {
	//display available options
	printf("\n\n--------------------------------");
	printf("\nMain menu, enter your choice:\n");
	printf("0 - Save entries, and terminate the program.\n");
	printf("1 - Add a person to the database.\n");
	printf("2 - Show the entries in the database.\n");
	printf("3 - Delete a specific entry.\n");
	printf("4 - Add a couple entries for testing purposes.\n");
	printf("5 - Search via binary search method.\n");
	printf("6 - Sort the database.\n\n");

	unsigned int choice;
	scanf_s("%u", &choice);
	printf("\n--------------------------------\n\n");
	if (choice == 0) {
		printf("Storing the values within and terminating the program.\n\n");
	}
	return choice;																//Making sure a value is returned
}

// read file into list
void Database::readFile(const char* filename) {
	// Put code in here for reading file...
	// All other member functions are made in the same way... 
	FILE* fp1;										// file pointer for input
	FILE* fp2;										// file pointer for output
	fopen_s(&fp1, filename, "r");					// open file for READING in order to count the number of entries

	if (fp1 == 0) {									// check for error, example not being able to open/locate/access/generate the file
		fprintf(stderr, "Cannot read file %s\n", filename); 						// write to standard error output
																					// Will try a workaround, by creating a file to write to, and then close it.
		printf("Trying to fix it.\n");
		fopen_s(&fp2, filename, "w");												// 
		if (fp2 == 0) {																// check for error
			// write error message to standard error output
			fprintf(stderr, "Unable to write to file, please check access to the file: %s\n", filename);
			// There should be some form of exit code here.
		}
		else {
			fclose(fp2);															// remember to close file
			printf("Fix complete, file should now be ready for use.");
		}
	}

	else {
		char space[maxlength];						// string for reading space

		while (!feof(fp1)) {						// repeat until end of file (feof - file end of file)

			if (currentNum >= maxSize) {
				break;						         // stop if array is full
			}
			/*			// fscanf_s works best if you read one string at a time
						// "%[^,]" will read anything but comma
						// "%[ ,]" will read spaces and commas and nothing else
						// "%[ ,\n\r]" will read spaces, commas, and newline
						// "%u" will read an unsigned integer
			*/
			//This is to prevent errors when reading an empty file.
			int e;
			e = fscanf_s(fp1, "%[ ]", space, maxlength);
			if (e) {															// If file is empty, break.
				printf("File %s loaded successfully.\n", filename);
				break;
			}
			/* Care, problem with this code it will always run, thus adding 1 entry even when there isn't any, and this missing entry can cause some issues.*/
			fscanf_s(fp1, "%[^,]", derp[currentNum].firstName, maxlength);		// read first name until comma
			fscanf_s(fp1, "%[ ,]", space, maxlength);							// read comma	
			fscanf_s(fp1, "%[^,]", derp[currentNum].lastName, maxlength);		// read last name until comma
			fscanf_s(fp1, "%[ ,]", space, maxlength);							// read comma
			fscanf_s(fp1, "%u", &derp[currentNum].telephone);					// read phone number
			fscanf_s(fp1, "%[ ,\n\r]", space, maxlength);						// read newline
			currentNum++;														// count number of persons, this is the important part of the code, finding the current amount of entries within the code
		}																		//counting the array
		fclose(fp1);														// ALWAYS remember to close file
	}
	// Notification to the user if there's more than just a few entries
	if (currentNum > 4) {
		printf("Note: There are currently %i entries stored within the database.", currentNum);
	}				//Belongs to the prototype function and not class function
}

//write
void Database::writeFile(const char* filename) {	// open file for writing
	FILE* fp2;
	fopen_s(&fp2, filename, "w");												// Near end of main, making sure to write the array into the file.
	if (fp2 == 0) {																// check for error
		// write error message to standard error output
		fprintf(stderr, "cannot write file %s\n", filename);
		// exit program with error code 1
	}
	else {
		for (int i = 0; i < currentNum; i++) {									// write persons to file    
			fprintf(fp2, "%s,%s,%u\n",
				derp[i].firstName, derp[i].lastName, derp[i].telephone);
		}
		// remember to close file
		fclose(fp2);
	}
}

void Database::results() {										// print all entries
	for (int i = 0; i < currentNum; i++) {
		printf("%-20s %-20s %u\n", derp[i].firstName, derp[i].lastName, derp[i].telephone);
	}
}

//user arrayinput
void  Database::userIO() {
	if (currentNum >= maxSize) {																		//preventing the user from storing too many entries.
		printf_s("\nYou've reached the max limit of the array, returning to menu.");					//Haven't had a chance to test this.
	}
	else {
		printf_s("\nPlease type in a first name(max 25 character limit) :\n");
		scanf_s("%s", derp[currentNum].firstName, maxlength);
		printf_s("Please type in a last name(max 25 characters limit):\n");
		scanf_s("%s", derp[currentNum].lastName, maxlength);
		printf_s("Please type in a first phone number(8 digits) :\n");
		scanf_s("%u", &derp[currentNum].telephone);														//& memory location reference
		while (derp[currentNum].telephone < 10000000 || derp[currentNum].telephone > 99999999) {		// Making sure entries stay withing an 8-digit format
			printf("You've entered an incorrect number please try again, remember 8 digits only:\n");
			scanf_s("%i", &derp[currentNum].telephone);
		}
		currentNum++;
		inOrder = false;
	}
}

//Linear search and delete function.
void Database::searchRemove() {											//Search function
	printf("\nType in a phone number to search for:\n");
	unsigned int compareNumber;
	int count = 0;																			//Counter to check if any numbers are found
	unsigned int k = maxSize + 1;															//Using k as an indicator for which values to store
	derpiDerp temp[2];
	scanf_s("%i", &compareNumber);
	for (int i = 0; i <= currentNum; i++) {
		if (compareNumber == derp[i].telephone) {
			printf("%-20s %-20s %u\n", derp[i].firstName, derp[i].lastName, derp[i].telephone);
			count++;
			if (k == maxSize + 1) {
				removeEntry = i;
			}
		}
	}
	if (count != 0) {															// Time to ask the user if he wants to delete an entry
		int m;
		printf("\nWould you like to delete an entry? If there are multiple numbers, only the first will be deleted.\n- If yes, type in 1.\n- If no, type in 2.\n");
		scanf_s("%i", &m);
		while (m < 1 || m > 2) {
			printf("\n You've entered an incorrect value, try again please, choose between 1 or 2.\n");
			scanf_s("%i", &m);
		}
		if (m == 1) {
			printf("\nThis is a delicate operation, we will now proceeed to delete the first listed entry.\n");
			temp[0] = derp[removeEntry];
			for (unsigned int i = removeEntry; i < currentNum; i++) {
				temp[1] = derp[i + 1];
				derp[i] = temp[1];
			}
			derp[currentNum] = temp[0];
			currentNum--;
		}
		if (m == 2) {
			printf("\nNo entry will be deleted.\n");
		}

	}
	if (count == 0) {															//Outside the for-loop since I need it to complete first
		printf("No individual within the database has that phone number.\n");
	}
}

//Adding entries based on the Marvel Universe
void Database::testEntry() {
	// add a record to the array
	int w = currentNum;
	derpiDerp control1 = { "Jane", "Doe",  66666666 };							//
	derpiDerp control2 = { "Peter", "Parker",  11111111 };						//	
	derpiDerp control3 = { "Tony", "Stark",  22222222 };						//
	derpiDerp control4 = { "Steve", "Rogers",  33333333 };						//
	derpiDerp control5 = { "Natasha", "Romanoff",  44444444 };					//
	derpiDerp control6 = { "Bruce", "Banner",  55555555 };						//
	derpiDerp control7 = { "Nick", "Fury",  77777777 };							//
	derpiDerp control8 = { "Clint", "Barton",  88888888 };						//
	derpiDerp control9 = { "Red", "Skull",  99999999 };							//

	if (w + 9 < maxSize) {																	// This is very nice to have.
		derp[w] = control1;
		w++;
		derp[w] = control2;
		w++;
		derp[w] = control3;
		w++;
		derp[w] = control4;
		w++;
		derp[w] = control5;
		w++;
		derp[w] = control6;
		w++;
		derp[w] = control7;
		w++;
		derp[w] = control8;
		w++;
		derp[w] = control9;
		w++;
		printf("Testing parameter selected, adding some entries based on the Marvel Universer.\n");
		currentNum = w;
		inOrder = false;
	}
	else {
		printf("There are too many entries in the database to add extras, consider clearning up the database.\n");
	}
}

//Binary search
void Database::binarySearch() {
	if (inOrder == false) {
		printf("Notice that the database is not currently organized.\nProceeding to automatically organize the Database.\n");
		sortBubble();
		printf("Fixed.\n");
		inOrder = true;
	}
	printf("\nType in a phone number to search for:\n");
	unsigned int compareNumber;													// Hvordan jeg vil gemme værdien fra søge funktionen
	scanf_s("%i", &compareNumber);												// Bruger input
	int low;
	int high;
	int mid;
	low = 0;
	high = currentNum;																	//Hvis jeg havde brugt maxSize i stedet, skull jeg have skrevet (high = maxSize -1)
	while (low < high) {
		mid = (low + high) / 2;
		if (compareNumber <= derp[mid].telephone) {							// Hvis mindre, ændres maxværdien til mid, for at ignorere den højeste halvdel
			high = mid;
		}
		else {																	// Hvis højere, ændres min. værdien til mid +1, da vi allerede har kontrolleret mid-værdien
			low = mid + 1;
		}
	}
	if (derp[low].telephone == compareNumber) {								// Hvis nummeret vi søgte efter er fundet.
		printf("%-20s %-20s %u\n", derp[low].firstName, derp[low].lastName, derp[low].telephone);
	}
	else {
		printf_s("Number was not found.\n");
	}

}

//Sorting the array
void Database::sortBubble() {
	printf_s("The database will now be sorted via the phone numbers.");
	bool swapped = true;
	int count = 0;															//counting number of runs
	derpiDerp temp[2];														// structuren er global, og vi bruger rent teknisk kun 1, så vi behøver ikke bruge maxSize
	while (swapped) {
		count++;
		swapped = false;
		for (int i = 0; i < currentNum - count; i++) {
			if (derp[i].telephone > derp[i + 1].telephone) {
				temp[1] = derp[i];
				derp[i] = derp[i + 1];
				derp[i + 1] = temp[1];
				swapped = true;												//Remembering that we swapped.
			}
		}
	}
	inOrder = true;
}


/******************************************************************************
* I opg 10, skal vi omskrive hele strukturen.
* Hele databasen skal pakkes ind i en c++ klasse
* Der må ikke være globale variable, men gerne
* globale konstanter.
* v1.02: Added some notes and changes
* v1.03: Removed the array input parameter since they're already included
* in the class.
* *****************************************************************************/