#*============================================================================
# Name        : toHex
# Author      : Declined#8151 (Discord ID)
# Version     : 1.01
# Date        : 18/11-22
# Lat updated : 22/11-22
# Copyright   : Your copyright notice
# Description : columnar transposition cipher
#               The key is a string of characters
#============================================================================*/

import sys
import os

def safety1(argc):
    if len(argc) != 3:
        print("[!] Incorrect usage")
        exit(1)
    if False == os.path.isfile(argc[1]) and False == os.path.isfile(argc[2]):
        print("[!] File does not exist")
        exit(1)
    if argc[1] == '-d' or argc[1] == '-e':
        return argc[1]
    elif argc[2] == '-d' or argc[2] == '-e':
        return argc[2]
    exit(1)


def acquiringkey():
    '''
    The key is determined by a word.
    The letters are organized alphabetically
    Then a count is issues to replace the letters
    for duplicate letters (i.e. 2 or more 'E* characters)
    the replacing value is duplicated as well
    ie. herptiderptiderp 
    --> ddeeehiippprrrtt,
    --> length: 16
    --> [6, 12, 1, 7, 13, 0, 5, 11, 3, 9, 15, 2, 8, 14, 4, 10]
    '''
    
    modifiedkey = ''
    origkey = input("Enter a key: ")
    '''
    Convert the keyword temporarily to clean up special
    characters
    '''
    for letter in range(len(origkey)):
        if origkey.lower()[letter].islower():
            modifiedkey += origkey[letter].lower()
    if len(modifiedkey) == 0:
        print("[!] Key not accepted")
        sys.exit(1)
    return organizedkey(modifiedkey)

def organizedkey(modifiedkey):
    '''
    Create a 
    '''
    tmpchar = ''
    uniqkey = set(modifiedkey)
    uniqlist = sorted(uniqkey)
    keyorder = ['']
    for iteration in range(len(uniqlist)):
        tmpchar = uniqlist[iteration][0]
        for letter in range(len(modifiedkey)):
            if tmpchar == modifiedkey[letter]:
                 keyorder.append(letter)
    keyorder.pop(0)
    return keyorder

def readingfromfile(something):
    somefile = open(something, 'r')
    content = somefile.read()
    somefile.close()
    return content


def encryption(content, order, length):
    '''
    encoding 'I was never here' with key 'derp'
    Matrix:
    | I |   | w | a |
    | s |   | n | e |
    | v | e | r |   |
    | h | e | r | e |
    ->
    depr --> 1,2,4,3
    Matrix:
    | I |   | a | w |
    | s |   | e | n |
    | v | e |   | r |
    | h | e | e | r |

    Encrypted content:
    'Isvh  ee ae ewnrr'
    '''
    regularmodule = ['']*length
    encryptedmodule = ''
    counter = 0
    for letter in content:
        regularmodule[counter%length] += letter
        counter += 1
    while counter%length != 0:
        regularmodule[counter%length] += '-'
        counter += 1
    for count in range(length):
        encryptedmodule += regularmodule[order[count]]
    print(encryptedmodule)

def decryption(content, order, length):
    '''
    Encoded: 'Isvh  ee ae ewnrr' with key 'derp'
    Matrix:
    | I |   | a | w |
    | s |   | e | n |
    | v | e |   | r |
    | h | e | e | r |
    ->
    depr --> 1,2,4,3
    Matrix:
    | I |   | w | a |
    | s |   | n | e |
    | v | e | r |   |
    | h | e | r | e |

    Encrypted content:
    'I was never here'
    '''
    regularmodule = ['']*length
    decryptedmodule = ''
    sectionsize = round(len(content)/length)
    for section in range(length):
#        print(((sectionsize) * (section+1)))
        regularmodule[order[section]] += content[sectionsize*section:((sectionsize) * (section+1))]
    print(regularmodule)
    for letterNumber in range(len(regularmodule[0])):
        for section in range(length):
            decryptedmodule += regularmodule[section][letterNumber]
    # stripping the last character
    while decryptedmodule[-1] == '-':
        tmp = decryptedmodule[:-1]
        decryptedmodule = tmp
    print(decryptedmodule)
    exit(0)

def fulldecrypt(filename):
    order = acquiringkey()
    content = readingfromfile(filename)
    decryption(content, order, len(order))

def fullencrypt(filename):
    order = acquiringkey()
    content = readingfromfile(filename)
    encryption(content, order, len(order))

    
if __name__ == "__main__":
#    print(f"Arguments count: {len(sys.argv)}")
#    for i, arg in enumerate(sys.argv):
#        print(f"Argument {i:>6}: {arg}")
    choice = safety1(sys.argv)
    if(choice == '-d'):
        fulldecrypt(sys.argv[2])
    else:
        fullencrypt(sys.argv[2])


