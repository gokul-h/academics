# Exercise 3
"""
A proctor of our university wants a student to write
a program that calculates the average of marks scored by her wards in CAT1.
She has the details such as name, register number, mark1, mark2 and mark3 of her proctees.
The constraint given by the faculty is that any of the details must not be altered by mistake.
Help the student to develop a Python program
"""

# Using Concept of Nested tuples
details = (("Gokul", "20BCE1211", 99, 99, 99), ("Student_2", "20BCE1222", 85, 58, 96),
           ("Student_3", "20BCE1223", 85, 58, 96), ("Student_4", "20BCE1223", 85, 58, 96))

details[0][0]
# Find Average of CAT 1
name = str(input())
for i in details:
    x = details.index(i)
    if name == details[x][0]:
        cat_avg = (details[x][2] + details[x][3] + details[x][4]) / 3
        print("Average mark for CAT 1 is:" + str(cat_avg))


# class Student:
#     def __init__(self, name, regno, mark1, mark2, mark3):
#         self.name = name
#         self.regno = regno
#         self.mark1 = mark1
#         self.mark2 = mark2
#         self.mark3 = mark3

#     def calc(self):
#         avgcat = (self.mark1 + self.mark2 + self.mark3) / 3
#         return avgcat


# student1 = Student("Gokul", "20BCE1211", 99, 99, 99)
# print(student1.calc())

# set_1 = {5, 1, 2, 3, 4}
# list_1 = list(set_1)
# print(list_1)
