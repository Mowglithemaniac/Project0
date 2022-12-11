#*============================================================================
# Name        : Lists
# Author      : Declined#8151 (Discord ID)
# Version     : 1.00
# Date        : 25/09-21
# Lat updated : 25/09-21
# Copyright   : Your copyright notice
# Description : Topic regarding lists and arrays
#============================================================================*/

friend_name = ["Derp", "Derpina", "Troll", "Fubar", "Spidermann", ""]
friend_rating = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
friend_gender = ["Male", "Female", "Unknown"]
friend_birthday = []

friend_info = ["Name", int, "Gender", int]
test_1 = [friend_name[0]]
test_2 = [friend_name[1]]
test_3 = friend_name[2]

#To access the 'extend', 'append' and more, we need to initialize the tests as list
test_1.extend(friend_rating[2:3])
test_2.append(friend_rating[3])
test_3.append(friend_rating[4:5]) #This syntax will cause the append value to be treated as a list

print("=============================\nPrints 3 test examples")
print(friend_name[1:3]) #Prints from index 1, up to, but not including index 3
print(test_1) #Prints from index 1, up to, but not including index 3
print(test_2)



#friend_



