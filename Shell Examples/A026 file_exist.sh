#!/bin/bash
filename=$1
if [ -f "$filename" ]; then
echo "File exists"
else
echo "File does not exist"
fi

# '-f' option is used here, to test whether the file exist
# the $1 is the 1st argument from the argument list
# Example
# ./example book.txt