##
from Testclass1 import Character

list = []
list.append( Character(1, "Adam Adamsen", "Troll", 8) )
list.append( Character(2, "Ishtar", "Bard", 4) )
list.append( Character(3, "Guverno", "Scholar", 6) )

for obj in list:
    print(obj.Name)


