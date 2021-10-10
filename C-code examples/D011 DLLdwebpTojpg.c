/*============================================================================
 Name        : Test17.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : v1.00
 Copyright   : 
 Dato        : 01/06-21
 Description : This program will convert all webp files in a folder to jpg
             : as well as removing the old webp file.
             : Requires a UNIX system to run (Linux)
             : Since the only method I know of to convert a file from webp to 
             : jpg, is via a Linux command 'dwebp' I am going to cheat a lot.
 ============================================================================*/

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>
#include <string.h>
#include <sys/types.h>

//Doubly Linked List
struct Node {
    char *data;
    int hidden, rank, suit;
    struct Node* next; // Pointer to next node in DLL
    struct Node* prev; // Pointer to previous node in DLL
};

struct Node* head;                      // First node in the list
struct Node* tail;                      // Last node in the list
struct Node *fileHead, *fileTail;


/************** All prototypes **************/
//Node operations
void push();
void pop();
void dequeue();
void specialDequeue();
void printList();

void skeleton();
void readFromFile(char filename[]);
int checkAnimation(char filename[]);
void convertWebpToJPG(char filename[]);

void main(){
    skeleton();
}

//Node operations
void push(){
    if(head != NULL){
        struct Node* temp1 = malloc(sizeof(struct Node));
        temp1->next = NULL; 
        temp1->prev = tail; 
        temp1->data = NULL;
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
    } else { printf("Main list is empty.\n"); }
}

void dequeue(){
        if(tail!=NULL){
        struct Node* temp1;
        if(head->next != NULL){
            temp1 = head;
            head = head->next;
            if(head->data != NULL){
                free(head->data);
            }
            free(temp1);
            head->prev = NULL;
        } else { // Only 1 node remains
            if(head->data != NULL){
                free(tail->data);
            }
            free(tail);
            head = NULL;
            tail = NULL;
        }
    } else { printf("Alternate list is empty.\n"); }
}

void specialDequeue(){
        if(fileTail!=NULL){
        struct Node* temp1;
        if(fileHead->next != NULL){
            temp1 = fileHead;
            fileHead = fileHead->next;
            if(temp1->data != NULL){
                free(temp1->data);
            }
            free(temp1);
            fileHead->prev = NULL;
        } else { // Only 1 node remains
            if(fileHead->data != NULL){
                free(fileTail->data);
            }
            free(fileTail);
            fileHead = NULL;
            fileTail = NULL;
        }
    } else { printf("List is empty.\n"); }
}

/* Use this function to print out the current contents of memory. */
void printList(){
	printf("------------------------------------"	
		   "\n------------------------------------"
		   "\nThis function will print info from all the nodes.\n");
    if(head == NULL){
        printf("List is empty, no content to be posted\n");
        return;
    }
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

void skeleton(){
    system("ls *.webp > derpy.txt");
    readFromFile("derpy.txt");
    fileHead = head;
    fileTail = tail;
    head = NULL;
    tail = NULL;
    while(fileHead != NULL){
        if(checkAnimation(fileHead->data)){
            //Not implemented
        } else {
            convertWebpToJPG(fileHead->data);
        }
        specialDequeue();
    }

}

void readFromFile(char filename[]){
    int maxSize = 512;
    char tempArray[maxSize];

    FILE *fp;
    fp = fopen (filename, "r");		// Open the file with 'read' option.	''
    if(fp==NULL){ exit(-1);}
    while(!feof(fp)){
       fgets(tempArray, maxSize, fp);
       if(tempArray[strlen(tempArray)-1]== '\n'){
            tempArray[strlen(tempArray)-1] = 0;
        }
        push();
        if(strlen(tempArray) > 0){
//            print("String length\t: %d\n", strlen(tempArray));
            tail->data = strdup(tempArray);
        } else{
//            printf("Empty line, deleted a node\n");
            pop();
//        printf("%s", tempArray);
        }
        memset(tempArray, 0, sizeof(char) * maxSize);       // Resetting the string for next round
    }
    fclose(fp);
//    printList();
    printf("\n");
}

int checkAnimation(char filename[]){
//    grep -c "ANMF" FILENAME.webp > derpy.txt
    printf("Checking animation for file\t: %s\n", filename);
    char command[100];
    strcat(command, "grep -c \"ANMF\" ");
    strcat(command, filename);
    strcat(command, " > derpy.txt\n");
//    printf("Executing command\t: %s\n", command);
    system(command);
    readFromFile("derpy.txt");
    int value = atoi(head->data);
    system("rm derpy.txt\n");
    dequeue();
    if(value){
        printf("Result\t\t\t\t\t: Contains animations\n");
    }
    printf("Result \t: Will be converted\n");
    return value;
}

void convertWebpToJPG(char filename[]){
    char command[100];
    int length = 0, result = 0;
    length = strlen(filename);
    for(int i = 0; i < length; i++){
        if(filename[i] == '\''){
            result++;
        }
    }
    if(result == 2){//assume no files found
        return;
    }
    strcat(command, "dwebp -o ");
    strcat(command, filename);
    length = strlen(command);
    command[length - 4] = 'j';
    command[length - 3] = 'p';
    command[length - 2] = 'g';
    command[length - 1] = ' ';
    strcat(command, filename);
    printf("Executing command \t: %s\n", command);
    system(command);                                //Execute command "dwebp -o FILENAME.jpg FILENAME.webp"
    memset(command, 0, sizeof(char) * 100);
/*    strcat(command, "rm ");
    strcat(command, filename);
    strcat(command, "\n");
    system(command);                                //Execute command "rm FILENAME.webp"
*///    memset(command, 0, sizeof(command));
}   


/*****************************************
 * 
 * Linux commands:
 * grep -c "ANMF" FILENAME.webp > derpy.txt         : Prints '0' in file 'derpy.txt' if not animated
 * ls *.webp > derpy.txt                            : List all files in directory of file format .webp and place the content into file 'derpy.txt'
 * rm derpy.txt                                     : remove derpy.txt
 * dwebp -o FILENAME.jpg FILENAME.webp              : Creates a duplicate file with the same filename, but using the jpg file format
 */