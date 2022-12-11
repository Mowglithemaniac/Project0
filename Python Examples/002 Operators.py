#*============================================================================
# Name        : Operators
# Author      : Declined#8151 (Discord ID)
# Version     : 1.00
# Date        : 22/09-21
# Last updated: 22/09-21
# Copyright   : Your copyright notice
# Description : Come basic python concepts about operators 
#============================================================================*/

# This program adds two numbers
print('This program will print the sum of two numbers')
num1 = 9
num2 = 3
# Add two numbers
sum = num1 + num2

# Display the sum
print('The sum of {0} and {1} is {2}\n'.format(num1, num2, sum))

print("Boolean operators: \'True\' and \'False\'\nDo not mistake them for BITWISE operations")
# and, or, not
x = True
y = False
print("========|============================")
print("\t|   x\t|   y\t|   Result")
print("--------+-------+-------+------------")
print(" Value\t| {0}\t| {1}\t|  ".format(x, y))
print(" and\t|\t|\t|  ",x and y)
print(" or\t|\t|\t|  ",x or y)
print(" not\t| {0}\t|  {1}\t|  ".format(not x, not y))

print("\n\nArithmetic operators:\nMath for dummies, using the values you entered previously")
print("========|============================")
print("\t|   a\t|   b\t|   Result")
print("--------+-------+-------+------------")
print(" Value\t|   {0}\t|   {1}\t|  ".format(num1, num2))
print("  +\t|\t|\t|   {0}\t| Addition".format(num1+num2))
print("  -\t|\t|\t|    {0}\t| Subtraction".format(num1-num2))
print("  *\t|\t|\t|   {0}\t| Multiplication".format(num1*num2))
print("  /\t|\t|\t|    {0}\t| Division".format(int(num1/num2)))
print("  %\t|\t|\t|    {0}\t| Modulu".format(num1%num2))
print("  //\t|\t|\t|    {0}\t| Floor division - division that results into whole number adjusted to the left in the number line".format(num1//num2))
print("  **\t|\t|\t|  {0}\t| Exponent - left operand raised to the power of the right".format(num1**num2))


print("\n\nLogical operators:\nReturns either \'True\' or \'False\'")
print("========|============================")
print("\t|   a\t|   b\t|   Result")
print("--------+-------+-------+------------")
print(" Value\t|   {0}\t|   {1}\t|  ".format(num1, num2))
print(" >\t|\t|\t|  ",num1 > num2)
print(" <\t|\t|\t|  ",num1 < num2)
print(" ==\t|\t|\t|  ",num1 == num2)
print(" !=\t|\t|\t|  ",num1 != num2)
print(" >=\t|\t|\t|  ",num1 >= num2)
print(" <=\t|\t|\t|  ",num1 <= num2)


a = 3      # 0011 
b = 10     # 1010
print("\n\nBitwise operators:\nBit manipulation")
print("========|============================")
print("\t|   a\t|   b\t |   Result")
print("--------+-------+-------+------------")
print(" Value\t|  {0:04b}\t|  {1:04b}\t|  ".format(a, b))
print("--------+-------+-------+------------")
print("--------| Operator info +------------")
print("--------+-------+-------+------------")
print("   &\t|\t \t|    {0:04b}\t| AND".format(a & b))
print("   |\t|\t\t|    {0:04b}\t| OR".format(a & b))
print("   ~\t|\t\t|    {0:04b}\t| NOT".format(a & b))
print("   ^\t|\t\t|    {0:04b}\t| XOR".format(a & b))
print("   >>\t|  {0:04b}\t|  {1:04b}\t|   x >> 2\t| Right shifting (2 spaces)".format(a >> 2, b >> 2))
print("   <<\t|  {0:04b}\t|{1:04b}\t|   x << 2\t| Left shifting (2 spaces)".format(a << 2, b << 2))

sum=10
alter=2
print("\n\nAssignment operators:")
print("========|============================")
print("Operator| Before| Alter\t|  Result")
print("--------+-------+-------+------------")
print(" Value\t|  {0}\t|  {1}\t|  ".format(sum, alter))
print("--------+-------+-------+------------")
print("   =\t| x = 2\t\t|    ", alter)
print("   +=\t| x = x + 2\t|   ", sum+alter)
print("   -=\t| x = x - 2\t|    ", sum-alter)
print("   *=\t| x = x * 2\t|   ", sum*alter)
print("   /=\t| x = x / 2\t|    ", int(sum/alter))
print("   %=\t| x = x % 2\t|    ", sum%alter)
print("   //=\t| x = x // 2\t|    ", sum//alter)
print("   **=\t| x = x ** 2\t|  ", sum**alter)
print("   &=\t| x = x & 2\t|    ", sum&alter)
print("   |=\t| x = x | 2\t|   ", sum|alter)
print("   ^=\t| x = x ^ 2\t|    ", sum^alter)
print("   >>=\t| x = x >> 2\t|    ", sum>>alter)
print("   <<=\t| x = x << 2\t|   ", sum<<alter)

