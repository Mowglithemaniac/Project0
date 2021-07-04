/*============================================================================
 Name        : 033
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : 
 ============================================================================*/

//INCOMPLETE

#include <string.h>
#include <stdio.h>

void funcCommon();
void funcUncommon();

void main(){

    char sillyTest[21] = "01234567890123456789";
    char a[] = "abc";
    char b[] = "def";
    char c[20];

    int derp = -1, i, temp = 0; 
    /** ASCII
     * 48: 0
     * 57: 9
     */
    printf("This program is designed to showcase the string.h\n"
           "library and it's associated functions.\n\n");

    while(derp!=0){
        printf( "=======================\n"
                "Type 0 to terminate the program\n"
                "Type 1 for the most common functions\n"
                "Type 2 for the less used functions\n"
                "=======================\n");
        scanf("%d", &derp);
        if(derp == 1){ funcCommon(); }
        if(derp == 2){ funcUncommon(); }        
    }
    printf("Terminating program.");
}

void funcCommon(){



    printf("=============================\n");

    printf("These are some of the commands you'll encounter the most:\n"
           "strlen, strcpy, strdup, strcat\n"
           "Respectively:\n"
            "-----------------------------\n");

    printf("strlen\t- Finds the length of a string\n" 
           "Return the string length.\n"
           "Argument\t- pointer to a NULL terminated string.\n"
           "size_t strlen(const char *s);\n"
           "-----------------------------\n");
    printf("strcpy\t- Copies string2 into string1" 
           "Return\t- A pointer to the start of str1\n"
           "Argument\t- Copies str2 into str1.\n"
           "char *strcpy(char *dest, const char *src)"
           "-----------------------------\n");
    printf("strcdup\t- Duplicate a string\n"
           "Returns\t- Pointer to the duplicate of the string, (allocated via malloc)\n"
           "Argument\t- Pointer to a NULL terminated string.\n"
           "char *strdup(const char *s);\n"
           "Beware that this function can cause an overflow of the allocated memory, and make it spill into other locations."
           "-----------------------------\n");
/*    printf("strcat\t- ");

    printf("strcasecmp,  strcat, strchr, strcmp, strcoll, strcspn, stpcpy,\n"
           "strdup, strfry, strncat, strncmp, strncpy,  strncasecmp,"
           "strpbrk,  strrchr, strsep, strspn, strstr, strtok, strxfrm, index, rindex");
*/
/*

    printf("Test: %s\n", sillyTest);
    printf("Type in something (max 20 characters\n");
    fgets(sillyTest, 21, stdin);		

    printf("Test: %s\n", sillyTest);
    i = strlen(sillyTest);
    printf("Length: %d\n", i);
*/
}









