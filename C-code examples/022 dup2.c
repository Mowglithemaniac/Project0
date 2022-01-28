/*============================================================================
 Name        : dup2
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 1.00
 Copyright   : Your copyright notice
 Date        : 01/07-2021
 Description : Example of redirecting the output from one process to another
             : via a pipe, by duplicating the stdout data stream through the
             : pipe. Essentially simulating a pipeline character on the
             : command line.
 ============================================================================*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void firstchild();
void secondchild();

int fd[2], pid[2];

int main(void){
    pipe(fd);
    firstchild();
    secondchild();
    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);
    return 1;
}

void firstchild(){
    pid[0] = fork();
    if(pid[0] < 0){
        fprintf(stderr, "Fork failed with first child.\n");
        exit(4);
    }
    if(pid[0] > 0){ // parent
        return;
    }
    dup2(fd[0], STDIN_FILENO); //copy input end (0) from console, to the read of the pipe
    close(fd[1]); //close write end
    char command[] = "tail";
    fprintf(stdout, "tail");
    execl("/bin/sh", "sh", "-c", command, (char *) 0);
    fprintf(stderr, "Command failed with second child.\n");
    exit(7);
}

void secondchild(){
    pid[1] = fork();
    if(pid[1] < 0){
        fprintf(stderr, "Fork failed with second child.\n");
        exit(6);
    }
    if(pid[1] > 0){ // parent
        return;
    }
    dup2(fd[1], STDOUT_FILENO); //copy output end (1) to console, to the write of the pipe
    close(fd[0]); //close read end
    char command[] = "ls -la";
    execl("/bin/sh", "sh", "-c", command, (char *) 0);
    fprintf(stderr, "Command failed with first child.\n");
    exit(5);
}