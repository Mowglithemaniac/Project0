#*============================================================================
# Name        : Dictionary
# Author      : Declined#8151 (Discord ID)
# Version     : 1.00
# Date        : 26/09-21
# Lat updated : 26/09-21
# Copyright   : Your copyright notice
# Description : 
#============================================================================*/

import random
import string

def passGen(length):
    availableChars = list(string.ascii_letters + string.digits + "#%!.,;:?@$_-&/")

    random.shuffle(availableChars)
    tempPass = []
    for i in range(10):
        print(str(i+1).format()+".\t", end='')
        for i in range(length):
            
            tempPass.append(random.choice(availableChars))
    
        random.shuffle(tempPass)
        print("".join(tempPass))
        tempPass.clear() # reset the list


# Main
while(True):
    attempt = False
    try: 
        size = int(input("Type in how many characters you would like to include:"))
        attempt = True
    except ValueError:
        print("Problem converting to a value.")
    if not(attempt):
        continue 
    if size == 0:
        print("Terminating program.")
        quit()
    if size < 8 or size > 40:
        print("Between 8-40 characters.")
        continue
    passGen(size)


