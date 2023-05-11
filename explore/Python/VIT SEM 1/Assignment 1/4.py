# ASSIGMENT 4
import sys
"""
Sunny and Johnny together have M dollars they want to spend on ice cream.
The parlor offers N flavors, and they want to choose two
flavors so that they end up spending the whole amount.

You are given the cost of these flavors. The cost of the ith flavor is denoted by ci.
You have to display the indices of the two flavors whose sum is M.
"""

n = int(input("Etra Flavour kadayil ondu?"))
flavour_kada = []
for i in range(0, n):
    flavour_paisa = int(input())
    flavour_kada.append(flavour_paisa)
print(flavour_kada)
kayil_olla_paisa = int(input("Total amount availble:"))

for i in flavour_kada:
    for j in flavour_kada:
        if i + j == kayil_olla_paisa:
            print(i, j)
            sys.exit(0)

# print(f"The index of possible flavour combination are {flav_price.index(i)} and {flav_price.index(j)}")

