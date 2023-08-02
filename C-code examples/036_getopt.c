/*============================================================================
 Name        : 036_getopt.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 1.00
 Date        : 11/07-2021
 Copyright   : Your copyright notice
 Description : gcc -o test 036_getopt.c
             $ ./test-aderpf derp bad "invalid input" 
 ============================================================================*/
//#include "filename.h"

#include <stdio.h>
#include <unistd.h>


/**
 * @brief This code is built to test argument usage 
 * @optarg This variable is used to catch additional arguments
 * @optopt This variable is used to manually catch any incorrectly passed options
 * @optind this integer, which is used to access the unused arguments, the example arguments showcase the result somewhat clearly
 */
int main(int argc, char *argv[]){
    /**
     * @brief Explanation of the format
     * When the first character is a colon, it signals that error handling will be accounted for by the program.
     * Any character followed by a colon does require an argument.
     * 'd', 'e', 'r', 'p' does not require an argument
     * 'f' does require an argument
     */
    //supported arguments
    char *supported = ":derpf:";
    int opt = 0;
    int result = 0;

    while((opt = getopt(argc, argv, supported)) != -1){ 
        switch(opt){
            case 'd':
                printf("Option 'd' was used\n");
                result |= (int)0x01;
                break;
            case 'e':
                printf("Option 'e' was used\n");
                result = result | (0x02) ;
                break;
            case 'r':
                result = result | (0x04) ;
                break;
            case 'p':
                printf("Option 'e' was used\n");
                result = result | (0x08) ;
                break;
            case 'f':
                // Note if no additional argument is supplied after 'f' is used, it will not pass
                printf("Option 'f' was used, passed parameter is: %s\n", optarg);
                break;
            case '?':
                printf("Case '?' '%c' was used.\n", optopt);
                break;
            default:
                //Code never reaches here
                printf("Unknown parameter '%c' used.\n", optopt);
                break;
        }
    }
 
    for(int i = optind; i < argc; i++){     

        printf("%d\t: Extra arguments: %s\n", i, argv[i]); 
    }
    
    if (result == 0xF)
        printf("Derp passed\n");

    return 0;
}