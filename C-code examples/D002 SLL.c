/*============================================================================
 Name        : A016 SSL.c
 Author      : Declined#8151 (Discord ID)
 Version     : v1.00
 Copyright   : 
 Dato        : 04/08-2021
 Description : Single Linked list example
             : Emulating a queue data structure
 ============================================================================*/

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>

//Single Linked List
struct Node {
    int data;
    struct Node* next; // Pointer to next node in DLL
};

void enqueue(int value);
void dequeue();
void printList();

struct Node* head;
struct Node* tail;

int main(){ 
    /* Start with the empty list */
    head = NULL;
    tail = NULL;

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    dequeue();
    dequeue();
    printList();
    return 0; 
}


void enqueue(int value){
        
    if(head != NULL){
        struct Node* temp1 = malloc(sizeof(struct Node));
        temp1->next = NULL; 
        tail->next = temp1;
        temp1->data = value;
        tail = temp1;
    } else { //list is empty
        head = malloc(sizeof(struct Node));    // setting up space in the memory for the 1st node.
        head->next = NULL;
        head->data = value;
        tail = head;
    }

} 

void dequeue(){

    if(tail != NULL){ // nodes exist
        struct Node* temp1 = head;
        if(tail == head){ // only 1 node in the list
            free(temp1);
            head = NULL;
            tail = NULL;
        } else { // Multiple nodes in the list
            temp1 = temp1->next;
            free(head);
            head = temp1;
        }
    } else { printf("List is empty.\n"); }
}


/* Use this function to print out the current contents of memory. */
void printList(){
	
	printf("------------------------------------"	
		   "\n------------------------------------"
		   "\nThis function will print info from all the nodes.\n");
    if(head == NULL){
        printf("No content to be shown.\n");
        return;
    }
	struct Node* Derpina = head;
	int derp =1;
    do{
		printf("Node data : %d\n", Derpina->data);
		Derpina = Derpina->next;
	} while (Derpina != NULL);	
	return;
}
