#*============================================================================
# Name        : toHex
# Author      : Declined#8151 (Discord ID)
# Version     : 1.01
# Date        : 18/11-22
# Lat updated : 22/11-22
# Copyright   : Your copyright notice
# Description : Read the content of a file as bytes, and display
#               it in the terminal as hex.
#============================================================================*/

import sys
import os

def readingfromfile(something):
    if False == os.path.isfile(something):
        print("[!] File does not exist")
        exit(1)
    somefile = open(something, 'rb')
    content = somefile.read()
    derp = ""
    counter = 0
    for char in content.hex():
        derp += char
        if counter > 0 and (counter + 1) % 20 == 0:
                derp += '\n'
        counter += 1

    print(derp)
#    transformed= content.encode() # Convert str to bytes
#    print(transformed)


# if __name__ == "__main__":
if len(sys.argv) != 2:
    print("[!] Incorrect usage")
    exit(1)
#    print(f"Arguments count: {len(sys.argv)}")
#    for i, arg in enumerate(sys.argv):
#        print(f"Argument {i:>6}: {arg}")
readingfromfile(sys.argv[1])



