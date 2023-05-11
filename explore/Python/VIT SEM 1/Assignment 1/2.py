# ASSIGMENT 2
"""
In a supermarket there are two sections S1 and S2.
The sales details of item1 to itemn of section1 and
item1 to itemp of section2 are maintained in a sorted order.
Write a program to merge the elements of the two sorted lists
to form the consolidated list.
"""

list_1 = ["lays","kurkure","dark_fantasy","bourbon"]
list_2 = ["lux","dove","santoor","yardley"]
list_3 = []
list_3 = list_1 + list_2
list_3.sort()
print(list_3)
