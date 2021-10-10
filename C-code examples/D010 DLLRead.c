/*============================================================================
 Name        : Test17.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : v1.00
 Copyright   : 
 Dato        : 01/06-21
 Description : Combined version of 014 and A007, to read the content of a file
             : into nodes in a Doubly Linked List.
 ============================================================================*/

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>
#include <string.h>

//Doubly Linked List
struct Node {
    char *data;
    int hidden, rank, suit;
    struct Node* next; // Pointer to next node in DLL
    struct Node* prev; // Pointer to previous node in DLL
};

struct Node* head;
struct Node* tail;

void push();
void pop();
void printList();

void main(){
    int maxSize = 512;
    char tempArray[maxSize];

    FILE *fp;
    fp = fopen ("derpy.txt", "r");		// Open the file with 'read' option.	''
    if(fp==NULL){ exit(-1);}
    while(!feof(fp)){
       fgets(tempArray, maxSize, fp);
       // Uncomment this, and change the printf within printList to include a '\n' when printing each node
//       if(tempArray[strlen(tempArray)-1]== '\n'){
//            tempArray[strlen(tempArray)-1] = 0;
//        }
        push();
        if(strlen(tempArray) > 0){
            printf("String length\t: %d\n", (int)strlen(tempArray));
            tail->data = strdup(tempArray);
        } else{
            pop();
//        printf("%s", tempArray);
        }
        memset(tempArray, 0, sizeof(char) * maxSize);
    }
    fclose(fp);
    printList();
    printf("\n");
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
        head = malloc(sizeof(struct Node));	// setting up space in the memory for the 1st node.
        head->data = NULL;        // This causes an error
        head->prev = NULL;
        head->next = NULL;

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

/* Use this function to print out the current contents of memory. */
void printList(){
	printf("------------------------------------"	
		   "\n------------------------------------"
		   "\nThis function will print info from all the nodes.\n");
    printf("Note that newline characters are NOT excluded from within nodes\n");
	struct Node* Derpina = head;
	int derp = 1;
	while (1==1){
		printf("Node data         : %s\n", Derpina->data);
		if(Derpina->next == NULL){ // reached the last node, so stop iterating
			break;	
		} else {
			Derpina = Derpina->next;
		}	
	}	
	return;
}

