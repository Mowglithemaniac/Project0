/*============================================================================
 Name        : ReadFile
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 1.00
 Date        : 17/03-2020
 Copyright   : Your copyright notice
 Description : Example of file descriptor usage
 ============================================================================*/


 #include <stdio.h>
 #include <unistd.h>


void main(){

    printf("[X] FD 1, stdout, printf\n");
//    perror("[!] FD 2, stderr perror\n");
    fprintf(stdout, "[X] FD 1, stdout, fprintf\n");
    fprintf(stderr, "[!] FD 2, stderr fprintf\n");
//    fprintf(4, "[?] FD 4, fprintf\n");
}