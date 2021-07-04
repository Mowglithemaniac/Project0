/*============================================================================
 Name        : Test18.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 1.01
 Copyright   : Your copyright notice
 Date        : 01/07-2021
 Description : Basic example of implementation of fork
 ============================================================================*/
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {

	int i, h = 5, pid;
	printf("Example of parent & child with fork.\n");
	/** 
	 * The 'fork' command, will create an almost identical copy of the same program,
	 * the return value explains what happened.
	 * <> -1     - If execution of a copy (aka 'child') failed
	 * <>  0     - Means that it is the child that's executing the code
	 * <>  != 0, - Means that it is the parent, the return value, is the specific ID of the child
	 *             Think of it as the parent having to keep track of the childs social ID 'n stuff,
	 * 			   cause it's a freaking baby
	 */
	pid = fork();
	if (pid<0){
		printf("Error creating a child"); 
		return 0;
	}
	
	if (pid>0) { // parent

		wait(NULL); //wait for child to finish, so it can be reaped 
		printf("Parent multiplication: %d with 2\n", h);
		for (i=0;i<10;i++){
			printf("%.3d, ", h);

		}
		printf("\n");
	}

	if (pid == 0){ // child
		printf("Child addition: %d with 2\n", h);
		h = h + 1;
		for (i=0;i<10;i++){
			printf("%.3d, ", h);

		}
		printf("\n");
	}
    return 0;
}


