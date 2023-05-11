# ASSIGNMENT 3
"""
Watson gives Sherlock an list of N numbers.
Then he asks him to determine if there exists an element
in the list such that the sum of the elements on its left
is equal to the sum of the elements on its right.
If there are no elements to the left/right,
then the sum is considered to be zero.
"""

[1,2,3,2,6]

num_list = []
count = int(input("Enter the number of elements you want to add:"))
for i in range(0, count):
    num_list.append(int(input(f'{i + 1}:')))


index = 0
for i in num_list:
    sum_1 = sum_2 = 0
    for j in num_list[:index]:
        sum_1 += j
    for k in num_list[index+1:]:
        sum_2 += k
    if sum_1 == sum_2:
        Success = True
        break
    print()
    i = i+1
if Success:
    print(f'Sum = {sum_1} (Success!!!)')
else:
    print("Sum = 0")