/*============================================================================
 Name        : Test17.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : v1.00
 Copyright   : 
 Dato        : 13/08-22
 Description : A program to convert texts using Ceasar Ciphers
 ============================================================================*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

//Doubly Linked List
struct Node {
    char *data;
    struct Node* next; // Pointer to next node in DLL
    struct Node* prev; // Pointer to previous node in DLL
};

struct Node* head;
struct Node* tail;

void push();
void pop();
void printAll();
void printSpecific(int shifted);
void readFile(char *filename);

int main(int argc, char *argv[]){
    if(argc-2){ perror("Incorrect usage\n"); exit(2);}
    readFile(argv[1]);
    printAll();


}


void push(){
    if(head != NULL){
        struct Node* temp1 = malloc(sizeof(struct Node));
        temp1->data = NULL;
        temp1->next = NULL; 
        temp1->prev = tail; 
        tail->next = temp1;
        tail = temp1;
    } else { //list is empty
        head = malloc(sizeof(struct Node));     // setting up space in the memory for the 1st node.
        head->data = NULL;                      // This causes an error
        head->prev = NULL;
        head->next = NULL;
        tail = head;
    }
} 

void pop(){
    if(tail!=NULL){
        struct Node* temp1;
        if(tail->prev != NULL){
            temp1 = tail;
            tail = tail->prev;
            if(temp1->data != NULL){
                free(temp1->data);
            }
            free(temp1);
            tail->next = NULL;
        } else { // Only 1 node remains
            if(tail->data != NULL){
                free(tail->data);
            }
            free(tail);
            head = NULL;
            tail = NULL;
        }
    } else { printf("List is empty.\n"); }
}

void printAll(){
    printf("------------------------------------\n"
           "------------------------------------\n"
           "This program will use a ceasar cipher to\n"
           "print all permutations of the file\n"
           "by shifting 1 character at a time.\n");
    printf("====================================\n");
    for(int i = 0; i < 26; i++) {
        printSpecific(i);
    }

}

/**
 * @brief 
 * @param shifted
 * ascii
 * Uppercase letters: 0x41 - 0x5A
 * Lowercase letters: 0x61 - 0x7A
 */
void printSpecific(int shifted){
    struct Node* Derpina = head;
    int length;
    char character = 0;
   printf("=============SHIFTED %2d=============\n", shifted);
    while (Derpina){
        length = strlen(Derpina->data);
        for(int i = 0; i < length ; i++){
            character = Derpina->data[i];
            if (0x41 <= character && character <= 0x5A){ //Uppercase letters
                character = ((character - 0x41) + shifted) % 26 + 0x41;
            }
            else if (0x61 <= character && character <= 0x7A){ //Lowercase letters
                character = ((character - 0x61) + shifted) % 26 + 0x61;
            }
            printf("%c", character);
        }
        Derpina = Derpina->next;
    }	
    printf("\n\n");
    return;
}


void readFile(char *filename){
    int maxSize = 512;
    char tempArray[maxSize];

    FILE *fp;
    fp = fopen (filename, "r");		// Open the file with 'read' option.	''
    if(fp==NULL){ 
        fprintf(stderr, "[!] Error reading from file\n");
        exit(1);
    }
    while(!feof(fp)){
       fgets(tempArray, maxSize, fp);
        push();
        if(strlen(tempArray) > 0){;
            tail->data = strdup(tempArray);
        } else{
            pop();
        }
        memset(tempArray, 0, sizeof(char) * maxSize);
    }
    fclose(fp);
    printf("\n");

}
