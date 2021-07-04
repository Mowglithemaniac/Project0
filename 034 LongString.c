/*============================================================================
 Name        : Test1.c
 Author      : Declined#8151 (Discord ID)
 Version     :
 Copyright   : Your copyright notice
 Description : What happens when you read a string, longer than the buffer?
============================================================================*/



#include <stdio.h>
#include <stdlib.h>

void main(){
    char tempArray[101];
//    fgets(tempArray, 20, stdin);


    FILE *fp;
    fp = fopen ("derpy.txt", "r");		// Open the file with 'read' option.	''
    if(fp==NULL){ exit(-1);}
    while(!feof(fp)){

        fgets(tempArray, 101, fp);
        printf("%s", tempArray);
    }
    fclose(fp);
    printf("\n");

}
