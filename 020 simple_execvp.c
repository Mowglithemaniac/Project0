/*============================================================================
 Name        : Test20.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 1.01
 Copyright   : Your copyright notice
 Date        : 01/07-2021
 Description : execvp example, part of the exec family of functions
             : It will emulate a command send through a shell function
             : For details check out the man page for execvp
 ============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

int main(void) {

        int pid;
	pid = fork();
        if (pid> 0 ) {
            pid = wait(NULL);
	    printf("Hello, parent has waited for child processes and completed now.\n");
        } else {

        //Arguments, are entered 1 word at a time, 1st word is the command, then comes the arguments, and last is null
	char *myargs[3];
	myargs[0]= strdup("ls");
	myargs[1]= strdup("-l");
	myargs[2]= NULL;

        execvp (myargs[0],myargs);
	printf("code never reaches here \n");
        exit(0);
        }
}

