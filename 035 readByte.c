/*============================================================================
 Name        : 
 Author      : Declined#8151 (Discord ID)
 Version     : 
 Copyright   : Your copyright notice
 Description : Example of BYTES reading from a file.
 ============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stddef.h>

typedef unsigned char BYTE;             // 8-bit byte

void main(){
    BYTE tempArray[64] = "";    
//    char tempArray[20];
//    fgets(tempArray, 20, stdin);


    FILE *fp;
    fp = fopen ("derpy.txt", "rb");		// Open the file with 'read BYTE' option.	''
    if(fp==NULL){ exit(-1);}
    while(!feof(fp)){

        fgets(tempArray, 64, fp);
        printf("%s", tempArray);
    }
    fclose(fp);
    printf("\n");

}