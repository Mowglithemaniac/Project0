/*============================================================================
 Name        : Test16.c
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 1.01
 Copyright   : Your copyright notice
 Date        : 01/07-2021
 Description : Struct syntax, 3 different examples
 ============================================================================*/

#include <string.h>
#include <stdio.h>

struct BookA {
   char  title[50];
   char  author[50];
   char  intro[100];
   int   book_id;
}; 

// Alternate syntax
typedef struct {
   char  title[50];
   char  author[50];
   char  intro[100];
   int   book_id;   
 } BookB;

// Alternate syntax
typedef struct BookC{
   char  title[50];
   char  author[50];
   char  intro[100];
   int   book_id;   
 } lzwzexr;

//global variable declaration of type BookC
struct BookC yolo = {
   .title = "Love",
   .author = "Derp",
   .intro = "To Derpina",
   .book_id = 0x0
};

int main( ) {
   //Declare a specific struct, can b


   struct BookA Book1;                                   // Direct declaration Book1 of type BookA
   BookB Book2;                                          // Direct declaration Book2 of type BookB
   struct BookC* Book3 =  &yolo;                         // Indirect reference to yolo (type BookB) via pointer declaration Book3

   /* book 1 specification */
   strcpy( Book1.title, "Java for dummies");
   strcpy( Book1.author, "Derpina"); 
   strcpy( Book1.intro, "C Programming Tutorial");
   Book1.book_id = 6495407;

   /* book 2 specification */
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Troll");
   strcpy( Book2.intro, "For 'services rendered', failure to comply will direct my services  in your general direction");
   Book2.book_id = 0x000000009;


 
   /* print Book1 info */
   printf( "Book 1 title   : %s\n", Book1.title);
   printf( "Book 1 author  : %s\n", Book1.author);
   printf( "Book 1 subject : %s\n", Book1.intro);
   printf( "Book 1 book_id : %d\n\n", Book1.book_id);

   /* print Book2 info */
   printf( "Book 2 title   : %s\n", Book2.title);
   printf( "Book 2 author  : %s\n", Book2.author);
   printf( "Book 2 subject : %s\n", Book2.intro);
   printf( "Book 2 book_id : %d\n\n", Book2.book_id);

   /* print Book3 info */
   printf( "Book 3 title   : %s\n", Book3->title);
   printf( "Book 3 author  : %s\n", Book3->author);
   printf( "Book 3 subject : %s\n", Book3->intro);
   printf( "Book 4 book_id : %d\n\n", Book3->book_id);


   return 0;
}





