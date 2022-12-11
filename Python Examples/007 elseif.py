#*============================================================================
# Name        : elseif
# Author      : Declined#8151 (Discord ID)
# Version     : 1.00
# Date        : 25/09-21
# Lat updated : 25/09-21
# Copyright   : Your copyright notice
# Description : Example of if-statements
#============================================================================*/


#Variables
a = 34
b = 45
c = 75.4
is_larger = False
is_smaller = True
is_priority = True

is_heavy = True
is_box = True

## Comparison operators
if a < b:
    print(str(a)+"is smaller than "+str(b))
    is_larger = False
else:
    print(str(b)+"is smaller than "+str(a))

if c < b or is_priority:
    print("Either the first value is smaller, or it is a priority")
else:
    print("First value is neither a priority or smaller than the second value")

## Boolean operators
if is_heavy or is_box:
    print("Object is either heavy or a box")
if is_heavy and is_box:
    print("Object is both heavy and a box")
elif is_heavy and not(is_box):
    print("Object is heavy and not a box")
elif not(is_heavy) and is_box:
    print("Object is not heavy and is a box")
else:
    print("Object is not heavy, and is not a box")
