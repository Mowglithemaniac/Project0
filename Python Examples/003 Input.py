#*============================================================================
# Name        : Input
# Author      : Declined#8151 (Discord ID)
# Version     : 1.00
# Date        : 25/09-21
# Lat updated : 25/09-21
# Copyright   : Your copyright notice
# Description : Showcasing user input
#============================================================================*/

#print('The sum is %.1f' %(float(input('Enter first number: ')) + float(input('Enter second number: '))))

#inputs are treated as strings, so to use them as numbers, we need to use a typecast
print("Enter 2 values\n")
value_1 = input("Enter first value:")
value_2 = input("Enter second value: ")
value_3 = float(value_1)+float(value_2)

if float(value_3 % 1) == 0:     # Checking if the value is a whole number
    value_3 = int(value_3)

print("The sum is ", value_3)

