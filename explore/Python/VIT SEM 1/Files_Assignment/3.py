"""
 3. Write a function in Python to count and display the total number of words in a text file.
"""
file = open("story.txt", "r")
a = file.read().split()
print(f'The total number of words in this text file is {len(a)}')

