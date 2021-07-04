/*============================================================================
 Name        : 030.c
 Author      : s090116
 Version     : 1.00
 Copyright   : My own, my precious
 Description : First part of encryption, changing characters within strings.
 ============================================================================*/

#include <stdio.h>

void change(char *ToBeChanged, int length);

int main(){
	
	char arbitraryArray[] = "Hello numnut!";
	printf("Entered sentence: %s\n", arbitraryArray);
	printf("char [0] : %u\n", arbitraryArray[0]);
	change(arbitraryArray, 14);
//	printf("Test length: %d\n", sizeof(arbitraryArray)/sizeof(arbitraryArray[0]));
	printf("Altered sentence: %s\n", arbitraryArray);
	int temp = arbitraryArray[0] + 256;
	printf("char [0] : %u\n", arbitraryArray[0]);
	change(arbitraryArray, 14);
	printf("Altered back    : %s\n", arbitraryArray);
	return 0;

}

void change(char *ToBeChanged, int length){
	int charValue = 0;
	int i, showMe;
	unsigned int derp;
/*	charValue = ToBeChanged[5];
	printf("Original Char \t: %c\n", ToBeChanged[0]);
	showMe = (int)ToBeChanged[0];
	printf("Original ASCII \t: %d\n", showMe);
	charValue = ~ToBeChanged[0];
	printf("Original Char \t: %c\n", ToBeChanged[0]);
	derp = ~ToBeChanged[0];
	derp += 256;
	printf("Changed ASCII \t: %d\n", derp);
	showMe = (char)derp;
	printf("Changed char \t: %c\n", showMe);
*/
	for(i = 0; i < length-1; i++){
		derp = ~ToBeChanged[i];
		derp += 256;
		ToBeChanged[i] = (char)derp;
	}
	
	
}





 