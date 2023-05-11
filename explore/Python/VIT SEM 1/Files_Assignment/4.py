"""
4. Write a function in Python to read lines from a text file "notes.txt".
Your function should find and display the occurrence of the word "the".
"""
file = open("notes.txt", "r")
a = file.read().split()
count = 0
for i in a:
    if i == 'the':
        count += 1
print(f'The total number of time the word \'the\' is repeated is {count}')
