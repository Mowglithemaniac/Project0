/*============================================================================
 Name        : Test12.c 
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 1.01
 Copyright   : Your copyright notice
 Date        : 15/01-2022
 Description : Displaying the difference between binary, octal, Signed Magnitude
               1's complement, 2's complement
               Please notice, I'm simulating a 5-bit data value, using 8-bit.
 ============================================================================*/

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte) \
    (byte & 0x80 ? 0 : 0), \
    (byte & 0x40 ? 0 : 0), \
    (byte & 0x20 ? 0 : 0), \
    (byte & 0x10 ? '1' : '0'), \
    (byte & 0x08 ? '1' : '0'), \
    (byte & 0x04 ? '1' : '0'), \
    (byte & 0x02 ? '1' : '0'), \
    (byte & 0x01 ? '1' : '0') \

 #include <stdio.h>

void main(void){
    printf("A simple table using a a 5-bit data value, to showcase data representation\n"
           "Binary\t\tHex\t\t      Octal\t\tSigned Magnitude\t1's Complement\t\t2's Complement\n"
           "----------------------------------------------------------------------------------------------------------------------\n");
    __uint8_t showcase = 0x00;
//Emulating a 5 bit data field, when in fact we're using an 8-bit data value.
    for(int i = 0; i < 32; i ++){
        printf(BYTE_TO_BINARY_PATTERN"\t\t", BYTE_TO_BINARY(showcase));                      // Binary, ensuring that the first 3 bits are ignored when printing
        printf("%.2x\t\t\t", showcase);                                                      // Hexadecimal, showing 2 digits
        printf("%2o\t\t\t", showcase);                                                       // Unsigned Octal, meaning it's always positive
        if(0x10 & showcase) printf("-%2d\t\t\t", showcase & 0x0F);                           // Signed Magnitude, negative
        else printf("%3d\t\t\t", showcase);                                                  // Signed Magnitude, positive
        if (0x10 & showcase) printf("-%2d\t\t\t", (~showcase & 0xF));                        // 1's Complement, negative
        else printf("%3d\t\t\t", showcase);                                                  // 1's Complement, positive
        if (0x10 & showcase) printf("-%2d", (~showcase & 0xF)+1);                            // 2's Complement, negative
        else printf("%3d", showcase);                                                        // 2's Complement, positive
        
        printf("\n");
        showcase++;
    }
    printf("----------------------------------------------------------------------------------------------------------------------\n");

 }