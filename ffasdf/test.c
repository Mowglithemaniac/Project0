 /*============================================================================
 Name        : Solution3
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 1.01
 Copyright   : Your copyright notice
 Date        : 17/09-2021
 Last updated: 19/09-2021
 Description : Exercise3 solution
 ============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void filconverter1(char infil[], char outfil[]);
void filconverter2(char infil[], char outfil[]);
void filconverter3(char infil[], char outfil[]);
void filconverter4(char infil[], char outfil[]);

int main(void) { 

	filconverter1("Inputfil1.txt","Outputfil1.txt");
	filconverter2("Inputfil2.txt","Outputfil2.txt");
	filconverter3("Inputfil3.txt","Outputfil3.txt");
	filconverter4("Inputfil4.txt","Outputfil4.txt");
}

// precon:  Input file must be a regular .txt fil and end with \n
// postcon: This function converts ',' to '.' 
void filconverter1(char infil[], char outfil[]){
	FILE *fpt1,*fpt2; 								    // Creating file pointers to be used for accessing the files.
	fpt1=fopen(infil,"r");								// Open file with read option
	fpt2=fopen(outfil,"w");								// Open file with write option
	if(fpt1 == NULL || fpt2 == NULL){
      perror("Error in opening file");
      exit(1);
	}

	char c;
	while(fscanf(fpt1,"%c",&c)==1){                    // Scanning 1 character at a time
		if(c==',')
			fprintf(fpt2,"%c",'.');
		else
			fprintf(fpt2,"%c",c);
	}
	
}

// precon:  Input file must be a regular .txt fil and end with \n
// postcon: Spaces must be turned into linebreaks, and commas to spaces
void filconverter2(char infil[], char outfil[]){
	FILE *fpt3,*fpt4; // angiver filerne .
	fpt3=fopen(infil,"r"); // l�ser fra input.
	fpt4=fopen(outfil,"w");// skriver til output.
	if(fpt3 == NULL || fpt4 == NULL){
      perror("Error in opening file");
      exit(-1);
	}
	char c; 
	while(fscanf(fpt3,"%c",&c)==1){
		switch(c){
			case ' ':
			 	fprintf(fpt4,"%c",'\n');
				break;
			case ',':
			 	fprintf(fpt4,"%c",' ');
				break;
			default:
			fprintf(fpt4,"%c",c); 
			break;
		}
	}
}

// precon:  Input file must be a regular .txt fil and end with \n
// postcon: Each line in the file should contain 4 numbers, and be able to tell if there isn't
//          When there is 4 numbers, insert a dot between the 2nd and 3rd number.

void filconverter3(char infil[], char outfil[]){
	FILE *fpt5,*fpt6;
	fpt5=fopen(infil,"r"); 
	fpt6=fopen(outfil,"w");
	if(fpt5 == NULL || fpt6 == NULL){
      perror("Error in opening file");
      exit(-1);
	}
	char c[50], a,b; //b before, a after
	int count, character; 

	while(!feof(fpt5)){
		fgets(c, 50, fpt5);
		count = 0;
		character = 0;
		b = 'Q';
		for(int i = 0; i < strlen(c); i++){
	        a = c[i];
		  	if(!(a < '0' || a > '9') &&  !(b >= '0' && b <= '9')){ //compare previous to current character
				count++;
		  	}
			if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')){
				count = -40;
				break;
			} 
			if(count == 3 && character == 0){
				character = i-1;
			}
			b = a;
		}

		if(count == 4){
			c[character] = '.';
			fprintf(fpt6,"%s",c);
			continue;
		} else if(count == 0) { //No numbers or characters, assume empty sentence
			fprintf(fpt6,"Assume empty: %s",c);
		} else if (count == -40){ //Not 4 numbers
			fprintf(fpt6,"Char: %s",c);
		} else {
			fprintf(fpt6,"Error count: %d: %s", count, c);
			
		}
	}
}

//precon  Input file must be a regular .txt fil and end with \n
//postcon: Outputfile has the following requirements
// 		   1. There must be a space after a dot (.) character.
//		   2. There must only ever be 1 space between words, not multiple.
//		   3. There must be a space after a comma (,) character.
//		   4. There must not be a space prior to a dot character.
//		   5. There must not be a space prior to a comma character.
void filconverter4(char infil[], char outfil[]){
	FILE *fpt7,*fpt8;
	fpt7=fopen(infil,"r");
	fpt8=fopen(outfil,"w");
	char c, nextc; 								//Only need to have acceess to 2 characters at a time, 0

	while(!feof(fpt7)){
		c=getc(fpt7);							// Read the first character(s) of a sentence
		if(c == ' ' || c == '.' || c == ','){	// In case a sentence start with something weird, ignore it.
			continue;
		}
		if(c == '\n'){							// Newline.
			fprintf(fpt8,"\n");
			continue;
		}

		while(1){ //check 1 sentence at a time.
			nextc=getc(fpt7);
			if(feof(fpt7)){ return;}
			if(nextc == '\n'){
				fprintf(fpt8,"%c%c", c, nextc);
				break;
			}
			if(c == ',' || c == '.'){
				fprintf(fpt8,"%c", c);
				c = ' ';
			}
			if(c == ' ' && nextc == ' ')
				continue;
			else if(c == ' ' && nextc == '.'){
				fprintf(fpt8,".");
				c = ' ';
				continue;
			} else if(c == ' ' && nextc == ','){
				fprintf(fpt8,", ");
				c = ' ';
				continue;
			} else {
				fprintf(fpt8, "%c", c);
				c = nextc;
			}
		}

	}
}






