/*
 ============================================================================
 Name        : Exercise3
 Author      : 
 Version     : 1.0
 Copyright   : 
 Description : Afleverings Opgave 1. Programering C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// precon:  modtaget fil skal være en normal .txt fil og slutte på \n.
// postcon: denne funktion laver "," om til "." 
void filkonverter1(char infil[], char outfil[]){
	FILE *fpt1,*fpt2; //angiver navne til filerne.
	fpt1=fopen(infil,"r");// læser fra fpt1 (Inputfil1).
	fpt2=fopen(outfil,"w");// skriver til fpt2 (Outputfil1).
	if(fpt1 == NULL || fpt2 == NULL){
      perror("Error in opening file");
      exit(1);
	}

	char c;
	while(fscanf(fpt1,"%c",&c)==1)//scanner filen 1 karakter afgangen.
	{
		if(c==',')
			fprintf(fpt2,"%c",'.'); //hvis "," lav om til ".".
		else
			fprintf(fpt2,"%c",c); // ellers forts�t at skrive direkte fra fpt1 til fpt2.
	}
	
}

// precon:  modtaget fil skal være en normal .txt fil og slutte på \n.
// postcon: mellemrum er blevet lavet om til linjeskift og "," er lavet om til mellemrum.
void filkonverter2(char infil[], char outfil[]){
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
			 	fprintf(fpt4,"%c",'\n'); // hvis mellemrum lav om til linjeskift.
				break;
			case ',':
			 	fprintf(fpt4,"%c",' '); // hvis mellemrum lav om til linjeskift.
				break;
			default:
			fprintf(fpt4,"%c",c); 
			break;
		}
	}
}

// precon:  filen skal være af .txt format og slutte på \n.
// postcon: filen skal have indsat punktum så der er 2 tal på hver linje som består af tal 1 og 2 samt
// af tal 3 og 4.
// programmet skal også kunne se om der er for mange tal i en linje eller ikke tal i (bogstaver og tegn)

void filkonverter3(char infil[], char outfil[]){
	FILE *fpt5,*fpt6;
	fpt5=fopen(infil,"r"); // angiver fil der skal l�ses fra.
	fpt6=fopen(outfil,"w"); // angiver fil der skal skrives til.
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

//precon:  infilen skal være af .txt format og slutte på \n
//postcon: outfilen skal have følgende krav.
// 		   1. Der er et mellemrum efter punktum.
//		   2. Der er et mellemrum mellem ordene, alts� overfl�dige mellemrum skal v�k.
//		   3. Der er et mellemrum efter komma.
//		   4. Der er ikke mellemrum f�r punktum.
//		   5. Der er ikke mellemrum f�r komma.


// følgende opgave virker ikke af ukendte årsager laves der "." i næstent hvert mellemrum. 
// jeg har prøvet at finde frem til fejlen uden held (ikke engang at lave et nyt program har virket)
// vil dog vove at p�st� at de funktioner jeg har skrevet burde virke som beskrevet.
void filkonverter4(char infil[], char outfil[]){
	FILE *fpt7,*fpt8;
	fpt7=fopen(infil,"r");//  angiver fil der skal l�ses fra.
	fpt8=fopen(outfil,"w");// angiver fil der skal skrives til.
	char c, nextc; // angiver en char c som er min "l�se" char og en char nextc  (next char)

	while(!feof(fpt7)){
		//Check first character(s) of a sentence
		c=getc(fpt7);
		if(c == ' ' || c == '.' || c == ','){
			continue;
		}
		if(c == '\n'){
			fprintf(fpt8,"\n");
			continue;
		}

		while(1){ //check 1 sentence at a time.
			nextc=getc(fpt7);
			if(feof(fpt7)){ return;			}
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


int main(void) { // her k�res filerne fra

	filkonverter1("Inputfil1.txt","Outputfil1.txt");
	filkonverter2("Inputfil2.txt","Outputfil2.txt");
	filkonverter3("Inputfil3.txt","Outputfil3.txt");
	filkonverter4("Inputfil4.txt","Outputfil4.txt");
}



