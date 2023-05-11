import csv
import random
import names
import datetime

fields = ["Account_Number", 'Name','Age', 'Account_Type', "Gender", "Branch", "Date", "Balance"]

rows = list()

num = int(input("Enter the number of Rows needed:-"))

gender_list = ['Male', 'Female']
Branch = ['Bengaluru', 'Pune', 'Ahmedabad', 'Chennai', 'Surat', 'Coimbatore', 'Vadodara', 'Indore', 'Thane', 'Delhi',
          'Bhopal', 'Raipur', 'Madurai', 'Kochi']
Account_Type = ["Savings", "Current"]

start_date = datetime.date(2000, 1, 1)
end_date = datetime.date(2020, 2, 1)
time_between_dates = end_date - start_date
days_between_dates = time_between_dates.days

for i in range(num):
    random_number_of_days = random.randrange(days_between_dates)
    random_date = start_date + datetime.timedelta(days=random_number_of_days)
    gender_temp = random.choice(gender_list)
    temp = [i + 1000 + 1, names.get_full_name(gender_temp), random.randint(18,50),random.choice(Account_Type),
            gender_temp, random.choice(Branch), random_date, random.randint(0, 200000)]
    rows.append(temp)

filename = "math_lab_data_new.csv"

with open(filename, 'w', newline="") as csvfile:
    csvwriter = csv.writer(csvfile)
    csvwriter.writerow(fields)
    csvwriter.writerows(rows)
print("Data Generate successfully")
