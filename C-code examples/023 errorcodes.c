/*============================================================================
 Name        : ReadFile
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 1.00
 Date        : 21/02-2020
 Copyright   : Your copyright notice
 Description : Example of error codes
 ============================================================================*/

#include <errno.h>                      //errno
#include <stdio.h>                      //printf
#include <unistd.h>                     //close()
#include <stdlib.h>                     //EXIT_FAILURE
#include <fcntl.h>                      //O_RDONLY
#include <string.h>                     //From char * to char []

int main(){

    printf("Illustrating use of errno and strerror.\n"
           "errno is an global variable that's automatically updated to store errors\n"
           "strerror is the function that returns the paired explanation\n"
           "------------------------------------------------------------------------\n");
    int fd = open("asdlkfasdnfkjasdfaksdjf", O_RDONLY);
    if(fd == -1){
        printf("[!]File error: %s\n", strerror(errno));
    }

    if(close(fd)){
        printf("[!]File error: %s\n", strerror(errno));
    }
    printf("------------------------------------------------------------------------\n"
           "And a simple for-loop to check the first 21 error codes..\n");

    for(int i = 0; i < 21; i++){
        printf("Error code Number %2d\t: %s\n", i, strerror(i));
    }
    
    return EXIT_FAILURE;
}