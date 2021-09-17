/*============================================================================
 Name        : pipeFileDescriptor
 Author      : Declined#8151 (Discord ID), s090116
 Version     : v1.01
 Copyright   : source: https://www.youtube.com/watch?v=Mqb2dVRe0uo
 Date        : 05/07-2021
 Description : Communication via Pipe with file descriptors
             : This function use 'read' and 'write' function calls.
 ============================================================================*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>										//exit commmand


void test01();											// Simple test, sending a message through a pipe to a child
void test02();											// Send message to child, then let the child send a message back
void terminate01();										// Terminate a child using 'kill'
void terminate02();										// 

int main(void){
	test01();
	test02();
	return 0;
}


// Creating a child, have the child ask for a number, which is then send to the parent.
void test01(){

	int fd[2];
//	int fd[0]; - read	
//	int fd[1]; - write


	if (pipe(fd) == -1) {					
		fprintf (stderr, "An error occured with opening the pipe.\n");
		exit(1);
	}

	pid_t id = fork();									// Creating a child

	if (id == -1){
	   printf("An error occured with the fork.\n");
	   exit(4);
	}
	if (id == 0){ 										// Child
	   close(fd[0]);
	   int x;
	   printf("Input a number: ");
	   scanf("%d", &x);
	   write(fd[1], &x, sizeof(int));
	   close(fd[1]);
	   exit(0);											// Terminating the child just in case.
	} else {											// Parent
	   int y;
	   if (read(fd[0], &y,sizeof(int))== -1) {
		printf("An error occured with reading from the pipe.\n");
		exit(3);
	   }
	   close(fd[0]);
	   printf("Got from child process %d\n", y);
	   wait(NULL);										// Wait for the child, and reap the PID
	}

}


// Set up pipes, 
void test02(){
	printf("Test 2\n");
	int fd1[2], fd2[2];									// Creating pipes, each pipe has 2 ends, and we need 2 pipes
	
//	int fd1[0]; - child end read
//	int fd1[1]; - parent end write
//	int fd2[0]; - parent end read
//	int fd2[1]; - child end write


	if (pipe(fd1) == -1){					
		fprintf (stderr, "An error occured with opening the first pipe.\n");
		exit(1);
	}
	if (pipe(fd2) == -1){					
		fprintf (stderr, "An error occured with opening the second pipe.\n");
		exit(1);
	}

	pid_t id = fork();									// Creating a child
	if (id == -1){
	   printf("An error occured with the fork.\n");
	   exit(4);
	}
	else if (id == 0){									// child process
		close(fd1[1]);
		close(fd2[0]);
		int temp;
		if (read(fd1[0], &temp,sizeof(int))== -1) {
		printf("An error occured with reading from the pipe.\n");
		exit(3);
		}
		close(fd1[0]);

		printf("Got from parent process %d\n", temp);
		temp *= 2;
		write(fd2[1], &temp, sizeof(int));
		close(fd2[0]);
	
	} else if (id > 0){									// parent process
		close(fd1[0]);
		close(fd2[1]);
		
		int x;

		printf("-----------------------------------------------\n"
			   "Next test, sending to child, then receiving double the value.\nInput a number: ");
		scanf("%d", &x);
 		write(fd1[1], &x, sizeof(int));
		close(fd1[1]);

		if (read(fd2[0], &x,sizeof(int))== -1) {
			printf("An error occured with reading from the pipe.adsfads\n");
			exit(3);
		}
		wait(NULL);
		printf("Got from child process %d\n", x);
		close(fd2[0]);
	}


}
