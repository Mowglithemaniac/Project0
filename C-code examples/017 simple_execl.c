/*============================================================================
 Name        : Test17.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 1.00
 Copyright   : Your copyright notice
 Date        : 01/07-2021
 Description : execl example, part of the exec family of functions
             : It will emulate a command send through a shell function
             : Notice how you can send it an entire sentence directly.
 ============================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>


    int main(){
        int derp_pid;
        derp_pid = fork();
        if(derp_pid==0){
            char command[20] = {"man creat | less"};
            execl("/bin/sh", "sh", "-c", command, (char *) 0);
        }   
        if(derp_pid == -1){
            printf("Error with exec.\n");
            return -20;
        }
        if(derp_pid > 0){
            int status;
            status = wait(NULL);
            printf("Parent here closing down: %d\n", status);
        }


    }



