/*============================================================================
 Name        : Test23.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 1.01
 Copyright   : Your copyright notice
 Date        : 01/07-2021
 Description : Sending a message to a child through a pipe, using FILE
 ============================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main () {
	int pipefd[2];
	int pid;
	char recv [256];
	
	pipe (pipefd);
	
	pid=fork();

	if(pid<0)
	{
	 perror("fork");
		 exit(1);
	}else if (pid==0)
	{
	 		//in child proc 
		close (pipefd[0]);
		FILE *out = fdopen(pipefd[1], "w");
		fprintf(out, "msg_from_child_process \n");
		
	}else
	{		//in parent process
		close (pipefd[1]);
		FILE *in = fdopen(pipefd[0], "r");
		fscanf(in, "%s", recv);
		printf("parent:" "%s" "\n", recv);
		
	}
}

