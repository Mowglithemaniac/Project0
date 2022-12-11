#*============================================================================
# Name        : Dictionary
# Author      : Declined#8151 (Discord ID)
# Version     : 1.00
# Date        : 26/09-21
# Lat updated : 26/09-21
# Copyright   : Your copyright notice
# Description : Information about dictionaries
#============================================================================*/

# Defining 'key value pairs'
# Note: Keys must be unique
gradeConversion = {
    "F" : "00",
    "E" : "02",
    'D' : "04",
    "C" : "07",
    "B" : "10",
    "A" : "12",
}

print(gradeConversion['C'])
print(gradeConversion.get("C"))
print(gradeConversion.get("C", "Default output"))


# This is a concept of "F" -> "00"

