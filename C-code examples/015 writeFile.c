/*============================================================================
 Name        : 015 writeFile.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 1.01 (included a warning)
 Date        : 24/12-2020
 Copyright   : Your copyright notice
 Description : Example of writing to a file.
 ============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxArraySize = 128;

void main(){
    char tempArray[maxArraySize];
    printf("Enter a filename that you want to write something to.\n"
           "=======================WARNING=======================\n"
           "Take care to choose a file that does NOT already exist.\n"
           "=======================WARNING=======================\n");
    /**This program will overwrite the content of any file you choose
     * therfore it is recommended to come up with a bogus name such as
     * 'derp.txt' or simply 'derp'
     */
    fgets(tempArray, maxArraySize, stdin);
    
    /** with fgets, the last character is '\n'
     * the last char needs to be changed to NULL 
     */
    int i = strlen(tempArray);
    tempArray[i-1] = '\0';

    FILE *fp;
    fp = fopen(tempArray, "w");
    char *test = "test1\ntest2\ntest3";
    fprintf(fp, "%s", test);
    fclose(fp);
}