#*============================================================================
# Name        : Functions
# Author      : Declined#8151 (Discord ID)
# Version     : 1.00
# Date        : 25/09-21
# Lat updated : 25/09-21
# Copyright   : Your copyright notice
# Description : Creating and defining functions
#============================================================================*/

#def is used for defining functions, indention is required

def function1():
    print("First ever function")

def function2(x, y):
    print("Sum of {0} and {1} is: {2}".format(x, y, (x+y)))
    print("Sum of {0} and {1} is: {2}".format(x, y, function3(x,y)))

def function3(x, y):
    return x+y

#main
function1()
function2(4, 6)



