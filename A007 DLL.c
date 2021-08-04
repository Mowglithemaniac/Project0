/*============================================================================
 Name        : Test17.c
 Author      : Declined#8151 (Discord ID)
 Version     : v1.00
 Copyright   : 
 Dato        : 22/12-20
 Description : Doubly Linked list example
             : featuring push, pop operations.
 ============================================================================*/


#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>


//Doubly Linked List
struct Node {
    int data;
    struct Node* next; // Pointer to next node in DLL
    struct Node* prev; // Pointer to previous node in DLL
};

struct Node* head;
struct Node* tail;

void push(int value);
void pop();
void printList();

int main(){ 
    /* Start with the empty list */
    head = NULL;
    tail = NULL;
//    printList(); 
    push(7); 
    push(1); 
    push(4); 

    printList(); 
 
    return 0; 
}


void push(int value){
	    
    if(head != NULL){
        struct Node* temp1 = malloc(sizeof(struct Node));
        temp1->next = NULL; 
        temp1->prev = tail; 
        temp1->data = value;
        tail->next = temp1;
        tail = temp1;
    } else { //list is empty
        head = malloc(sizeof(struct Node));	// setting up space in the memory for the 1st node.
        head->prev = NULL;
        head->next = NULL;
        head->data = value;
        tail = head;
        printf("Node specific addr: %p\n", head);
    }

} 

void pop(){
    if(tail!=NULL){
        struct Node* temp1;
        if(tail->prev != NULL){
            temp1 = tail;
            tail = tail->prev;
            free(temp1);
            tail->next = NULL;
        } else { // last node in the list
            temp1 = tail;
            free(temp1);
            head = NULL;
            tail = NULL;
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
	while (1==1){
		printf("Node data : %d\n", Derpina->data);
		if(Derpina->next == NULL){ // reached the last node, so stop iterating
			break;	
		} else {
			Derpina = Derpina->next;
		}	
	}	
	return;
}


