#*============================================================================
# Name        : Tuple
# Author      : Declined#8151 (Discord ID)
# Version     : 1.00
# Date        : 25/09-21
# Lat updated : 25/09-21
# Copyright   : Your copyright notice
# Description : Tuple, an immutable list
#============================================================================*/


list_1 = (3, 5, 45, 24, 34, 345, 40) # This is a tuple
list_2 = [3, 5, 45, 24, 34, 345, 40] # This is a list

#cannot sort list_1, can sort list_2
try:
    list_1.sort()
except:
    print("Unable to sort 1st list")
list_2.sort()

print(list_1)
print(list_2)

list_3 = [(12, 14), (76, 4), (8, 9), (52, 35, 7), 34, 43]
print(list_3)