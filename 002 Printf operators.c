/*============================================================================
 Name        : Test5.c
 Author      : Declined#8151 (Discord ID)
 Version     : v1.00
 Copyright   : Your copyright notice
 Description : printf operators
============================================================================*/

#include <stdio.h>

/* prototypes */
void printf_info();
void printf_showcase();

int main(void){
    int derp=10, a = 10;
    float b = 10.13456;
    char c = 100; //ASCII "d"
    int safetyvalve = 0;
    printf( "This program is designed to show case print operators:\n");

    while(derp!=0){
        if(safetyvalve > 1){ break; }
        printf( "=======================\n"
                "Type 0 to terminate the program\n"
                "Type 1 to get information about operators\n"
                "Type 2 for a showcase\n"
                "=======================\n");
        scanf("%d", &derp);
        if(derp == 1){
            printf_info();
            safetyvalve = 0;
            derp = 10;
        } else
        if(derp == 2){
            printf_showcase();
            safetyvalve = 0;
            derp = 10;
        } else
        {
            printf("Invalid choice\n");
        }
        safetyvalve++;        
    }
    printf("Terminating program.\n");
}

void printf_info(){
    /** Format specifiers:
     * How to print from data, such as
     * char, string, int, float, double
     * and so on.
     * It is VERY important to know that when
     * using strings, you're printing from an array 
     * the last character MUST be NULL (aka '\0')
     */
    printf( "=======================\n"
            "Format specificers:\n"
            "=======================\n"
            "%%c \t- Character\n"
            "%%d \t- Decimal (integer) number (base 10)\n"
            "%%e \t- Exponential floating-point number\n"
            "%%f \t- Floating-point number\n"
            "%%i \t- Integer (base 10)\n"
            "%%o \t- Octal number (base 8)\n"
            "%%s \t- String of characters\n"
            "%%u \t- Unsigned decimal (integer) number\n"
            "%%x \t- Number in hexadecimal (base 16)\n"
            "%%p \t- Printes the addresss that a pointer points to\n"
            "%%%% \t- Print a percent sign\n"
            "\\%% \t- Print a percent sign\n\n");
    /**Special characters
     */
    printf( "=======================\n"
            "Special characters:\n"
            "=======================\n"
            "\\a \t- Audible alert\n"
            "\\b \t- Backspace\n"
            "\\f \t- Form feed\n"               // ASCII value of '12', it means 'advance downwards to the next page'
            "\\n \t- Newline, or linefeed\n"    //
            "\\r \t- Carriage return\n"         // Move cursor to the start of the line
            "\\t \t- tab\n"
            "\\v \t- Vertical tab\n"
            "\\\\ \t- Backslash\n\n");

    /**Controlling width
     */
    printf( "=======================\n"
            "Controlling width:\n"
            "=======================\n"
            "Here, '#' represents a number in decimal.\n"
            "%%#d \t- Minimum width of '#', right shifted\n"
            "%%-#d \t- Minimum width of '#', left shifted\n"
            "%%0#d \t- Zero fill option\n\n");
 
    /** Controlling the floating point number
     *
     */     
    printf( "=======================\n"
            "Controlling the \n"
            "floating point number:\n"
            "=======================\n"
            "Here, '#' represents a number in decimal.\n"
            "%%.#f \t- # number of decimals included\n\n");
}

void printf_showcase(){
    char a = 168; //ASCII 168 = upside down questionmark.
    char alpha = 63; //ASCII 63 = Questionmark
    char b[] = "This is a showcase";
    char c[] = {'T','h','i','s',' ','i','s',' ','b','o','t','h','e','r','s','o','m','e'};
    int d = 255;
    int e = 7;
    float f = 0.123456789;
    printf("==============================================\n"
           "             Format specificers:\n"
           "==============================================\n"
           " * Single character\n");
            
        // 
    printf("Showing the the same character in different ways.\n");

    printf("As character '%%c' \t: %c\n", a);
    printf("As decimal '%%d' \t: %d\n", (int)a+256); //stored as FFFFFF, so we manipulate the bits from place 9 and onwards
    printf("As unsigned int '%%u \t: %u\n", (int)a+256);
    printf("As octal '%%o \t\t: %o\n", (int)a+256);
    printf("As hex '%%x \t\t: %x\n", (int)a+256);
    printf("Addresss of char '%%p' \t: %p\n", &a);
    printf("=======================\n");
    printf(" * Special characters\nDisplaying them as 'test\\n test'\n");
    printf("Audible alert '\\a'\t:Test\a test\n");
    printf("Backspace '\\b' \t\t: Test\b test\n");
    printf("Form feed '\\f' \t\t: Test\f test\n");
    printf("Newline or linefeed '\\n': Test\n test\n");
//    printf("Carriage return '\\r'\t: Test\r test\n");
    printf("Tab '\\t' \t\t: Test\t test\n");
    printf("Vertical tab '\\v' \t: Test\v test\n");
    printf("----------------------\n");
    printf("Carriage return is a bit special, next sentence is entered like this:\n"
           "Carriage return '\\\\r'\t: Test\\r test\n"
           "And this is the result:\n");
    printf("Carriage return '\\r'\t: Test\r test\n");



   printf("=======================\n");
   printf(" * Controlling width\n");
   printf("Initial (default) value to demonstrate with: %f\n", f);
   printf("Length \t: 1\tValue : %.1f\n", f);
   printf("Length \t: 2\tValue : %.2f\n", f);
   printf("Length \t: 3\tValue : %.3f\n", f);
   printf("Length \t: 4\tValue : %.4f\n", f);
   printf("Length \t: 5\tValue : %.5f\n", f);
   printf("Length \t: 6\tValue : %.6f\n", f);
   printf("Length \t: 7\tValue : %.7f\n", f);
   printf("Length \t: 8\tValue : %.8f\n", f);
   printf("Length \t: 9\tValue : %.9f\n", f);
   printf("Once more for an integer: %d\n", d);
   printf("Length \t: 1\tValue : %01d\n", d);
   printf("Length \t: 2\tValue : %02d\n", d);
   printf("Length \t: 3\tValue : %03d\n", d);
   printf("Length \t: 4\tValue : %04d\n", d);
   printf("Length \t: 5\tValue : %05d\n", d);
   printf("Length \t: 6\tValue : %06d\n", d);
   printf("Length \t: 7\tValue : %07d\n", d);
   printf("Length \t: 8\tValue : %08d\n", d);
   printf("Length \t: 9\tValue : %09d\n", d);

   printf("=======================\n");
   printf(" * Controlling location (right vs left shiftd)\n");
   printf("Displaying right shifted: %d\n", d);
   printf("Length \t: 1\tValue : %1d\n", d);
   printf("Length \t: 2\tValue : %2d\n", d);
   printf("Length \t: 3\tValue : %3d\n", d);
   printf("Length \t: 4\tValue : %4d\n", d);
   printf("Length \t: 5\tValue : %5d\n", d);
   printf("Length \t: 6\tValue : %6d\n", d);
   printf("Length \t: 7\tValue : %7d\n", d);
   printf("Length \t: 8\tValue : %8d\n", d);
   printf("Length \t: 9\tValue : %9d\n", d);
   
   printf("\nHow it looks like in a table:\n");
   printf("Right shifted with base: '%%9'\n");
   int i;
   for(i = 1; i <= 10; i++){
        printf("R: %9i\t", e);
        if(i%5==0){printf("\n");}
        e *= 10;     
   }

   printf("\nLeft shifted with base -9: '%%-9'\n");
   e = 7;
   for(i = 1; i <= 10; i++){
        printf("L: %-9i\t", e);
        if(i%5==0){printf("\n");}
        e *= 10;     
   }
   
}

/*============================================================================
 Cheat sheet:
 https://alvinalexander.com/programming/printf-format-cheat-sheet/
 ============================================================================*/
