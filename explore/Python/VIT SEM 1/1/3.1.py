# 1. Given a number,count the total number of digits in a number
number = str(input())
length = len(number)
print(length)

# Mathematical Approach
num = int(input())
count = 0
while num != 0:
    num //= 10  # // implies integer division
    count += 1
print(f'Total number of digits are {count}')
