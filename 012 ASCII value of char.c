/*============================================================================
 Name        : Test12.c 
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 1.01
 Copyright   : Your copyright notice
 Date        : 01/07-2021
 Description : Read the first 32 characters of a file called 'temp.txt' in the
             : same folder, and display their ASCII value.
             : The program display the influence of sign extension, and 
             : how signed vs unsigned int is stored in memory
 ============================================================================*/

#include <stdio.h>
#include <stdlib.h>

const int maxSize = 33;

void main(){
    char tempArray[maxSize];

    printf("This function will print the ASCII value of the first 32 characters of a file\n"
           "First we'll show using normal int:\n");
    FILE *fp;
    fp = fopen ("temp.txt", "rb");		// Open the file with 'read' option.	''
    if(fp==NULL){ exit(-1);}
//    while(!feof(fp)){
    fgets(tempArray, 33, fp);

    for(int i=0;i<32;i++){
        printf("%.2d : %4d\t", i+1, tempArray[i]); //%.2 means left shifted 2 spaces
        if((i+1)%5==0){printf("\n");}
    }

    printf("\nThis is displayed using unsigned int:\n");
    for(int i=0;i<32;i++){
        printf("%.2d : %4u\t", i+1, tempArray[i]); //Notie %u for unsigned
        if((i+1)%5==0){printf("\n");}
    }

    fclose(fp);
    printf("\n");

    //Using bitwise AND, to only look at the 8 last bits, and setting the remaining bits to 0 (int is 32 bits).
    printf("\nThis is what it should say:\n");
    for(int i=0;i<32;i++){
        printf("%.2d : %4d\t", i+1, 0xFF & tempArray[i]);
        if((i+1)%5==0){printf("\n");}
    }


//    }
    fclose(fp);
    printf("\n");
}

