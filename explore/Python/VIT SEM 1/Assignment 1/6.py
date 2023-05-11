# ASSIGNMENT 6
"""
Given N integers,count the number of pair of integers
whose difference is K
"""

print("How many integers you want to enter?")
count = int(input())
num_list = []
print("please enter the numbers one by one")
for i in range(1, count+1):
    num_list.append(int(input(f'{i}:')))
print(f'Your list is {num_list}')
diff = int(input("Enter the difference"))
num_pair_list = []
for i in num_list:
    for j in num_list:
        if (i - j) == diff:
            num_pair_list.append(f'({i},{j})')
print(f'Total number of pairs where difference between elements is {diff} = {len(num_pair_list)}')
print(f'Pairs are {num_pair_list} ')