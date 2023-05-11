# ASSIGNMENT 5
""" Given a list_new of integer values find the fraction of count
of positive numbers,negative numbers and zeroes to the
total numbers.Print the value of the fraction correct to 3 decimal"""

num_list = []
count = int(input("Enter the number of elements you want to add:"))
for i in range(0, count):
    num_list.append(input(f'{i + 1}:'))
count_positive = count_negative = count_zero = 0
for i in num_list:
    if int(i) > 0:
        count_positive += 1
    if int(i) < 0:
        count_negative += 1
    if int(i) == 0:
        count_zero += 1
print(f'Fraction of Positive numbers is {format((count_positive/count),".3f")}')
print(f'Fraction of Negative numbers is {format((count_negative/count),".3f")}')
print(f'Fraction of number Zero is {format((count_zero/count),".3f")}')
frac = count_positive/count
frac_new = format(frac,".3f")
print(f'Fraction of Positive numbers is {frac_new}')
