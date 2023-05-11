# Exercise 6
"""
Write a program to store the name of the players against each of a 20-20 cricket team.
The program should print the name of the players given the team name.
"""

# Declare empty list
team_1 = []
team_2 = []

# Input names of the members of team1
print("Team 1")
for i in range(0, 11):
    team_1.append(str(input(f'{i + 1}:')))
print()

# Input names of the members of team2
print("Team 2")
for i in range(0, 11):
    team_2.append(str(input(f'{i + 1}:')))

input_var = str(input())
if input_var == "Team 1":
    # Output names of the members of team1
    print("Team 1")
    for i in range(0, 11):
        print(f'{i + 1}-{team_1[i]}')
    print()
elif input_var == "Team 2":
    # Output names of the members of team2
    print("Team 2")
    for i in range(0, 11):
        print(f'{i + 1}-{team_2[i]}')
else:
    print("Wrong Input")

# Another Method

# ISL = {
#     "chennai": None,
#     "Banglore": [],
#     "Mumbai": []
# }
# # for i, j in ISL.items():
# #     for k in range(0,2):
# #         j.append(input())
# # print(ISL)
#
# for i in ISL:
#     for j in range(0, 2):
#         ISL[i] = "new_value"
# print(ISL)

