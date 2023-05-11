""""
Q:Given time in AM/PM format. Convert this into a 24 hour format.

Note: Midnight is 12:00:00AM or 00:00:00 and 12 Noon is 12:00:00.

"""
# Solved using basic logic

import sys

print("Please enter the time to convert into 24 Hour Format")
hour = int(input("Please enter the hour:"))
minute = int(input("Please enter the minute:"))
second = int(input("Please enter the second:"))
am_or_pm = str(input("Enter AM or PM"))
print(am_or_pm.upper())
print(f"Time inputted is {hour}:{minute}:{second} {am_or_pm.upper()}")
if am_or_pm.upper() == 'AM':
    if hour == 12:
        hour = 0
elif am_or_pm.upper() == 'PM':
    hour += 12
else:
    print("Wrong Input")
    sys.exit(0)
print(f'Time in 24 hour format is {hour}:{minute}:{second}')
