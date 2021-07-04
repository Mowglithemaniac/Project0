/*
 ============================================================================
 Name        : A001.c
 Author      : Declined#8151 (Discord ID)
 Version     :
 Copyright   : Your copyright notice
 Description : ASCII
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	printf("This program is supposed to print 254 ASCII characters\n");
	char c;
	int i;
	for(i = 1; i < 255; i++){
		c = i;
		printf("%.3i : %c\t", i, c);
		if((i % 10 )== 0){
			printf("\n");
		}
	}
	printf("\n");
	return 0;
}
