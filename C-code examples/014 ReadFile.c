/*============================================================================
 Name        : ReadFile
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 
 Date        : 28/12-2020
 Copyright   : Your copyright notice
 Description : Example of reading from a file.
 ============================================================================*/

#include <stdio.h>
#include <stdlib.h>

void main(){
    char tempArray[20];

    FILE *fp;
    fp = fopen ("derpy.txt", "r");		// Open the file with 'read' option.	''
    if(fp==NULL){ exit(-1);}
    while(!feof(fp)){

        fgets(tempArray, 20, fp);
        printf("%s", tempArray);
    }
    fclose(fp);
    printf("\n");

}

/*
Taken from the manual page for "fopen":

       r      Open text file for reading.  The stream is positioned at the beginning of the file.

       r+     Open for reading and writing.  The stream is positioned at the beginning of the file.

       w      Truncate file to zero length or create text file for writing.  The stream is positioned at the beginning of the file.

       w+     Open for reading and writing.  The file is created if it does not exist, otherwise it is truncated.  The stream is positioned at the beginning of the file.

       a      Open for appending (writing at end of file).  The file is created if it does not exist.  The stream is positioned at the end of the file.

       a+     Open  for  reading  and  appending (writing at end of file).  The file is created if it does not exist.  Output is always appended to the end of the file.  POSIX is silent on
              what the initial read position is when using this mode.  For glibc, the initial file position for reading is at the beginning of the file, but for Android/BSD/MacOS, the ini‐
              tial file position for reading is at the end of the file.
*/