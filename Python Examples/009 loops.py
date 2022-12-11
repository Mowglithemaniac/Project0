#*============================================================================
# Name        : Dictionary
# Author      : Declined#8151 (Discord ID)
# Version     : 1.00
# Date        : 26/09-21
# Lat updated : 26/09-21
# Copyright   : Your copyright notice
# Description : Information about dictionaries
#============================================================================*/

x = 0
# counting from 00-99
while x < 10:
    for i in range (10):
        print(str(x) + str(i), end ='')
        if i != 9:
            print(", ", end='') # A bit of formatting magic
        else:
            print("") # prints 2 newline characters
    x += 1


print("\n\nOnce again, this time with a list\n\n")
# Once more, but this time with another method in the for-loop
z = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

for j in z:
    for i in z:
        print(str(j) + str(i), end ='')
        if i != 9:
            print(", ", end='') # A bit of formatting magic
        else:
            print("") # prints 2 newline characters

for j in z:
    for i in z:
        pass ##pass can be used to fill in an empty loop
print("\nPrints one letter at a time, rather than as a string")

derp = "herpti derpti derp"
# 'letter' is simply a variable name, 'x' will suffice
for letter in derp:
    print(letter, end = '')
print("")
for x in derp:
    print(x, end = '')
print("")




