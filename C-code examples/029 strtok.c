/*============================================================================
 Name        : 029 strtok
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 1.00
 Date        : 08/09-2022
 Copyright   : Your copyright notice
 Description : A program to to create a strtok function, that returns a double
               pointer to the tokenized string.
               This code can be altered to be handled in 3 different methods
               for getting a double pointer with the content
               Method A: Supply address of double pointer as an argument
               Method B: Use return value of the function
               Method C: Store in Global pointer
 ============================================================================*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void init();                            //Added security to prevent memory leaks
char **tokenization(char ***workwith, char input[]);

char **methodC;
int dummy = 0;

void main(){

    char **methodA = NULL, **methodB = NULL;    // A = argument, B = Return value
    char test[] = "herpti derpti derp\n";// test string
    methodB = tokenization(&methodA, test);


    int i = 0;
//showcase,
    printf("Method A:\n");
    while(1){
        if(methodA[i] == NULL){ break; }
        printf("Method A output \t: %s\n", methodA[i]);
        i++;
    }
    i = 0;
    printf("\nMethod B:\n");
    while(1){
        if(methodA[i] == NULL){ break; }
        printf("Method B output \t: %s\n", methodB[i]);
        i++;
    }
    i = 0;
    printf("\nMethod C:\n");
    while(1){
        if(methodC[i] == NULL){ break; }
        printf("Method C output \t: %s\n", methodC[i]);
        i++;
    }
}

/**
 * @brief Initializing and preventing memory leaks,
 *        related to tokenization
 * Right now this is build around methodC with a
 * global variable, but can easily be altered to support
 * any of the methods.
 */
void init(){
    dummy++;
    if(dummy-1){                                // First time init is called.
        methodC = NULL; 
    } 
    if(methodC){                                // dummycheck != NULL
        dummy = 10;                             // Resetting dummy, to prevent integer overflow
        char *derp;
        int i = 0;
        while (1){
            if(methodC[i]){                     // methodC[i] != NULL
                free(methodC[i]);               // Free indivual strings
            } else {
                break;
            }
            i++;
        }
        free(methodC);                       // Free the double pointer
    }
}

/**
 * @brief 
 * 
 * @param nincompoop 
 * @param input 
 * @return char** 
 */
char **tokenization(char ***argumentA, char input[]){
    init();
    int count = 0;
    char **carbon_copy;
    char *stringtobesplit = malloc(sizeof(char)*strlen(input));
    char *usedforcount;

// Part 1, find out how many strings will be needed.
    strcpy(stringtobesplit, input);                   // Temporarily store the word
    usedforcount = strtok(stringtobesplit, " ");      // First word
    while( usedforcount != NULL ) {                   // Used to figure out how many words are in the string
      usedforcount = strtok(NULL, " ");               // The addtional words in the string is tokenized by whitespace
      count++;
    }

// Part 2, Initializing space for the double pointers.
    carbon_copy = malloc(sizeof(char *) * (count + 1));
    for(int i = 0; i <= count; i++){
        carbon_copy[i] = NULL;
    }

// Part 3, tokenization
    strcpy(stringtobesplit, input);               // copies the original userInput string into stringtobesplit
    
    //tokenizing the string
    for(int i = 0; i < count; i++){
        if(i == 0)
            usedforcount = strtok(stringtobesplit, " ");
        else
            usedforcount = strtok(NULL, " ");
        carbon_copy[i] = strdup(usedforcount);
    }


// Part 4, organizing return values and cleaning up memory
    free(stringtobesplit);
         // Choose method A, B, C
    *argumentA = carbon_copy;           // Method A, requires a double pointer as an argument to this function
    if(methodC == carbon_copy){}        // 
    else{methodC = carbon_copy; }       // Method B, storing the double pointer in a global variable
    
    return carbon_copy;                 // Method C, utilizing the return value of the function
}

