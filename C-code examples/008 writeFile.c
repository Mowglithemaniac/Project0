/*============================================================================
 Name        : 015 writeFile.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 1.01 (included a warning)
 Date        : 24/12-2020
 Last updated: 10/08-2024
 Copyright   : Your copyright notice
 Description : Example of writing to a file.
 ============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

const int maxArraySize = 128;

int main(){
    FILE *fp;
    char tempArray[maxArraySize];
    int i = strlen(tempArray);
    char *test = "test1\ntest2\ntest3";

    printf("Enter a filename that you want to write something to.\n"
           "=======================WARNING=======================\n"
           "Choose a file that does NOT already exist!!!\n"
           "=======================WARNING=======================\n");
    /**This program will overwrite the content of any file you choose
     * therfore it is recommended to come up with a bogus name such as
     * 'derp.txt' or simply 'derp'
     */
    fgets(tempArray, maxArraySize, stdin);
    
    /** with fgets, the last character is '\n'
     * the last char needs to be changed to NULL 
     */
    tempArray[i-1] = '\0';

    // Inserting error handling, check if file exist
    struct stat buffer;
    if (stat(tempArray, &buffer) == 0) {
        fprintf(stderr, "[!] File already exist, terminating program!\n");
        return 1;
    }

    fp = fopen(tempArray, "w");
    fprintf(fp, "%s", test);
    fclose(fp);
    return 0;
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
