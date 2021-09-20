/*============================================================================
 Name        : DoublePointer
 Author      : Declined#8151 (Discord ID), s090116
 Version     : v1.00
 Date        : 10/08-2020 
 Last updated: 20/09-2021
 Copyright   :
 Description : Example of a double pointer implementation
             : Showcasing two methods with identical results
             - One made via functions
             - One created without the use of functions
 ============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init1(char ***derp);
void init2(char **derp);
void insert(char **derp);
void print(char **derp);
void reset1(char **something);

int main(){

    char** doubleP;                         //Initialized a double pointer variable
    printf("=================================================\n"
           " This is an example of initialization and usage of\n"
           " a double pointer function, via functions:\n");
    //Showing how it can be done via functions
    init1(&doubleP);                        // Initialize pointers to strings
    init2(doubleP);                         // Initialize room for strings
    insert(doubleP);                        // Insert strings
    print(doubleP);                         // Print the content
    reset1(doubleP);                        // Free all the allocated memory
 /* At this point, doubleP still points to the memory,
 *  so even though we've freed the content it points to,
 *  we still need to ensure that doubleP points to NULL afterwards
 */
    doubleP = NULL;                        


    printf("=================================================\n\n"
           " This part is done without functions:\n");

    // Showing the exact same, but this time directly
    doubleP = malloc(sizeof(char *)*3);
    doubleP[0] = malloc(sizeof(char) * 10);
    doubleP[1] = malloc(sizeof(char) * 10);
    doubleP[2] = malloc(sizeof(char) * 10);
    strcpy(doubleP[0], "Hi");
    strcpy(doubleP[1], "Hello");
    strcpy(doubleP[2], "Hola");
    //print
    for (int i=0;i<3;i++){
        printf(" String[i] = %s\n",doubleP[i]);
    }
    free(doubleP[0]);
    free(doubleP[1]);
    free(doubleP[2]);
    free(doubleP);

    printf("=================================================\n\n");
    return 0;
}

void init1(char ***derp){
    *derp = malloc(sizeof(char *)*3);
}
void init2(char **derp){
    derp[0] = malloc(sizeof(char) * 10);
    derp[1] = malloc(sizeof(char) * 10);
    derp[2] = malloc(sizeof(char) * 10);
}
void insert(char **derp){
    strcpy(derp[0], "Hi");
    strcpy(derp[1], "Hello");
    strcpy(derp[2], "Hola");
}

void print(char **doubleP){
    for (int i=0;i<3;i++){
        printf(" String[i] = %s\n",doubleP[i]);
    }
}

void reset1(char **something){
    free(something[0]);
    free(something[1]);
    free(something[2]);
    free(something);
}

void reset2(char *something, int length){
    int i;
    for(i =0;i < length; i++)
        something[i] = '\0';
}
