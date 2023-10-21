/*============================================================================
 Name        : min_max.c
 Author      : Declined
 Version     : 1.00
 Date        : 21/10-2023
 Description : Comparing 3 numbers to find the lowest and highest
               Program is interesting because of its error handling,
               along with accounting for variable length integer bit-size.
 ============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    int str_len, min = 0, max = 0;

// Argument check
    if(argc -4){
        //fputs because it accepts a const char argument.
        fputs("\x1b[31m[!]\x1b[0m Argument count incorrect.\n", stderr);
        exit(1);
    }

// Input value verification check.
    for(int j = 1; j < 4 ; j++){
        for(int i = 0; i < strlen(argv[j]); i++){
//Using ascii value representation, to verify that the character is supposed to be a number            
            if(argv[j][i] < '0' || '9' < argv[j][i]){
                //fprintf because it accepts a variable length argument
                fprintf(stderr, "\x1b[31m[!]\x1b[0m Argument: \"%s\" cannot be converted to a number.\n", argv[j]);
                return -1;
            }
        }
    }

/** Fix min/max values irregardless of bit-length.
 * Max will be set to the absolute lowest integer value because it can only increase from there
 * Min will be set to the absolute highest integer value because it can only decrease from there
 */
    min = ~min;
    min = (unsigned int)min >> 1;
 
    max = ~max;
    while (max << 1 != 0){
        max <<= 1;
    }

// Finding min/max values
    for(int i = 1; i < 4; i++){
        if (min > atoi(argv[i]))
            min = atoi(argv[i]);
        if (max < atoi(argv[i]))
            max = atoi(argv[i]);
    }

// Print results
    printf("Minimum value is: %d\n", min);
    printf("Maximum value is: %d\n", max);

return 0;

}