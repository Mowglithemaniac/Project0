/*
 ============================================================================
 Name        : A001.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 1.00
 Date        : 27/06-2022
 Copyright   : Your copyright notice
 Description : Prints a few special characters
 ============================================================================
 */

/*
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>                      //O_RDONLY
*/

#include <stdio.h>                      //printf
#include <stdlib.h>                     //EXIT_FAILURE
#include <errno.h>                      //errno
#include <unistd.h>                     //close()
#include <fcntl.h>                      //O_RDONLY
#include <string.h>                     //From char * to char []

int main(int argc, char *argv[]) {

    int something[7] = {0x00, 11, 0x22, 0x30, 0x7F, 168, 0xFF}, error;

    char file_name[] = "derp.bin";
    FILE *fp;
    fp = fopen (file_name, "wb");
    if (!fp) { //pf == NULL
		error = errno;
//        fprintf(stderr, "[!]File error: %s\n", strerror(errno));
        fprintf(stderr, "[!]File error: %s\n", strerror(error));
        exit(errno);  
    }
    for(int i = 0; i < 7; i++){
//        fputc((unsigned int)something[i], fp);		// <-- This is crap because it ignores leading 0x0, and extend with 4*f in case of most significant bit being 0
		fwrite(&something[i], sizeof(char), 1, fp);
    }
    if(fclose(fp)){
        fprintf(stderr, "[!] Error\t: %s\n", strerror( errno ));
        exit(errno);  
    }
    return 0;
}
