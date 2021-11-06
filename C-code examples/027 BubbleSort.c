/*============================================================================
 Name        : Test27.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : v1.01
 Date        : 6/11-2019
 Last updated: 6/11-2021
 Copyright   : 
 Description : A simple program to showcase bubblesort.
 ============================================================================*/

#include <stdio.h>
#define ARRAYSIZE 10

int printArray(int array[], int size);
void BubbleSort(int array[], int size);

int main(void){

    int array[] = {20, 22, 42, 3, 234, 75, 3, 2, 27, 72};
    printf("This is the content of the initial array:\n");
    printf("Total: %d\n", printArray(array, ARRAYSIZE));

    BubbleSort(array, ARRAYSIZE);

    printf("After sorting:\n");
    printArray(array, ARRAYSIZE);

}

int printArray(int arrayThingy[], int size){
    int temp = 0;
    for(int i = 0; i < size; i++){
        printf("%d", arrayThingy[i]);
        if(i != 9){ printf(", ");}
        else {printf("\n");}
        temp += arrayThingy[i];
    }
    return temp;
}

void BubbleSort(int array[], int size){
    int temp;
    for(int i=0; i < ARRAYSIZE-1; i++){ //go forward
        if(array[i] > array[i+1]){ //go backward
            for(int j = i+1;j != 0 && array[j] < array[j-1] ; j--){
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }
    }

}

