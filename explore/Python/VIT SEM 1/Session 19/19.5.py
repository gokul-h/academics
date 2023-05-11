# Exercise 5
"""
Write a program to maintain a telephone directory of the employees of an organization.
If the employee has more than one number store all the numbers.
Write a program to print the mobile numbers given full or part of the name of the employee.
Eg: Given name of the employee as ‘John’
the program must print phone numbers of ‘John Paul’ and ‘Michel John’
"""

# Using concept of nested list
contact = [["John", "Paul", 9876543211], ["Michel", "John", 4567899123, 9632587419]]

name = str(input("Enter name to find contact details:"))
name_list = name.split()
# when input is partial name
if len(name_list) == 1:
    # for i in name_list:  # to identify first name and last name separately
        i = name_list[0]
        for j in contact:  # to check for each contact in list
            if i == j[0] or i == j[1]:  # to check if first name or last names matches input
                for k in range(2, len(j)):  # print all phone numbers
                    print(f'{j[0]} {j[1]}:{j[k]}')
elif len(name_list) == 2:
    for j in contact:
        if (name_list[0] == j[0] and name_list[1] == j[1]) or \
             (name_list[1] == j[0] and name_list[0] == j[1]):
            for k in range(2, len(j)):  # print all phone numbers
                print(f'{j[0]} {j[1]}:{j[k]}')
else:
    print("No details found!!!")
    print("or")
    print("Enter name in correct format")
