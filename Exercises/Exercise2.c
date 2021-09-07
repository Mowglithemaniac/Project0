/*============================================================================
 Name        : Exercise2.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 1.00
 Date        : 07/09-2021
 Copyright   : Your copyright notice
 Description : This program will create up to 9 zombies, decided by the user.
               Then wait for input and close afterwards.
               To be used in conjuction with the 'top' command, to see the 
               'zombie' value change. 
 ============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {

	int DUMMYCHECK = 546546354, pid[10];
    unsigned int choice = DUMMYCHECK;
    char stupidityvalve[2];
	printf("==================================================\n"
           "This program is set up to illustrate the concept of zombies.\n"
           "Type in a value between 0-9, if you choose 0, the program will close.\n"
//           "If you screw around, the program will also close\n"
           "How many zombies would you like?\n");
   	scanf("%u", &choice);

// A bit of code to ensure that the user does not screw around.
    do{
        fgets(stupidityvalve, 2, stdin);
        if (stupidityvalve[0]!='\n') continue;
    }while(0);
    
    //THIS IS ABSOLUTELY NECESSARY UNLESS YOU WANT TO FORK BOMB YOUR COMPUTER
    if (choice < 1 || 9 < choice){
        printf("Terminating program.\n");
        return 1;
    }

    for(int i = 0; i < choice; i++){ 

        /** 
         * The 'fork' command, will create an almost identical copy of the same program,
         * the return value explains what happened.
         * <> -1     - If execution of a copy (aka 'child') failed
         * <>  0     - Means that it is the child that's executing the code
         * <>  != 0, - Means that it is the parent, the return value, is the specific ID of the child
         *             Think of it as the parent having to keep track of the childs social ID 'n stuff,
         * 			   cause it's a freaking baby
         */
        pid[i] = fork();
        if (pid[i]<0){
            printf("Error creating child number %d\n", i+1); 
        }
        
        if (pid[i]>0) { // parent
// wait(NULL); //wait for child to finish, so it can be reaped 
            printf("Created child number :%d\n", i+1); 
        }
        if (pid[i] == 0){ // child
            return 0;
        }
    }
    printf("Waiting for input before termination\n");
    fgets(stupidityvalve, 2, stdin);
    return 0;
}


