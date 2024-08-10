/*============================================================================
 Name        : A042 base64 varations.c
 Author      : Declined#8151 (Discord ID)
 Version     : 1.00
 Date        : 23/6-2024
 Copyright   : This is my file.
 Description : Encryption and decryption of base64
               Additional variants are included and showcased,
               but not converted supported.
 ============================================================================*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

//************** Global struct **************
/**
 * @brief Structure to hold information about different base64 variants.
 * 
 * Linked for easy traversal.
 */
struct base64_variant{
    char name[20];
    char string[65];
    struct base64_variant * next;
    struct base64_variant * prev;
};

// ************** Global variables **************
//! Base64 standard character set
char BASE64[]          = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
//! Base64 URL-safe character set
char BASE64_URL[]      = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";
//! Bcrypt Base64 character set
char BCRYPT_BASE64[]   = "./ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
//! Filename safe Base64 character set
char FILENAME_BASE64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+-";


int ENCODING_LENGTH = 64;
struct base64_variant *head, *selected_node;


// ************** Prototype functions **************
void initialize_list();                              // Initializing data structure
void determine_method(char method[]);       // Determining which base64_method to use
int validate_encoding(char *encoded,        // Validate encoding integrity
        int length);
void encode(char content[], int length);    // Encode content to selected base64_method
void decode(char method[], char content[],  // Decode content from selected base64_method
        int length);


// ************** Functions **************

/**
 * @brief Initializes the linked list of base64 variants.
 *
 * Initialize doubly linked list, with each node
 * containing a flavor of base64.
 */
void initialize_list(){

    //Initialize the list, and keep nodes connected
    head = malloc(sizeof(struct base64_variant));
    head->prev = NULL;
    selected_node = head;

    for(int i = 1; i < 4; i++){ // Create and connect additional nodes
        selected_node->next = malloc(sizeof(struct base64_variant));
        selected_node->next->prev = selected_node;
        selected_node = selected_node->next;
    }

    // Insert data into the 4 different nodes, hardcoded
    strcpy(head->name, "base64");
    strcpy(head->string, BASE64);

    strcpy(head->next->name, "base64_url");
    strcpy(head->next->string, BASE64_URL);

    strcpy(head->next->next->name, "bcrypt_base64");
    strcpy(head->next->next->string, BCRYPT_BASE64);

    strcpy(head->next->next->next->name, "filename_base64");
    strcpy(head->next->next->next->string, FILENAME_BASE64);

    selected_node = NULL;
}

/**
 * @brief Determines the encoding method by comparing provided method name with known variants.
 * Exits if the specified method is not found.
 * 
 * @param method The based64 variant to be used.
 */
void determine_method(char method[]){
    //Find the correct variant to be used
    selected_node = head;
    int variant;
    for(variant = 0; selected_node != NULL && variant < 1; selected_node = selected_node->next){
        for(int i = 0, type_length = strlen(selected_node->name); i <= type_length ; i++){
            if(selected_node->name[i] != method[i]){
                variant = -1;
                break;
            }
            if(i == type_length)
                variant = 1;
        }
    }
    if (variant <= 0){
        fprintf(stderr, "[!] Method \"%s\" not found.\n", method);
        exit(1);
    }
}



/**
 * @brief Validates the format of a base64 variation-encoded string.
 *
 * This is achieved by verifying:
 * - Its length is a multiple of 4.
 * - It contains only valid characters along with up to two '='
 *   padding characters at the end.
 *
 * @param encoded The base64-encoded string to validate.
 * @param length The length of the base64-encoded string.
 * @return Returns 1 if the string is valid; otherwise, 0.
 */
int validate_encoding(char *encoded, int length){
    if (length % 4 != 0) return 0;  // Length must be a multiple of 4

    int pad_count = 0;
    int i = length - 1;

    // Check padding at the end
    while (i >= 0 && encoded[i] == '=') {
        pad_count++;
        if (pad_count > 2) return 0; // No more than two padding characters are allowed
        i--;
    }

    // Ensure all characters before any padding are valid base64 characters
    for (i = 0; i < length - pad_count; i++) {
        int found = 0;
        for(int j = 0; j < ENCODING_LENGTH; j++){
            if (encoded[i] == selected_node->string[j]){
                found = 1;
                break;
            }
        }
        if (found == 0)
            return 0;
    }

    return 1; // Valid base64 string
}

 /**
 * @brief Encodes the given content using the specified method
 * 
 * All variations of base64 encrypt blocks of 3 bytes at a time,
 * which results in block of 4 characters outputtet at a time.
 * This means we can use buffers to handle the logic, such as
 * the use of equal ('=') signs to be used.
 * 
 * @param content The data to be encoded
 * @param length The length of the content
 * 
 * @note The method is automatically applied through "selected_node"
 */
void encode(char content[], int length){
    //
    int i = 0;
    int mod_table[] = {0, 2, 1};
    unsigned char encoded[4], buffer[3];
    while (i < length) {
        buffer[0] = content[i];
        buffer[1] = (i + 1 < length) ? content[i + 1] : 0;
        buffer[2] = (i + 2 < length) ? content[i + 2] : 0;

        encoded[0] = selected_node->string[buffer[0] >> 2];
        encoded[1] = selected_node->string[((buffer[0] & 0x03) << 4) | (buffer[1] >> 4)];
        encoded[2] = (i + 1 < length) ? selected_node->string[((buffer[1] & 0x0F) << 2) | (buffer[2] >> 6)] : '=';
        encoded[3] = (i + 2 < length) ? selected_node->string[buffer[2] & 0x3F] : '=';

        //Print the buffer
        for (int j = 0; j < 4; ++j) {
            putchar(encoded[j]);
        }

        //Increment for the next 3 bytes to be processed
        i += 3;
    }
    putchar('\n');

}


/**
 * @brief Decodes a base64-encoded string using the selected variant.
 * 
 * Handles padding appropriately and converts four
 * base64 characters back to three bytes.
 * 
 * @param method The method to use for decoding.
 * @param content The encoded content to decode.
 * @param length The length of the encoded content.
 */
void decode(char method[], char content[], int length){
    int i = 0, pad_count = 0;
    unsigned char buffer[3];

    if (!validate_encoding(content, length)){
        fprintf(stderr, "[!] Encoding invalid.\n");
        exit(1);
    }

    for(i = 0; i < length; i += 4){
        buffer[0] = 0;
        buffer[1] = 0;
        buffer[2] = 0;

        // Insert 0b1111_0b1100 in buffer[0]
        buffer[0] = (unsigned char)find_index(content[i]) << 2;        // Shift and store byte 0b0011_0b1111 to 0b1111_0b1100
        // Insert 0b0000_0b0011 in buffer[0]
        buffer[0] |= (unsigned char)(find_index(content[i+1]) >> 4);   // Extract byte 0b0011_0b0000 and store in place 0b0000_0b0011

        // Insert 0b1111_0b0000 in buffer[1]
        buffer[1] = (unsigned char)(find_index(content[i+1]) && 0x0f) << 4 ; // Extract byte 0b0000_0b1111 and shift 4 places to the left
        // Insert 0b0000_0b1111 in buffer[1] (if content[i+2] is not an equal sign)
        buffer[1] |= (unsigned char)(content[i+2] == '=') ? 0 : (find_index(content[i+2]) && 0x3a) >> 2 ;

        // Insert 0b1100_0b0000 in buffer[2] (if content[i+2] is not an equal sign)
        buffer[2] = (unsigned char)(content[i+2] == '=') ? 0 : (find_index(content[i+2]) && 0x03) << 6 ;
        // Insert 0b0011_0b1111 in buffer[2] (if content[i+2] is not an equal sign)
        buffer[2] = (unsigned char)(content[i+3] == '=') ? 0 : find_index(content[i+3]) ;


        if (i + 4 == length){
            if (content[i+3] == '='){
                pad_count++;
                if (content[i+2] == '='){
                    pad_count++;
                }
            }
        }

        // Print the decoded bytes based on the padding count
        if (pad_count == 0) {
            putchar(buffer[0]);
            putchar(buffer[1]);
            putchar(buffer[2]);
        } else if (pad_count == 1) {
            putchar(buffer[0]);
            putchar(buffer[1]);
        } else if (pad_count == 2) {
            putchar(buffer[0]);
        }
    } // end for-loop
        
}


/**
 * @brief Finds the index of a given base64 character in the selected encoding string.
 *
 * Note: Relies on a valid encoded string, hence why validation
 * be handled before calling this function.
 * 
 * @param c The character to find.
 * @return Returns the index of the character if found; -1 if not found or if it is a padding character.
 */
int find_index(unsigned char c) {
    if (c == '=') {
        return -1;  // Immediately return -1 for padding characters
    }
    for (int i = 0; selected_node->string[i] != '\0'; i++) {
        if (selected_node->string[i] == c) {
            return i;
        }
    }
    return -1;  // Return -1 if the character is not found, indicating an error
}




 /**
 * @about: 
 *      Parse arguments supplied via the commandline.
 * @param '-d'|'--decode'
 */
int main(int argc, char* argv[]){
    //supported arguments
    head = NULL;
    selected_node = NULL;
    initialize_list();

    char *supported = ":divb:";
    int opt = 0;
    int result = 0;

//    print("[?] Base64 variants");
//    while((opt = getopt(argc, argv, supported)) != -1){ 
//        switch(opt){
//
//        }
//
//    }

// 
    char derp[] = "some arbitrary content";
    encode(derp, strlen(derp));


    return 0;
}

