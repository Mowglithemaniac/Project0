/*============================================================================
 Name        : 008 Pointers.c
 Author      : 
 Edited by   :  s090116
 Version     : v1.00
 Date        : 28/12-2020 
 Copyright   :
 Description : Working with pointers
 ============================================================================*/

#include <stdio.h>

int main (){

    int i, k, *ip;
    ip = &i;
    i = 100;
    k = 400;
    void *kp;


    printf("This program illustrates the use of pointers.\n"
           "A pointer is an object that looks at the address of another object.\n"
           "Using 4 categoeries of increasing difficulty.\n\n");
    
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
    printf("ip = %5p,\n", ip);
    
}

