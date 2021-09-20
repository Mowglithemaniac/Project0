 /*============================================================================
 Name        : Exercise3
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 1.01
 Copyright   : Your copyright notice
 Date        : 17/09-2021
 Last updated: 20/09-2021
 Description : 4 small tasks of increasing difficulty, about evaluating
               input from .txt files
               Desctiption at the bottom.
 ============================================================================*/

#include <stdio.h>
#include <stdlib.h>


void fileconverter1(char infil[], char outfil[]);
void fileconverter2(char infil[], char outfil[]);
void fileconverter3(char infil[], char outfil[]);
void fileconverter4(char infil[], char outfil[]);

int main(void) { 
	fileconverter1("Inputfile1.txt","Outputfile1.txt");
	fileconverter2("Inputfile2.txt","Outputfile2.txt");
	fileconverter3("Inputfile3.txt","Outputfile3.txt");
	fileconverter4("Inputfile4.txt","Outputfile4.txt");
}

void fileconverter2(char infil[], char outfil[]){
    //FILL ME IN
}
void fileconverter2(char infil[], char outfil[]){
    //FILL ME IN
}
void fileconverter2(char infil[], char outfil[]){
    //FILL ME IN
}
void fileconverter2(char infil[], char outfil[]){
    //FILL ME IN
}

/*
You've been given the skelet of a code, and 4 input files.
You're not supposed to alter the names of the files, or delete
any code you've been given, but only to add to the code.

Task 1
// precon:  Input file must be a regular .txt fil and end with \n
// postcon: This function converts ',' to '.' 

Task 2
// precon:  Input file must be a regular .txt fil and end with \n
// postcon: Spaces must be turned into linebreaks, and commas to spaces

Task 3
// precon:  Input file must be a regular .txt fil and end with \n
// postcon: Each line in the file should contain 4 numbers, and be able to tell if there isn't
//          When there is 4 numbers, insert a dot between the 2nd and 3rd number.

Task 4
//precon  Input file must be a regular .txt fil and end with \n
//postcon: Outputfile has the following requirements
// 		   1. There must be a space after a dot (.) character.
//		   2. There must only ever be 1 space between words, not multiple.
//		   3. There must be a space after a comma (,) character.
//		   4. There must not be a space prior to a dot character.
//		   5. There must not be a space prior to a comma character.

*/