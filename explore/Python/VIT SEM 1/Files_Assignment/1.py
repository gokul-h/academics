"""
1. Write a function in python to read the content
from a text file "poem.txt"
line by line and display the same on screen.
"""
x = open("poem.txt", 'r')
y = x.readlines()
for i in y:
    print(i, end="")
