/*============================================================================
 Name        : pthread overview
 Author      : Declined#8151 (Discord ID), s090116
 Version     : v1.00
 Copyright   : Your copyright notice
 Date        : 29/07-2021
 Last updated: 31/09-2021
 Description : Showcasing multiple aspects of pthreads
               Using a very common of distributing a shared memory between
               processes.
 Compile     : gcc -pthread -o output filename.c
 ============================================================================*/


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define MAXSIZE 10

int binaryTable[MAXSIZE] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

struct threadInfo {
    int threadCount;
    int threadMax;
    int output;
};

int intro();
void case1();
void case2();
void case3(int numThreads);

void *function1();
void *function2(int *derp);
void *function3(struct threadInfo *details);


int main(int argc, char *argv[]){
    int derp = intro();
    case1();
//    sleep(1);
    case2(1);

    case3(derp);
}

int intro(){
    char dummyCheck[2];
    int choice = -1, areyouadummy = 999;
    
    printf("This is a program to showcase some aspects of pthreads\n"
           "How many threads would you like to test with (1-10)?\n");
    scanf("%d", &choice);
    
    fgets(dummyCheck, 2, stdin);
    if(dummyCheck[0] != '\n')
        return 0x596573;
    return choice;
}


/** Simple showcase of how a pthread is executed
 *  
 */
void case1(){
    printf("Case 1:\n");
    pthread_t athread;

    if(pthread_create(&athread, NULL, &function1, NULL) != 0){
        perror("Failed to create thread\n");
        exit(1);
    }
    if(pthread_join(athread, NULL) != 0){
        perror("Failed to join thread\n");
        exit(3);
    }


}

/** Passing an argument to a thread
 */
void case2(){
    printf("Case2:\n");
    int *somevalue = &binaryTable;
    pthread_t threadthingy;
    if(pthread_create(&threadthingy, NULL, &function2,somevalue) != 0)
        perror("Failed to create thread.\n");
    if(pthread_join(threadthingy, NULL) != 0)
        perror("Failed to join thread.\n");
}

/**Example of a common thread operation
 * taking the content of an array and 
 * 
 */
void case3(int numThreads){
    printf("Case 3: ");
    if (numThreads == 5858675){
        printf("You're a dumbass\n");
        return;
    }
    printf("With %d threads\n", numThreads);
    if(numThreads > 10 || numThreads < 0){
        printf("Number of threads should be between 1-10\n");
        return;
    }
    struct threadInfo *details;
    pthread_t threadthingy[numThreads];
    int globalSum = 0;
    int* intPtr;

    for(int i = 0; i < numThreads; i++){
        details = malloc(sizeof(struct threadInfo));
        details->threadMax = numThreads;
        details->threadCount = i; 
        if(pthread_create(&threadthingy[i], NULL, &function3, (void *)details) != 0)
            perror("Failed to create thread.\n");
    }

    void *received;
    struct threadInfo *something;

//Notice this is a critical section,and thus incrementing the globalSum is sequentially
    for(int i = 0; i < numThreads; i++){
        if (pthread_join(threadthingy[i], &received) != 0) {
            perror("Failed to join thread");
        }
        something = received;
        globalSum += something->output; 
        free(something);
    }
    printf("Global sum: %d\n", globalSum);
    return;
}

void *function1(){
    printf("Thread here, posting stuff\n");
}

void *function2(int *derp){
    printf("Thread here, received values: { ");    
    for(int i = 0; i < MAXSIZE; i++){
        printf("%d", derp[i]);
        if(i != MAXSIZE - 1)
            printf(", ");
    }
    printf("}\n");
}

//Getting the sum from an array
void *function3(struct threadInfo *details){
    int sum = 0;

//Need to determine which part of the array, the thread is responsible for.
    int start, end, avg;
//Is the array evenly distributed among the cores?
    if( MAXSIZE %  details->threadMax == 0){ // Yes it is
        avg = MAXSIZE/details->threadMax;
        start = details->threadCount * avg;
        end = (details->threadCount + 1) * avg;
    } else  // No it isn't 
    if ((float)MAXSIZE / details->threadMax < 2 && (float)MAXSIZE / details->threadMax > 1){ //threads numbering start to half MAXSIZE, get to do stuff
        if(details->threadCount != 0 && MAXSIZE/details->threadCount <= 2){ //technically 2, but integers are rounded down.
            details->output = 0;
            return details;
        }

        start = details->threadCount * 2;
        if(MAXSIZE/ (details->threadCount + 1) == 2 )
            end = MAXSIZE;
        else
            end = (details->threadCount +1)* 2;
    } else { // Equal to, or less than half the number of threads compared to values
        avg = (MAXSIZE/details->threadMax) +1;
        start = details->threadCount * avg;
        if(details->threadCount != details->threadMax -1){
            end = (details->threadCount+1) * avg;
        } else {
            end = MAXSIZE;
        }
    }

    for(int i = start; i < end; i++){
        sum += binaryTable[i];
    }
    details->output = sum;
//    free(details);
    return details;
}





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