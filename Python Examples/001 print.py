#*============================================================================
# Name        : print
# Author      : Declined#8151 (Discord ID)
# Version     : 1.01
# Date        : 21/09-21
# Lat updated : 24/09-21
# Copyright   : Your copyright notice
# Description : Showcasing different aspects of printing
#============================================================================*/

# Showcasing print operators
import textwrap

'''
This is a multi line comment
'''

sum1 = 3
sum2 = 5
sum3 = 7
derp = "fubar"
#### print specific functions

#Removing newline
'Removing the automatic newline character\n:'.rstrip() # method 1
print("=============================\nShowcasing omission of newline:\n")

print("Testing newline prevention. ", end='')
print(" Is this sentence on a new line?")

# testing ' vs "
print("\n\n=============================\nShowcasing use of '  &\" :\n")

print("derp 'test'")  
print('derp "test"')
print("derp \"test\"")


print("\n\n=============================\nShowcasing insertion of variables:\n\n")
# Inserting variables
variable1="Derpina"
variable2='''abc
\tABC'''
variable3 = 48                  # Integer
print("1.\tDerp loves " + variable1 + " very much")
print("2.\tDerp loves " + variable2 + " very much")
print("3. Derp loves " + str(variable3) + " very much")    #Only works with strings, not int, hence the str conversion

print("4.\tSilly test {0} complete".format(variable1))
print("5.\tSilly test {0} complete".format(variable2))
print("6.\tSilly test {0} complete\n\n".format(variable3))


print("=============================\nShowcasing seperator usage:\n")
# seperator
print('\nhome', 'user', 'documents', sep='/' )



# Formattet strings
# Start with 'F' or 'f', can even be in front of tripple quotation mark
variabl3=f'''Value1: {sum1}, Name: {derp}'''

yes_votes = 42_572_654
no_votes = 43_132_495
percentage = yes_votes / (yes_votes + no_votes)
print('{0:-9} YES votes  {1:2.2%}'.format(yes_votes, percentage))
print(' 42572654 YES votes  49.67%')


