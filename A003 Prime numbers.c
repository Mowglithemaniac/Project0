/*
 ============================================================================
 Name        : Test3.c
 Author      : Declined#8151 (Discord ID)
 Version     :
 Copyright   : Your copyright notice
 Date        : 24/12-2020
 Description : Prime numbers
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int choice=-2, comparator=1, derp=1;

	printf("Type in a number between 1-20 to choose\nhow many prime numbers you would like to see?\n");

	scanf("%d", &choice);
	while(choice < 0 || choice > 20){
		printf("Value not accepted, please try again");
		scanf("%d", &choice);
	}
	printf("The first %d prime numbers are:\n", choice);

	   while(choice > -1){
	      for(derp = 1 ; derp <= (comparator - 1) ; derp++){
	         if ( comparator%derp == 0 )
	            break;
	      }
	      if ( derp == comparator )
	      {
	         printf("%d\n", comparator);
	         choice--;
	      }
	      comparator++;
	   }

	return 0;
}
