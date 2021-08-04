/*============================================================================
 Name        : Test23.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : v1.00
 Date        : 10/10-2019
 Copyright   : 
 Description : Add values for an array, then sort and provide some info.
 ============================================================================*/

#include <stdio.h>
#include <stddef.h>


int main(void)
{
	int AR[100];																		//creating an array
	for (size_t i = 0; i < 100; i++) {													//setting all values to 0 is generally a good practice, but not required
		AR[i] = 0;
	}

	int k;																				//This is the most important user imput, explanation in the printf
	printf_s("Welcome to the array program!\nChoose between 1-100 how many rows you'd like to include:\n");
	scanf_s("%i", &k);
	while (k > 100 || k < 1) {															//Making sure the entered value is between 1-100
		if(k == 0){
			printf("Terminating program.\n");
		}
		printf_s("Sorry the value you've entered is incorrect, please try again.\n");
		scanf_s("%i", &k);
	}

	printf("We're now ready to proceed, type in the numbers you'd like to enter:\n");	//Explanation in printf
	for (int i = 0; i < k; ++i) {														//for-loop to increment the row where we enter the value
		printf_s("Type in a number: ");
		scanf_s("%i", &AR[i]);
	}

																						//Time to calculate the total value of the entered numbers
	int sum = 0;
	for (int i = 0; i < k; ++i) {

		sum += AR[i];																	//taking the previous numbers and adding them into the new sum
	}
	printf_s("\nTotal value of the entered numbers: %i", sum);

																						//Time to calculate the average value of the entered numbers
	float average = 0;
	for (int i = 0; i < k; ++i) {

		average += AR[i];
	}
	printf_s("\nAverage value of the entered numbers are: %.3f", (float)sum / k);


	for (unsigned int j = 1; j < k; ++j) {												//Using the bubblesort algorithm to organize the array
																						//loop to control number of comparisons per pass
		for (size_t i = 0; i < k - 1; ++i) {
			//compare adjacent elements and swap them if first
			//element is greater than second element.
			if (AR[i] > AR[i + 1]) {
				int hold = AR[i];
				AR[i] = AR[i + 1];
				AR[i + 1] = hold;
			}
		}
	}

	//test to show the sorted array
/*printf_s("\nThis is your array in order of lowest to highest:\n");
	for (size_t i = 0; i < k; ++i) {
		printf("%4d", AR[i]);
	} */

																						//Since I've organized the array, I just need to show the lowest and highest numbers.
	printf("\nThis is the lowest entered number: %d", AR[0]);
	int q = k - 1;																		//IMPORTANT: arrays start at the value 0,  so the value the user has entered will always be 1 higher than the specific max array number
	printf("\nThis is the highest entered number: %d", AR[q]);

																						//time to find duplicates, this method is only possible because we used bubblesoft to sort it.
	int count = 1;																		//Start the counter at 1 since you have any number 1* times
	for (int i = 0; i < k; ++i) {
		if (AR[i] == AR[i + 1]) {															
			count++;
			continue;																	//This function returns the value to the for-loop and run it again, without executing the remainder of the for-loop. (important function)
		}
		if(count > 1){
		printf("\nNumber %i, is shown: %i times", AR[i], count);
		}
//		printf("\nTest counter for my own benefit: %i", count);
		count = 1;																		//Making sure to reset the counter
	}

	return 0;

}
