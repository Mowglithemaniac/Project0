/*============================================================================
 Name        : pthread example
 Author      : Declined#8151 (Discord ID), s090116
 Version     : v1.00
 Copyright   : 
 Dato        : 
 Description : Combined version of 014 and A007, to read the content of a file
             : into nodes in a Doubly Linked List.
 Compile     : gcc -pthread -o output filename.c½
 ============================================================================*/


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *routine();

int main(int argc, char *argv[]){
    pthread_t one, two;
/**   int pthread_create(
 *      pthread_t *__restrict__ __newthread,
 *      const pthread_attr_t *__restrict__ __attr,
 *      void *(*__start_routine)(void *),
 *       void *__restrict__ __arg)
 * Mearning that the arguments for this function is:
 *  1st: The address of a created 'pthread_t' variable
 *  2nd: A 'pthread_attr_t' variable. 
 *  3rd: The address function that the thread is going to execute
 *  4th: any arguments used in the function
 * 
 */ 
    if(pthread_create(&one, NULL, &routine, NULL) != 0){
        perror("Failed to create thread\n");
        return 1;
    }
    if(pthread_join(one, NULL) != 0){
        perror("Failed to join thread\n");
        return 3;
    }
}

void *routine(){
    printf("Thread here, posting stuff\n");
}

