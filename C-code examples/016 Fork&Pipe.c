/*============================================================================
 Name        : Fork&Pipe.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 1.01
 Copyright   : Your copyright notice
 Date        : 01/07-2021
 Last updated: 17&09/2021
 Description : Sending a message to a child through a pipe, using FILE
	     : Ergo, 'fprintf' and 'fscanf'
 ============================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>										// pid_t

int main () {
	int pipefd[2];
	pid_t pid;
	char recv [256];
	
	pipe (pipefd);
	
	pid=fork();												// Create a child

	if(pid<0)
	{
	 perror("fork");
		 exit(1);
	}else if (pid==0){								 		//in child proc 
		close (pipefd[0]);
		FILE *out = fdopen(pipefd[1], "w");
		fprintf(out, "msg_from_child_process \n");
		
	}else{													//in parent process
		close (pipefd[1]);
		FILE *in = fdopen(pipefd[0], "r");
		fscanf(in, "%s", recv);
		printf("parent:" "%s" "\n", recv);
		
	}
}

