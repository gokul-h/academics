# Python project to generate data
# Current Status:
# Generate n number of meaningful rows (CLI)

# Designed and developed by Gokul H

# Modules Required
import csv
import random
import names

# field names
fields = ['reg_no', 'Name', 'Branch', 'Year', 'Gender', 'Attendance', 'CGPA', 'Good/Bad']

# Initialise list which has to be converted to CSV
rows = list()

# User Input:- Number of rows
num = int(input("Enter the number of Rows needed:-"))

# Choices offered to certain fields
gender_list = ['male', 'female']
branch_list = ['CSE', 'IT', 'ECE', 'EEE', 'BAI', 'MBA', 'MCA', 'ME']

# Generating data
for i in range(num):
    gender_temp = random.choice(gender_list)
    temp = [i + 1, names.get_full_name(gender=gender_temp), random.choice(branch_list),
            random.randint(1, 4), gender_temp, random.randint(50, 100), random.randint(4, 10),
            random.randint(0, 1)]
    rows.append(temp)

# name of csv file
filename = "maths_lab_data.csv"

# writing to csv file
with open(filename, 'w', newline='') as csvfile:
    # creating a csv writer object
    csvwriter = csv.writer(csvfile)

    # writing the fields
    csvwriter.writerow(fields)

    # writing the data rows
    csvwriter.writerows(rows)

print("Data Generated successfully")
