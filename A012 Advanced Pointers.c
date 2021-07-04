/*============================================================================
 Name        : Test12.c
 Author      : DTU - 2020 exam, course 02321
 Edited by   : s090116
 Version     : v1.00
 Copyright   : Your copyright notice
 Description : Advanced use of pointers and memory
             : Rewritten slightly to improve the format.
 ============================================================================*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct complex{
	int r;
	int i;
} complex;

void* (*add)(void*, void*);

void* add_int(void *a, void *b){
	*(int*)a = *(int*)a + *(int*)b;
	return (int*)b+1;
}

void* add_complex(void *a, void *b){
	/*********************************/
    *(int*)a = *(int*)a + *(int*)b;
    *(int*)(a-sizeof(int)) =  *(int*)(a-sizeof(int)) + *(int*)(b-sizeof(int));
	
    return (int*)b+2;
}

void* add_str(void *a, void *b){
	/*********************************/
    strcat(a, " ");
    strcat(a, b);
}

#define SIZE 5

int main(){
	int intarray[SIZE]={3, 4, 2, 77, 3};
	complex complexarray[SIZE]={{3, 7},{2, 0},{7, 9},{8, 1},{0, 3}};
	char* strarray[SIZE]= {"This", "is", "an", "interesting", "experiment"};
	int i, intres;
	complex complexres;
	char strres[100];
	void *psum;
	void *pnext;
	int type=0;

	while (1){
		intres = 0;
		strres[0]='\0';
		complexres.r=0; complexres.i=0;
		printf("Input the type of addition (1-integer, 2-complex, ");
		printf("3-string):");
		scanf("%d", &type);

        if (type == 1){
            add = add_int;
			psum= &intres;
			pnext = intarray;
        }
		else if (type == 2){
			/*********************************/
            psum = &complexres.i;
            pnext = &complexarray[0].i;
            add = add_complex;
            
		}
		else if (type == 3){
			/*********************************/
			strcpy(strres, strarray[0]);
            for(i = 1; i <5; i++){
                add_str(strres, strarray[i]);
            }

		} else { break; } //terminate program

		for (i=0; i<SIZE; i++){
				pnext = add(psum, pnext);
		}

		if (type == 2){
			printf("Sum of complex values = %d + %d*i\n",
					complexres.r, complexres.i);
		} else if (type == 3){
 //           printf("test = %s", strarray[0]);
			printf("Sum of strings = %s\n", strres);
		} else {
			printf("Sum of integers = %d\n", intres);
		}
	}
    printf("Terminating program.\n");
	return 0;
}
