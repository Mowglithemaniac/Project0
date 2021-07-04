/*============================================================================
 Name        : Test22.c
 Author      : CodeVault
 Edited by   : s090116
 Version     : v1.00
 Copyright   : source: https://www.youtube.com/watch?v=Mqb2dVRe0uo
 Description : Communication via Pipe with file descriptors
 ============================================================================*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(void){
	int fd[2];
//	int fd[0]; - read	
//	int fd[1]; - write

	if (pipe(fd) == -1) {					
	   printf("An error occured with opening the pipe\n");
	   return 1;
	}

	int id = fork();

	if (id == -1){
	   printf("An error occured with the fork.\n");
	   return 4;
	}
	if (id == 0){ //child
	   close(fd[0]);
	   int x;
	   printf("input a number: ");
	   scanf("%d", &x);
	   write(fd[1], &x, sizeof(int));
	   close(fd[1]);
	} else {
	   int y;
	   if (read(fd[0], &y,sizeof(int))== -1) {
		printf("An error occured with reding from the pipe.\n");
		return 3;
	   }
	   close(fd[0]);
	   printf("Got from child process %d\n", y);
	}
	
	return 0;
}