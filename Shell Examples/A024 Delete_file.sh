#!/bin/bash
echo "Enter filename to remove"
read fn
rm -i $fn

## The '-i' option is used here to get permission before deleting the file.