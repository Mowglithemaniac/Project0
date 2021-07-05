/*============================================================================
 Name        : ReadFile
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 
 Copyright   : Your copyright notice
 Description : Example of reading from a file.
 ============================================================================*/

#include <stdio.h>
#include <stdlib.h>

void main(){
    char tempArray[20];

    FILE *fp;
    fp = fopen ("derpy.txt", "r");		// Open the file with 'read' option.	''
    if(fp==NULL){ exit(-1);}
    while(!feof(fp)){

        fgets(tempArray, 20, fp);
        printf("%s", tempArray);
    }
    fclose(fp);
    printf("\n");

}