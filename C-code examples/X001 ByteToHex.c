/*============================================================================
 Name        : Test17.c
 Author      : Declined#8151 (Discord ID)
 Version     : v1.00
 Copyright   : 
 Dato        : 22/12-20
 Description : Read file as byte and convert to hex. (3 examples)
 ============================================================================*/

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>
#include <string.h>

//Doubly Linked List
struct Node {
    char data[16];
    struct Node* next; // Pointer to next node in DLL
    struct Node* prev; // Pointer to previous node in DLL
};

struct Node* head;
struct Node* tail;
int offset;

void menu(char filename[], int method);

//Method reading from files
void simplified(char filename[]);
void readfromfile1(char filename[]);
void readfromfile2(char filename[]);


//  
void push();
int pop();
void reset();
void printList();

int main(int argc, char *argv[]){
    if(argc != 2){
        perror("No filename suppplied");
        return 1;
    }

    menu(argv[1], 2);
 
    return 0; 
}

void menu(char filename[], int method){

    switch(method){
        case 1:
            simplified(filename);
            break;        
        case 2:
            tail = NULL;
            head = NULL;
            readfromfile1(filename);
            printList();
            reset();
            break;
        case 3:
            tail = NULL;
            head = NULL;
            readfromfile2(filename);
            printList();
            reset();
            break;
        default:
            fprintf(stderr, "[!] Incorrect usage, terminating program");
            break;        
    }

}

void simplified(char filename[]){
    
    FILE *fp;
    char *buffer;
    int filelength;

    fp = fopen(filename, "rb");        // Open the file in binary mode
    fseek(fp, 0, SEEK_END);            // Jump to the end of the file
    filelength = ftell(fp);            // Get the current byte offset in the file
    rewind(fp);                        // Jump back to the beginning of the file
//    printf("Filelength\t: %d\n", filelength);
    buffer = (char *)malloc((1+ filelength) * sizeof(char)); // Enough memory for the file
    fread(buffer, filelength, 1, fp);  // Read in the entire file
//    printf("File content\t: %s\n", buffer);
    fclose(fp); // Close the file

    for(int i = 0; i < filelength ; i++)
        printf("%X", buffer[i]);
    free(buffer);

}

void readfromfile1(char filename[]){
    offset = 0;
    FILE *fp;
    unsigned char buffer;
    int counter = 0;
    fp = fopen(filename, "rb");         // Open the file in binary mode
    while(!feof(fp)){                   // While not end of file
        push();
        memset(tail->data, 0, sizeof(unsigned char) * 16);
        for(int i = 0; i < 16; i++){
//            read(fp, &buffer, 1);
		    fread(&buffer, sizeof(unsigned char), 1, fp);
                if(feof(fp)) break;     //If end of file, then break
            tail->data[i] = buffer;
            offset = i + 1;;
        }
    }
    fclose(fp);
}

void readfromfile2(char filename[]){
/*****************Attempt 2*******************/
    offset = 0;
    FILE *fp;
    unsigned char buffer;
    int counter = 0;
	size_t check;
    fp = fopen(filename, "rb");        // Open the file in binary mode
    push();
	while(1){
		check = fread(&buffer, sizeof(unsigned char), 1, fp);
//Method 1, to terminate the loop
		if(feof(fp)){
 //           fprintf(stderr, "[!] feof reached\t: break node.\n");
			break;
		}
//Method 2, to terminate the loop (both work)
/*        if(check < 1){
			fprintf(stderr, "[!] Check < 1\t: break node\n");
			break;
		}
*/      
        counter = offset%16;
//        fprintf(stderr, "counter %2d\t: offset %2d\n", counter, offset);
		tail->data[counter] = buffer;
        offset++;
		if(counter == 15){
			push();
        }
    }
    if(!counter){ // counter != 0
        pop();
        offset = 16;
    } else
        offset = counter + 1;
    fclose(fp);
}

void push(){
    if(head != NULL){
        struct Node* temp1 = malloc(sizeof(struct Node));
        temp1->next = NULL; 
        temp1->prev = tail; 
        tail->next = temp1;
        tail = temp1;
    } else { //list is empty
        head = malloc(sizeof(struct Node));	// setting up space in the memory for the 1st node.
        head->prev = NULL;
        head->next = NULL;
        tail = head;
//        printf("Node specific addr: %p\n", head);
    }

}

//return 0 upon sucess, return 1 if list is already empty
int pop(){
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
        return 0;
    }
    return 1;
}


void reset(){
    while(!pop());
    head = NULL;
    tail = NULL;
}


/**
 * @brief Printing the content as hex
 */
void printList(){
    if(head == NULL){
        perror("[!] Empty list");
        exit(1);
    }

    struct Node* Derpina = head;

    while (Derpina->next != NULL){
        for(int i=0; i < 16; i++){
            printf("%X", Derpina->data[i]);
        }
        Derpina = Derpina->next;
    }

    for(int i = 0; i < offset; i++){
        printf("%x", Derpina->data[i]);
    }

    return;
}


