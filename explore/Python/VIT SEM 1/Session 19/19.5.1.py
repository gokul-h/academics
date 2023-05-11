# Exercise 5
"""
Write a program to maintain a telephone directory of the employees of an organization.
If the employee has more than one number store all the numbers.
Write a program to print the mobile numbers given full or part of the name of the employee.
Eg: Given name of the employee as ‘John’
the program must print phone numbers of ‘John Paul’ and ‘Michel John’
"""
# Done using Dictionary
# Limitation cant have numtiple numbers
import sys

contact = {
    ("John", "Paul"): [9876543211],
    ("Michel", "John"): [4567899123, 9632587419],
    ("Gokul"): [1258963478]
}

name = str(input("Enter name to find contact details:"))
name_list = name.split()

for i in contact:
    for j in i:
        for k in name_list:
            if j == k:
                print(contact[i])

# contact_keys = list(contact.keys())
# for i in contact_keys:
#     cont_temp_list = i.split()
#     if len(name_list) == 1:
#         for m in cont_temp_list:
#             for j in name_list:
#                 if m == j:
#                     print(contact[i])
#         sys.exit(0)
#     elif len(name_list) == 2:
#         if name in contact:
#             print(contact[name])
#         sys.exit(0)
#     else:
#         print("No details found!!!")
#         print("or")
#         print("Enter name in correct format")
#         sys.exit(0)
str = input().rstrip()