/*============================================================================
 Name        : Test 004 Loops
 Author      : s090116
 Version     :
 Date        : 26/1-2021
 Copyright   : Your copyright notice
 Description : Illustrates the use of loops
 ============================================================================*/

#include <stdio.h>

void loop_for();
void loop_while();
void loop_dowhile();
void loop_example();

void main(){
    int i, j, k;

    printf("This program will illustrate the use of loops.\n"
           "- for\n"
           "- while\n"
           "- do while\n"
           "- Example of continue/break implementation\n");

    loop_for();
    loop_while();
    loop_dowhile();
    loop_example();
}

void loop_for(){
    int i, j;
    /****
     * 3 different methods to achieve
     * the exact same result
     * (Prints a 10x10 box counting from 0-99)
     */
    printf("-----------------------------\n"
        "For-loop\n");


    //method 1
    printf("method 1\n");
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("%2d\t", i*10+j);
        }
        printf("\n");
    }

 //Method 2, cleaner, but requires a bit better understanding of modulu
    printf("method 2\n");
    for(i=0;i<100;i++){
        printf("%2d\t", i);
        if((i+1)%10 == 0){ printf("\n"); }
    }

//Method 3, multiple initializations
    printf("Method 3");
    for(i=-1, j = 0; i<10;j++){
        i++;
        if(j%10==0){
            printf("\n");
            j=0;
        }
        else {i--;}
        if(i == 10){break;}
        printf("%2d\t", i*10+j);
    }
}

void loop_while(){
    int k;
    printf("-----------------------------\n"
           "while loop\n");
    k = 0;
    //Prints from 0-10
    while(k < 10){
        printf("%d\t", k);
        k++;
    }
    /**At this point k is 10, so if you were to use it again,
     * make sure that you know what value it is.
     */
}

void loop_dowhile(){
    int k = 10;
    printf("\n-----------------------------\n"
        "do while loop\n");
    /**We've continued from the previous, and let k be 10,
    * according to the boolean operator, k is NOT greater than 10
    * and therefore the 1st iteration of the loop only run
    * because it is being forced to do so with with the 'do' part
    */
    do{
        printf("%d\t", k);
        k++;
    }while(k > 10 && k < 20);
}

void loop_example(){
    printf("\n-----------------------------\n"
           "An example of break/continue\n");
    int k=0;
    /** while(1), meaning that the look will continously run, 
     * throughout infinity
     * while(0), meaning that it's never supposed to run
     * 
     * This function is basically an overly complicated method to write
     * all even numbers between [0-99].
     */
    while(1){
       do{
           /**'continue' will move the Program Counter to the
            * start of the loop.
            * Because the loop is set up as while(0)
            * it'll essentially terminate the loop
            * aka work as 'break'
           */
            if(k%2==1){
                continue;
            }
            printf("%2d\t", k);
        }while(0);
        k++;
        if(k%10==0){ printf("\n");}
        if(k >= 100){
            break; //terminates the current loop.
        }
    }
}


