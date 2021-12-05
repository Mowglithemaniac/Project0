/*============================================================================
 Name        : errorhandling
 Author      : Declined#8151 (Discord ID), s090116
 Version     : v1.00
 Copyright   : Your copyright notice
 Date        : 01/12-2021
 Last updated: 01/12-2021
 Description : Example of stdout, stderr and return codes.
               Details found at the bottom
============================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>										// pid_t

#define MAX 3

void showerror(int id);       //stderr
void shownormal(int id);      //stdout

int main(void){
    int pid[MAX];
    int returncodes[MAX];
    /**
     * @brief Create MAX children
     * Have them output something via stdout and stderr
     * Then terminate with exit code (childNO + 1 + MAX)
     */
    for(int i = 0; i < MAX; i++){
        pid[i] = fork();
        if(pid[i] < 0){ //error
            fprintf(stderr, "Error creating child %d\n", i);
            return i+1;
        } else
        if(pid[i] == 0){ //child
            showerror(i);
            shownormal(i);
            exit(i+1+MAX); //aka 3, 4, ...
        } else{ // parent

        }
    }
    /**
     * @brief Reap children, and capture exit codes.
     */
    int derp = 0;
    for(int i = 0; i < MAX; i++){
        int status;
        int es;
        if ( waitpid(pid[i], &status, 0) == -1 ) {
            perror("waitpid failed\n");
            return (i+1+(2*MAX)); //rather than EXIT_FAILURE;
        }

        if ( WIFEXITED(status) ) {
            returncodes[i] = WEXITSTATUS(status);
            printf("Child: %d\treturned status: %d\n", i, returncodes[i]);
        }
        derp += returncodes[i];
    }
    return derp;
}


void showerror(int id){       //stderr
    //perror vs fprintf
    if(id < 0){
        fprintf(stderr, "Error message from child %d\n", id);
    } else{}
    /**
     * perror(const char * __s)
     * Because the string has to be const, there's no way to include variables
     */ 
    perror("Error message from child 0\n"); //No
//    perror("Error message from child %d\n", id); //This will not work
}


void shownormal(int id){      //stdout
    printf("Standard message from child %d\n", id);
}


/**
 Follow these steps to compile and execute the program in different ways
Here '$ ' emulates the command line, and : represents a comment
$ gcc -o test 022\ error.c
$ ./test
$ ./test 1> /dev/null
$ ./test 2> /dev/null
$ echo $?

: So, what happened?
: '1>' represents stdout
: '1>' is the explicit of '>', and '>' is the implicit of '1>'
: '2>' represents stderr
: /dev/null is a black hole, anything sent there is deleted
: '$?' command display the return code of the previous command/function
: The "./test" command execute the compiled program.
: The "./test > /dev/null" Execute the program, but omits stdout from being sent to the console
: The "./test 2> /dev/null"  Execute the program, but omits stderr from being sent to the console
*/

