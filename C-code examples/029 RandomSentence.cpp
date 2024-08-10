/*============================================================================
 Name        : Test29.cpp
 Author      : s090116
 Edited by   : s090116
 Version     : v1.01
 Date        : 28/12-2020
 Last updated: 6/11-2021
 Copyright   : 
 Description : Create a gibberish senten using format G - A - S - V - G - A - S
			   Notice that this is a C++ file, beacuse of windows.h
			   in order to include æøå and define a UTF8 character set.
 ============================================================================*/

#include <stdio.h>              // definer printf (og input)
/*C++ function to include UTF8 character sets*/
#include <windows.h>            // definer SetConsoleOutputCP  
#include <stdlib.h>             // define rand() function
#include <time.h>               // define time() function 

int RNG(int k);														//definer funktion

int main(void){

	SetConsoleOutputCP(CP_UTF8);									//Den skal inkluderes én gang, for at kunne bruge UTF-8 tegnsætning (æøå)
	int sizeG = 13;													//Størrelsen på de enkelte arrays
	int sizeA = 18;
	int sizeS = 23;
	int sizeV = 16;

	/*//Alternativ metode
	//Den finder antallet af elementer ved at dividere størrelsen af hele arrayet med størrelsen af et enkelt element.
	const int sizeG = sizeof(listG) / sizeof(listG[0]);
	const int sizeG = sizeof(listA) / sizeof(listA[0]);
	const int sizeG = sizeof(listS) / sizeof(listS[0]);
	const int sizeG = sizeof(listV) / sizeof(listV[0]);
	*/

	const char* listG[] = {											//Der skal være en pointer, ellers henviser den til hver character i arrayet
	"mit partis", "regeringens", "erhvervslivets", "eksportens",
	"betalingsbalancens", u8"arbejdsløshedens", "skattetrykkets",	//u8, forklaring i noterne i bunden
	"skatteydernes", u8"vælgernes", "forbrugets", u8"udlandsgældens",
	"globaliseringens", "industriens" };
	const char* listA[] = {											
		u8"miljøvenlige", u8"fælleseuropæiske", "fornuftige",
		"fremadrettede", u8"bæredygtige", "ansvarlige", u8"ambitiøse",
		"genmodificerede", "optimistiske", u8"skelsættende", "kloge",
		u8"igangsættende", u8"målrettede", "banebrydende", "proaktive",
		"ansvarlige", "omstillingsparate", u8"værdibaserede" };
	const char* listS[] = {											
		u8"finansordfører", "arbejdsmarkedsreform", "minister",
		"EU-direktiv", "stramninger", "danskhed", "win-win situation",
		"tiltag", "konkurrenceevne", "flygtningepolitik",
		"ghettoer", "udlicitering", u8"målsaetning", "visioner",
		u8"indsatsområder", u8"vækst", "ressourcer", u8"råderum",
		"levevilkår", u8"sammenhængskraft", u8"lavthængende frugter",
		u8"løsninger", "synlighed i det offentlige rum" };
	const char* listV[] = {											
		u8"støtter", u8"nødvendiggoer", "er et omdrejningspunkt for",
		u8"tager afsæt i", u8"er en forudsætning for", "bygger på",
		u8"vil gøre en forskel for", u8"vil tage aktion på", "fremmer",
		u8"nedsætter", u8"sætter fokus på", u8"vil stå på mål for",
		"beklager", u8"skal italesætte", "effektiviserer",
		"er efter vort partis mening den bedste garanti for", };

	//Rækkefølgen skal være G - A - S - V - G - A - S 

	srand((int)time(0));									// Use the time in seconds to initialize the random number generator:
	printf("%s ", listG[RNG(sizeG)]);						//listG er arrayet, RNG() er Random Number Generator funktionen, og sizeG er indenfor intervallet
	printf("%s ", listA[RNG(sizeA)]);
	printf("%s ", listS[RNG(sizeS)]);
	printf("%s ", listV[RNG(sizeV)]);
	printf("%s ", listG[RNG(sizeG)]);
	printf("%s ", listA[RNG(sizeA)]);
	printf("%s.", listS[RNG(sizeS)]);						//punktum til slut

//	printf(u8"\næblegrødstest");							//rar at have for at kunne se eksempel
//	printf("\næblegrødstest")								
	return 0;
}															//end main


int RNG(int f) {											//Function
	int ran;												// random number 
	ran = rand() % f;										// rand() makes a random number. '%' is modulo
	return ran;
}


/******************************************************************************
* Programmet skal indeholde lister over ord eller fraser fra fire kategorier
* G, A, S og V som vist nedenfor. Programmet skal vælge tilfældige ord fra hver
* kategori i rækkefølgen  
* G - A - S - V - G - A - S 
*
* For danske symboler skal jeg indsætte
* #include <stdio.h>      // definer printf
* #include <windows.h>    // definer SetConsoleOutputCP 
* SetConsoleOutputCP(CP_UTF8);	//Skal sættes en enkelt gang ind i main
* Jeg skal skrive u8 foran tekststrengen, det er vigtigt at gøre det i arrayet
* og ikke bare i printf, ellers bliver symbolet ikke gemt i arrayet
* *****************************************************************************/