"""
 2. Write a function in python to
 count the number of lines from a text file "story.txt"
 which is not starting with an alphabet "T".
"""
y = open("story.txt", 'r')
z = y.readlines()
Count = 0
for i in z:
    if i[0] != 'T' or i[0] != 't':
        Count += 1
print(Count)
