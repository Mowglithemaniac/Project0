#*============================================================================
# Name        : detectEnglish
# Author      : Declined#8151 (Discord ID)
# Version     : 1.00
# Date        : 10/12-22
# Last updated: 11/12-22
# Copyright   : Your copyright notice
# Description : Creating an bruteforce iterative function containing all
#               possible permutations of a string from 1 character up to X
#               characters i.e. 'a' -> 'zzz'
#============================================================================*/

import sys

def iteration(current, characterset):
    toremove = 0
    position = len(current) - 1
    check = True
    maxcharacters = len(characterset) -1
    while check:
        characterindex = characterset.index(current[position])
        if characterindex == maxcharacters:
            toremove += 1
            #increment char to 'a'
            current[position] = characterset[0]
            position -= 1
            if position < 0:
                #insert 'a' at the front of the list
                toremove = len(current)
                current.insert(0, 'a')
                check = False
        else:
            toremove += 1
            current[position] = characterset[characterindex+1]
            check = False
    
    return current, toremove


def printresult(content, toremove):
    sys.stdout.write('\r' + ''.join(content))

def testclass():
    pass    
    
def main():
    availablechars = "abcdefghijklmnopqrstuvwxyz"
    currentprint = ['a']
    maxlength = 8
    toremove = 0
    while len(currentprint) < maxlength+1:
        printresult(currentprint, toremove)
        currentprint, toremove = iteration(currentprint, availablechars)
    print("")

if __name__ == "__main__":
#    testclass()
    main()


