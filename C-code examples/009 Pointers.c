/*============================================================================
 Name        : Pointers.c
 Author      : 
 Author      : Declined#8151 (Discord ID), s090116
 Version     : v1.00
 Date        : 28/12-2020 
 Last updated: 17/09-2021
 Copyright   :
 Description : A tl;dr file about how pointers work
 ============================================================================*/

#include <stdio.h>

void basic();
void basicFunction();
void basicArray();
void badExampleFunction(int derp);
void godExampleFunction(int *derp); 
void exampleArray(int array[], int length);


void main(void){

       printf("This program illustrates the use of pointers.\n"
              "A pointer is an object that looks at the address of another object.\n");
       basic();
       basicFunction();
       basicArray();
 
}

void basic(){
    int i, k, *ip;
    ip = &i;
    i = 100;
    k = 400;
    void *kp;


    printf("============================================\n\n"
           "This paragragh will be focusing on the basics\n"
           "using 4 categories of increasing difficulty.\n\n");
    
    printf("Simple initialization of the values.\n");
    printf("Value\t\tValue,\t\t'Deferenced' \tAddress\n");
    printf("i = %5d,\t", i);
    printf("k = %5d,\t", k); 
    printf("*ip = %5d,\t", *ip);
    printf("ip = %5p,\n\n", ip);

    
    i = *(&i);                      // i = 'i'
    i = *ip / 2 + 2;                // i = 'i' / 2 + 2  : i = '52'
    *ip = i * 2 - 2;                // 'i' = i * 2 -2   : i = 52 * 2 - 2 => 102
    *(&k) = 200;                    // 'k' = 200;
    printf("Simple changes\n"
           "Value\t\tValue,\t\t'Deferenced' \tAddress\n");
    printf("i = %5d,\t", i);
    printf("k = %5d,\t", k); 
    printf("*ip = %5d,\t", *ip);
    printf("ip = %5p,\n\n", ip);
    
    kp = &k; 
    *(&k) = 400;                    // 'k' = 400        - the '&' looks at the address, and then the '*' deferences it
    k = *(int *)kp * 2 + 2;         // k = ('k' *2 + 2) - = '802' since kp is defined as 'void *' we need to typecast it to 'int *'. 
    *ip = i + 3;                    // 'i' = i +3
    printf("Fancy use of pointers:");
    printf("\nValue,\t\tAddress\t\t\t'Deferenced' \tAddress\n");
    printf("i = %5d,\t", i);
    printf("ip = %5p,\t", ip);
    printf("*kp = %5d,\t", *(int*)kp);
    printf("kp = %5p,\n\n", kp);

    printf("Fancy memory stuff\n"
           "ip++ will move the pointer forward to look at 'k' rather than 'i'\n"); 
    *ip++;                          // *(ip++)          - The pointer has been changed to look at the next address, because ++ has higher presedence. The '*' does nothing here.
    printf("Value,\t\tAddress\t\t'Deferenced' \tAddress\n");
    printf("i = %5d,\t", i);
    printf("*ip = %5d,\t", *(int*)ip);
    printf("*kp = %5d,\t", *(int*)kp);
    printf("ip = %5p,\n\n\n", ip);
    
}


//Pointers or values through functions
void basicFunction(){
       printf("============================================\n\n"
              "What happens when sending values or pointers through functions\n"
              "Using 2 simple examples, submitting as direct, and indirect (pointer) .\n\n");
       int derp = 10;
       printf("Each of these functions will double the value\n");

       printf("Original value of 'derp': %d\n\n", derp);
       badExampleFunction(derp);
       printf("Result after direct  \t  %d\n", derp);
       
       godExampleFunction(&derp);
       printf("Result after indirect\t  %d\n\n", derp);
       /**When you pass a variable to a function,
        * you're creating a copy of that variable,
        * so in order to alter it within the original function,
        * you need to pass the pointer to that variable,
        * so you'll have access to the original and not just the copy.
        */
    
}

void basicArray(){
    printf("============================================\n\n"
           "When dealing with arrays, the name itself is treated as a pointer\n"
           "A single simple example\n\n");
    int derp[] = {2, 3, 5, 7, 11};
    printf("Content of original array\n");
    for(int i = 0; i < 5; i++){
       printf("%d", derp[i]);
       if(i != 4){ printf(", ");}
    }
    printf("\nIncrementing the value within, by 1, by passing the name of the array\n");
    exampleArray(derp, sizeof(derp)/sizeof(derp[0]));
    printf("Content after passing through a function\n");
    for(int i = 0; i < 5; i++){
       printf("%d", derp[i]);
       if(i != 4){ printf(", ");}
    }
    printf("\n\n");
}


void badExampleFunction(int derp){
     derp *= 2;
}

void godExampleFunction(int *derp){
    *derp *= 2;
}

void exampleArray(int array[], int length){
   for(int i = 0; i < length; i++){
      array[i]++;
   }
}

