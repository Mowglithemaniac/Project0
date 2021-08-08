#!/bin/bash
file='book.txt'
while read line; do
echo $line
done < $file

## Reads the content of a file named 'book.txt'