# README
Dedicated to contain basic static content in relation to C programming.

## End of File: EOF
EOF is a an integer constant, used to to indicate End of File, by a
number of functions. It is defined as a value which is not impossible
to reach naturally, and is therefore not necessarily the same across all systems.

It can quickly be determined via this small program.
```c
#include <stdio.h>
int main(void){
    printf("Value\t: %d\nBytes\t: %d",
        EOF, sizeof(EOF));
    return 0;
}
```

## Character escape sequences.

| Character | Meaning |
|:---|:---|
| \a        | Alert(bell) character
| \b        | Backspace
| \f        | Formfeed
| \n        | Newline
| \r        | Carriage Return
| \t        | Horizontal tab
| \v        | Vertical tab
| \\        | Backslash
| \?        | Questionmark
| \'        | Single quote
| \"        | Double Quote
| \000      | Octal number (Represents 8 bits)
| \xhh      | Hexadecimal number (Represents 8 bits)

## Bitwise operators

```txt

&   Bitwise AND
|   Bitwise inclusive OR
^   Bitwise exclusive OR
<<  Left shift
>>  Right shift
~   One's complement (Unary)
```

### Bit fields
Using bit specific values from a variable to determine specific scenarios.

```c
// Copy from stat.h
#define	__S_ISUID	04000       /* Set user ID on execution.  */
#define	__S_ISGID	02000       /* Set group ID on execution.  */
#define	__S_ISVTX	01000       /* Save swapped text after use (sticky).  */
#define	__S_IREAD	0400        /* Read by user.  */
#define	__S_IWRITE	0200        /* Write by user.  */
#define	__S_IEXEC	0100        /* Execute by user.  */
#define S_IRGRP     0040        /* Read by group.  */
#define S_IWGRP     0020        /* Write by group.  */
#define S_IXGRP     0010        /* Execute by group.  */
#define S_IROTH     0004        /* Read by other.  */
#define S_IWOTH     0002        /* Write by other.  */
#define S_IXOTH     0001        /* Execute by other.  */

// Common examples
flag |= S_IROTH | S_IXOTH;      /* Set Read and Execute by other */
flag &= ~(S_IROTH | S_IXOTH);   /* Turn off Read and Execute by other */
if ((flag & (S_IROTH | S_IXOTH)) == 0){ /* True if both fbits are off */
    ...
}

```

## Precedence and associativity of Operators

```txt
Operator                            Associativity
-----------------------------------|--------------
() [] -> .                          Left to right
! ~ ++ -- + - () & (type) sizeof    Right to left
* / %                               Left to right
+ -                                 Left to right
<< >>                               Left to right
< <= > >=                           Left to right
== !=                               Left to right
&                                   Left to right
^                                   Left to right
|                                   Left to right
&&                                  Left to right
||                                  Left to right
?:                                  Right to left
= += -= *= /= %= &= ^= |= <<= >>=   Right to left
,                                   Left to right
-----------------------------------|--------------
```

Warning: This is undefined behaviour, as it is up to the compiler
to defining, which of the two is called first.
We assume that the stack related to the push()/pop() function return
an integer from an array.

push(pop() / pop()) /* WRONG */
push(pop() - pop()) /* WRONG */


## goto statements and labels.
"C provides the infinitely-abusable goto statement, and labels to branch to.
Formally the goto is never necessary, and in practice it is almost always easy
to write code without it."

> Source: Page 65 of "The C programming Language" version 2, by Brian Kernighan and
> Dennis M. Ritchie

```c
    for (...)
        for (...) {
            ...
            if (disaster)
                goto error
        }
    ...
    error:
        // clean up the mess
```

## External definition
```txt
The adjective "external" is used in contrast to "internal," which
describes the aruments and variables defined inside functions.
External variables are defined outside of any function, and are
thus potentially available to many functions. Functions themselves
are always external, because C does not allow functions to be
defined inside other functions. By defult, external variables and
functions have the poerty that all references to them by the same
name, even from functions compiled separately, are references to
the same thing. (The standard calls this property external linkage.)
```

> Source: Page 73 of "The C programming Language" version 2, by
> Brian Kernighan and Dennis M. Ritchie


## Usage of define

```c
#define max(A, B) ((A) > (B) ? (A) : (B)))

//Bad usage
max(i++, j++); /* WRONG */
max(i++, j++); /* WRONG */
```

## Conditional inclusion
This is part of the preprocessors responsibility.
Here are a few examples of how to do this in practice.

This relates to #ifdef, #if, #elif, #endif, #ifndef

Example 1:
```c
#if !defined(HDR)
#define HDR
/* contents of hdr.h goes here */

#endif
```

Example 2:
```c
#if SYSTEM == SYSV
    #define HDR "sysv.h"
#elif SYSTEM == BSD
    #define HDR "msdos.h"
#elif SYSTEM == MSDOS
    #define HDR "default.h"
#endif
#include HDR    
```

Example 3:
```c
#ifndef HDR
#define HDR
/* contents of hdr.h goes here */

#endif
```

***

## sizeof

```c
#define NKEY (sizeof keytab / sizeof (struct key))
# Equivalent to
#define NKEY (sizeof keytab / sizeof keytab[0])
```

> A sizeof can not be used in a #if line, because the preprocessor does not parse type names. 

## Input and output
A number of functions related to I/O, and their uses.
It is important to note that file descriptors which are handled by the OS andaccessed through
System Calls such as read() and write(), can be translated directly to integers, whereas the FILE *,
is a struct containing file related information, which is used as an intermediary to access lower
level system resources.

These commands are related to FILE streams.
```c
// Unsorted
int ungetc(int c, FILE *stream);            // <stdio.h> Pushes 'c' back onto stream to be read again.

// Input
int fgetc(FILE *stream);                    // <stdio.h> Reads the next character from stream.
int getc(FILE *stream);                     // <stdio.h> Reads the next character, often as a macro.
int getchar(void);                          // <stdio.h> Reads the next character from stdin.
char *fgets(char s[restrict .size],         // <stdio.h> Reads string from stream, prevents overflow.
    int size, FILE *restrict stream);       
int scanf(const char *restrict format, ...);// <stdio.h> Reads formatted input from stdin.
int fscanf(FILE *restrict stream,           // <stdio.h> Reads formatted input from stream.
    const char *restrict format, ...);      
int sscanf(const char *restrict str,        // <stdio.h> Reads formatted input from string.
    const char *restrict format, ...);      

// Output
int putc(int c, FILE *stream);              // <stdio.h> Writes character to stream, often as a macro.
int putchar(int c);                         // <stdio.h> Writes character to stdout.
int fputc(int c, FILE *stream);             // <stdio.h> Writes character to stream.
int fputs(const char *restrict s,           // <stdio.h> Writes string to stream.
    FILE *restrict stream);     
int puts(const char *s);                    // <stdio.h> Writes string to stdout, adds newline.
int printf(                                 // <stdio.h> Writes formatted output to stdout.
    const char *restrict format,...);       
int fprintf(FILE *restrict stream,          // <stdio.h> Writes formatted output to stream.
    const char *restrict format, ...);      
int sprintf(char *restrict str,             // <stdio.h> Writes formatted output to string.
    const char *restrict format, ...);      
int snprintf(char str[restrict .size],      // <stdio.h> Writes formatted output to string safely.
    size_t size,
    const char *restrict format, ...);                                   
int vprintf(                                // <stdio.h> Writes formatted output to stdout using va_list.
    const char *restrict format, va_list ap);       
int vfprintf(FILE *restrict stream,         // <stdio.h> Writes formatted output to stream using va_list.
    const char *restrict format, va_list ap);       
int vsprintf(char *restrict str,            // <stdio.h> Writes formatted output to string using va_list.
    const char *restrict format, va_list ap);       
int vsnprintf(char str[restrict .size],     // <stdio.h> Writes formatted output to string safely using va_list.
    size_t size, const char *restrict format, va_list ap);       
int vscanf(const char *restrict format,     // <stdio.h> Reads formatted input from stdin using va_list.
    va_list ap);                            
int vfscanf(FILE *restrict stream,          // <stdio.h> Reads formatted input from stream using va_list.
    const char *restrict format, va_list ap);       
// Unsorted
int ungetc(int c, FILE *stream);            // <stdio.h> Pushes the character 'c' back onto the specified
                                             //input stream, useful for "un-reading" a character when parsing.
```

These functions are related to file descriptors.
```c
ssize_t read(int fd, void buf[.count],      // <unistd.h> Reads bytes from file descriptor into buffer.
    size_t count);                          

ssize_t write(int fd,                       // <unistd.h> Writes bytes from buffer to file descriptor.
    const void buf[.count], size_t count);  

int dprintf(int fd,                         // <unistd.h> Writes formatted output to file descriptor.
    const char *restrict format, ...);      
int vdprintf(int fd,                        // <unistd.h> Writes formatted output to file descriptor using va_list.
    const char *restrict format, va_list ap);       
```

Table: Scanf Conversions.
| Character | INPUT DATA; Argument type |
|:---|:---|
| d         | Decimal integer; int *.
| i         | Integer; int *. The integer may be in octal (leading 0) r hexadecimal (leading 0x of 0X).
| o         | Octal integer (with or without leading zero); int *.
| u         | Unsigned decimal integer; unsigned int *.
| x         | Hexadecimal integer (with or without leading 0x or 0X); int *.
| c         | Characters; char *. The next input characters are placed in the indicated array, up to the number given by the width field; the default is 1. No '\0' is added. The normal skip over white space characters is suppressed in this case; to read the next non-white space character use %1s.
| s         | String of non-white space characters (not quoted); char *, pointing to an array of chracters large enough to hold the string and a terminating '\0' that will be added.
| e, f, g   | Floating-point number; float *. The input format for float's is n optoinal sign, a string of numbers possibly containing a decimal point, and an optional exponent field containing and E or e followed by a possible signed integer.
| p         | Pointer value as printed by printf("%p"); void *.
| n         | Writes into the argument the number of characters read so far by this call; int *. No input is read. The converted item count is not incremented.
| [...]     | Matches the longest non-empty string o input characters from the set between brackets; char *. A '\0' is added. []...] includes ] in the set.
| [^...]    | Matches the longest non-empty string of input characters _not_ from the set between brackets; char *. A '\0' is added. [^]...] includes ] in the set.
| %         | Literal %; No assignment is made.

***

## Libraries
A number of relevant libraries, along with highly used functions.
Generally, it is recommended to use the manual pages to review functions, these can be accessed through a shell such as bash, ksh, zsh or similar, example:

```bash
$ man 3 printf
```
Here the '3' is used to specify a library call, and not the shell executable 'printf' command.


### _<ctype.h> Character Class Tests:_
The header <ctype.h> declares functions for testing characters. For each function the argument is an int, whose value must be OEF or representable as an unsigned char, and the return valur is an int. The funtions return non-zero (true) if the argument c stisfies the condition described, and zero if not.

| Function | Description |
|:---|:---|
| isalnum(c)    | isalpha(c) or isdigit(c) is true
| isalpha(c)    | isupper(c) or islower(c) is true
| iscntrl(c)    | Control character
| isdigit(c)    | Decimal digit
| isgraph(c)    | printing character except space
| islower(c)    | Lower-case letter
| isprint(c)    | Printing charcter including space
| ispunct(c)    | Printing character except space or letter or digit
| isspace(c)    | Space, formfeed, newline, carriage return, tab, vertical tab
| isupper(c)    | Upper-case letter
| isxdigit(c)   | Hexadecimal digit

***

* _String functions: <string.h>_
* _Mathematical functions: <math.h>_
* _Utility functions: <stdlib.h>_
* _Diagnostics: <assert.h>_
* _Variable argument list: <stdarg.h>
* _Signals: <signal.h>_
* _Date and time format functions: <time.h>
* _Implementation defined limits: <limits.h> and <float.h>


