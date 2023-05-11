"""
You are asked to find the number of students who secured centum in mathematics
in their examination. A total of 6 lakhs students appeared for the examinations
and their results are available with us.
"""
import re

# Condition for sorting
mark = int(input("Enter the mark to get deatils of students who scored above it \n"))
sorted_student_list = []

# opening file
file = open("student_list_1.txt", "r")
file_content = file.read()

# New file to store the oputput
output_file = open("output_student.txt", "w")
# Splitting the details of each student
x = re.split("\n", file_content)
# Splitting mark and details of each student
# Now compares his mark and perform logical calculation
leng = len(x)
for i in range(leng - 1):
    y = re.split(" ", x[i])
    if int(y[1]) > mark:
        sorted_student_list.append(y[0])
        output_file.write(f'{x[i]}\n')
print(sorted_student_list)
# Closes the file
output_file.close()
file.close()
