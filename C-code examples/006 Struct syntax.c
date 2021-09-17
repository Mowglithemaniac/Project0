/*============================================================================
 Name        : Struct syntax.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 1.04
 Copyright   : Your copyright notice
 Date        : 29/07-2021
 Last updated: 17/07-2021
 Description : Struct syntax, different examples
 ============================================================================*/

#include <string.h>
#include <stdio.h>

/*********** Declaration of struct types ***********/

// Declare a struct type {BookA}
struct BookA {
   char  title[50];
   char  author[50];
   char  intro[100];
   int   book_id;
}; 

// Declare a struct type, version 2. Notice the two types created {BookB, BookBB}
typedef struct BookB{
   char  title[50];
   char  author[50];
   char  intro[100];
   int   book_id;   
 } BookBB;

// Declare a struct type, Version 3. {BookC}
typedef struct {
   char  title[50];
   char  author[50];
   char  intro[100];
   int   book_id;   
 } BookC;


int main( ) {
   //very atypical format, we've created a struct type BookD, and also initialized a pointer to the struct called 'Book6'
   struct BookD {
      char  title[50];
      char  author[50];
      char  intro[100];
      int   book_id;
   }* Book6;

   /*********** Declaration of variables  ***********/
// Direct declaration of a global variable of type BookB
   struct BookA Book1 = {                                // This is a very atypical method to declare variables, usually used globally for specific structs.
      .title = "Love",
      .author = "Derp",
      .intro = "To Derpina",
      .book_id = 0x0
   };

   //Create instances of books, as needed.
   struct BookA Book2;                                   // Direct declaration of type BookA, called Book1 
   struct BookA* Book3 =  &Book1;                        // Indirect reference to Book1 (type BookA) via pointer declaration of type BookB
   struct BookB Book4;                                   // Direct declaration of Book4 of type BookB 
   BookBB Book5;                                         // Direct declaration Book5 of type BookBB (same as BookB, just no need for the struct part)
   Book6;                                                // Already declared                                             
   struct BookD Book7;

   // Book 1 specification
   strcpy( Book1.title, "Java for dummies");
   strcpy( Book1.author, "Derpina"); 
   strcpy( Book1.intro, "C Programming Tutorial");
   Book1.book_id = 6495407;
   
   /* Book 2 specification */
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Troll");
   strcpy( Book2.intro, "For 'services rendered', failure to comply will direct my services  in your general direction");
   Book2.book_id = 0x000000009;

   /* Book 4 specification */
   strcpy( Book3->title, "Shell scripting");
   strcpy( Book3->author, "Theckr");
   strcpy( Book3->intro, "For 'services rendered', failure to comply will direct my services  in your general direction");
   Book3->book_id = 0x000000009;

 
   /**  Accessing the variables, notice the dot for direct, and -> for indirect  **/
   /* print Book1 info */
   printf( "Book 1 title   : %s\n", Book1.title);
   printf( "Book 1 author  : %s\n", Book1.author);
   printf( "Book 1 subject : %s\n", Book1.intro);
   printf( "Book 1 book_id : %d\n\n", Book1.book_id);

   /* print Book3 info */
   printf( "Book 2 title   : %s\n", Book2.title);
   printf( "Book 2 author  : %s\n", Book2.author);
   printf( "Book 2 subject : %s\n", Book2.intro);
   printf( "Book 2 book_id : %d\n\n", Book2.book_id);

   /* print Book3 info (which points to Book1)*/
   printf( "Book 3 title   : %s\n", Book3->title);
   printf( "Book 3 author  : %s\n", Book3->author);
   printf( "Book 3 subject : %s\n", Book3->intro);
   printf( "Book 4 book_id : %d\n\n", Book3->book_id);

   return 0;
}

