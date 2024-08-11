/*============================================================================
 Name        : A027.c
 Author      : Declined#8151 (Discord ID)
 Edited by   : 
 Version     : v1.02
 Date		 : 26/12-2020
 Last updated: 11/08-2024
 Copyright   : 
 Description : How many bits are used for a specific datatype, the command
               sizeof() can also be used to find the amount of bytes.
               (Bits = bytes * 8)
 ============================================================================*/

#include <stdio.h>
#include <stdint.h>                                                     // uintptr_t

/* Function prototype */
void Method1();

/* Main */
int main(void){
    Method1();                                                          //Calling the function
    return 0;
}


void Method1(){                                                         // Checking each data type through bitwise operators, rather than sizeof()
    int result[8];
    int loop, a;
    unsigned int b = 0;
    short int c = 0;
    long int d = 0;
    long e = 0;
    long long f;
    char g = 0;
    void *h = NULL;  


//testing int
    for(loop = 0, a = 1; a != 0; loop++){
       a *= 2;
    }
    result[0] = loop;

//testing unsigned int
    for (loop = 0, b = 1; b != 0; loop++){
       b *= 2;
    }
    result[1] = loop;

//testing short int
    for (loop = 0, c = 1; c != 0; loop++){
       c = c * 2;
    }
    result[2] = loop;

//testing long int
    for (loop = 0, d = 1; d != 0; loop++){
       d = d * 2;
    }
    result[3] = loop;

//testing long
    for (loop = 0, e = 1; e != 0; loop++){
    	e = e * 2;
    }
    result[4] = loop;

//testing long long
    for (loop = 0, f = 1; f != 0; loop++){
        f = f * 2;
    }
    result[5] = loop;

//testing character
    for (loop = 0, g = 1; g != 0; loop++){
        g = g * 2;
    }
    result[6] = loop;


//testing pointer
    for (loop = 0, h = (void *)0x1; h != 0; loop++){
        h = (void *)((uintptr_t)h << 1);
    }
    result[7] = loop;

    printf("This program will calculate the bit length of different variable types.\n");
    printf("int\t\t: %.2i\n", result[0]);
    printf("unsigned int\t: %.2i\n", result[1]);
    printf("short int\t: %.2i\n", result[2]);
    printf("long int\t: %.2i\n", result[3]);
    printf("long\t\t: %.2i\n", result[4]);
    printf("long long\t: %.2i\n", result[5]);
    printf("char\t\t: %.2i\n", result[6]);
    printf("Pointer\t\t: %.2i\n", result[7]);

}
