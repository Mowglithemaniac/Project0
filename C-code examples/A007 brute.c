/*============================================================================
 Name        : brute
 Author      : Declined#8151 (Discord ID), s090116
 Version     : v1.00
 Copyright   : All rights reserved
 Date		 : 11/12-2022
 Last updated: 31/12-2022
 Description : A program that can brute force all permutations of a
               characterset, up to a defined number of characters.
 ============================================================================*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int MAXLENGTH = 24;
int CHARSETLENGTH = 26;
int desiredlength = 8;
char characterset[] = "abcdefghijklmnopqrstuvwxyz";
//Function prototypes
void printing(char printthis[]);
void increment(char current[]);
int findIndex(char character);

void printing(char printthis[]){
    printf("\r%s", printthis);
}

void increment(char current[]){
    int check = 1; //Boolean
    int position = strlen(current) -1;
    char tmp;
    //Find the index of the character in the characterset
    int CHARINDEX;
    while (check){
        tmp = current[position];
//        printf("%c\n", characterset[CHARSETLENGTH-1]);
        if(tmp == characterset[CHARSETLENGTH-1]){
            current[position] = characterset[0];
            if(position == 0){
                position = strlen(current)-1;
                while(position > -1){
                    current[(position+1)] = current[position];
                    position--;
                }
                return;
            }
            position--;
//            printf("\nReached end of characterset\n");
//            printf("Position : %i\n%s\n", position, current);
        }
        else {
            CHARINDEX = findIndex(tmp);
            current[position] = characterset[CHARINDEX+1];
//            check = 0;
            return;
        }
    }
//    printf("test string %s\n", current);
//    exit(1);
}

int findIndex(char character){
    for(int i = 0; i < CHARSETLENGTH; i++){
//        printf("\nchar : %c\t\tposition : %i\n", character, i);
        if(character == characterset[i]){ return i;}

    }
    fprintf(stderr, "[!] Character not found, terminating for security reasons.\n");
    exit(1);
    return -1;
}


void main1(){
    char *output = malloc(sizeof(char)*MAXLENGTH);
    //Initialize the array needed to store the output string
    memset(output, 0, MAXLENGTH*sizeof(char));
    if(CHARSETLENGTH != strlen(characterset)){
        fprintf(stderr,"[!] Updating CHARSETLENGTH\n");
        printf("MAXLENGTH : %i \t\t characterset : %i\n", CHARSETLENGTH, (int)strlen(characterset));
        CHARSETLENGTH = strlen(characterset);
    }
    output[0] = characterset[0];
    output[1] = characterset[0];
//    printf("%s\n", output);
//    exit(1);
    while(output[desiredlength] == 0){
        printing(output);
        increment(output);
    }
    printf("\nderp\n");
}

void test(){

}

int main(void){
    main1();
    test();
}