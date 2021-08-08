/*-----------------------------------------------------------------------------
|                           filetest.cpp
| Version:       2.00
| Created by:    Agner Fog (original)
| Created date:  2018-10-30
| Altered by :   s090116
| Last modified: 2019-10-29
| Description:   This program shows an example of how to write and read a
|                comma-separated file
-----------------------------------------------------------------------------*/

#include <stdio.h>                               // file input/output functions

const int maxlength = 20;                        // maximum length of name string
const int maxpersons = 100;                      // maximum number of persons in database

// Define structure for person records
struct Person {
    char firstName[maxlength];                   // first name
    char lastName[maxlength];                    // last name
    unsigned int telephone;                      // telephone number
};


int main() {
    const char * filename = "myfile.txt";        // file name
    FILE * fp1;                                  // file pointer for input
    FILE * fp2;                                  // file pointer for output

    // Database of persons as array of structures
    struct Person persons[maxpersons];
    int numPersons = 0;                          // number of persons in database

    // open file for reading
    fopen_s(&fp1, filename, "r");
    if (fp1 == 0) {                              // check for error
        // write to standard error output
        fprintf(stderr, "cannot read file %s\n", filename);
    }
    else {
        char space[maxlength];                   // string for reading space

        // Read file
        while (!feof(fp1)) {                     // repeat until end of file

            if (numPersons >= maxpersons) {
                break;                           // stop if array is full
            }
            // fscanf_s works best if you read one string at a time
            // "%[^,]" will read anything but comma
            // "%[ ,]" will read spaces and commas and nothing else
            // "%[ ,\n\r]" will read spaces, commas, and newline
            // "%u" will read an unsigned integer
            fscanf_s(fp1, "%[^,]", persons[numPersons].firstName, maxlength); // read first name until comma
            fscanf_s(fp1, "%[ ,]", space, maxlength);                         // read comma
            fscanf_s(fp1, "%[^,]", persons[numPersons].lastName, maxlength);  // read last name until comma
            fscanf_s(fp1, "%[ ,]", space, maxlength);                         // read comma
            fscanf_s(fp1, "%u",    &persons[numPersons].telephone);           // read phone number
            fscanf_s(fp1, "%[ ,\n\r]", space, maxlength);                     // read newline
            numPersons++;  // count number of persons
        }
        // remember to close file
        fclose(fp1);    
    }

    // add a record
    struct Person gaga = {"Lady", "Gaga",  66666666};
    if (numPersons < maxpersons) {
        persons[numPersons] = gaga;
        numPersons++;    
    }

    // print persons
    for (int i = 0; i < numPersons; i++) {
        printf("%-20s %-20s %u\n", persons[i].firstName, persons[i].lastName, persons[i].telephone);    
    }

    // open file for writing
    fopen_s(&fp2, filename, "w");
    if (fp2 == 0) {                        // check for error
        // write error message to standard error output
        fprintf(stderr, "cannot write file %s\n", filename);
        return 1;                          // exit program with error code 1
    }
    else {
        // write persons to file    
        for (int i = 0; i < numPersons; i++) {
            fprintf(fp2, "%s,%s,%u\n",
                persons[i].firstName, persons[i].lastName, persons[i].telephone);
        }
        // remember to close file
        fclose(fp2);
    }

    // end program
    return 0;
}


