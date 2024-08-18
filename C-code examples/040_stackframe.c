/*============================================================================
 Name        : stackframe.c
 Version     : v1.00
 Dato        : 17/08-24
 Description : Showcasing the stack frame, through the use of gdb.
 ============================================================================*/
#include <stdio.h>
#include <stdio.h>

int functionB(int x, int y) {
    int sum = x + y;
    char buffer[8] = "example";
    return sum;
}

int main() {
    int a = 10;
    int b = 20;
    int result = functionB(a, b);
    printf("Result: %d\n", result);
    return 0;
}


/***
Commands in order:
$ gcc -o test -O0 -g stackframe.c
$ gdb ./test
(gdb) b functionB
(gdb) r
(gdb) n
(gdb) n
(gdb) print &x
... = ... 0x...db0c
(gdb) print &y
... = ... 0x...db08
(gdb) print &sum
... = ... 0x...db1c
(gdb) print &buffer
... = ... 0x...db14
(gdb) print $fp
... = 0x...db20
(gdb) info frame
(gdb) x/64xb $fp-32
0x...db00: 0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
0x...db08: 0x14    0x00    0x00    0x00    0x0a    0x00    0x00    0x00
0x...db10: 0x00    0x00    0x00    0x00    0x65    0x78    0x61    0x6d
0x...db18: 0x70    0x6c    0x65    0x00    0x1e    0x00    0x00    0x00
0x...db20: 0x40    0xdb    0xff    0xff    0xff    0x7f    0x00    0x00
0x...db28: 0x86    0x51    0x55    0x55    0x55    0x55    0x00    0x00
0x...db30: 0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
0x...db38: 0x14    0x00    0x00    0x00    0x0a    0x00    0x00    0x00


Notes:
* The register RIP (EIP for 32-bit CPU) contain
  the address of the instruction to be executed next
* The register RBP (commonly known as frame pointer aka fp)
  is used to fix the base of a stack frame.
* Arguments to functions are stored right to left.


        Higher Memory Addresses
+-------------+---------------------+ 
| ...         | ...                 | <-- Previous frame (from `main`)
| 0x...db38:  | 0x0000000a (10)     | <- a
| 0x...db30:  | 0x00000014 (20)     | <- b
+=============+=====================+ <-- Frame boundary
| 0x...db28:  | 0x5555555186        | <- Saved RIP (Return Address to `main`)
+-------------+---------------------+                           
| 0x...db20:  | 0x...db40           | <- Saved RBP (Old Base Pointer for `main`)
+-------------+---------------------+
| 0x...db1c:  | 0x0000001e (30)     | <- sum
+-------------+---------------------+
| 0x...db1b:  | 0x65 ('\0')         | <- buffer[7]
| 0x...db1a:  | 0x6c ('e')          | <- buffer[6]
| 0x...db19:  | 0x6c ('l')          | <- buffer[5]
| 0x...db18:  | 0x70 ('p')          | <- buffer[4]
+-------------+---------------------+
| 0x...db17:  | 0x6d ('m')          | <- buffer[3]
| 0x...db16:  | 0x61 ('a')          | <- buffer[2]
| 0x...db15:  | 0x78 ('x')          | <- buffer[1]
| 0x...db14:  | 0x65 ('e')          | <- buffer[0]
| 0x...db13:  | 0x00 ('\0')         | <- Unused/Aligned space
| 0x...db12:  | 0x00 ('\0')         | <- Unused/Aligned space
| 0x...db11:  | 0x00 ('\0')         | <- Unused/Aligned space
| 0x...db10:  | 0x00 ('\0')         | <- Unused/Aligned space
+-------------+---------------------+
| 0x...db0c:  | 0x00000014 (20)     | <- Argument x
+-------------+---------------------+
| 0x...db08:  | 0x0000000a (10)     | <- Argument y
+-------------+---------------------+
       Lower Memory Addresses



 */