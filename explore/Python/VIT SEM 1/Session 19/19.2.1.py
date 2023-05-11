# Exercise 2
"""
A marketing company has branch in a set of cities ‘S’.
The company sends three of their sales man to various cities in set ‘S’.
In the middle of the year, help the manager to find out the cities
that are already visited by the sales men and the cities that are yet to be visited.
"""

# s = {"Kochi", "Bengaluru", "Hyderabad", "Chennai", "Delhi", "Mumbai", "Vijayawada"}
# # cities
# s_1 = {"Hyderabad", "Chennai"}  # cities visited by employee 1
# s_2 = {"Bengaluru"}
# s_3 = {"Vijayawada"}
# visited = s_1 | s_2 | s_3
# not_visited = s - visited
# print(visited)
# print(not_visited)


s = {"Kochi", "Bengaluru", "Hyderabad", "Chennai", "Delhi", "Mumbai", "Vijayawada"}
gokul = {
    "s_1": {"Hyderabad", "Chennai"},  # cities visited by employee 1
    "s_2": {"Bengaluru"},
    "s_3": {"Vijayawada"}
}
set_anu = set()
for x, y in gokul.items():
    set_anu.update(y)
set_anu_2 = set()
for x, y in gokul.items():
    set_anu_2.add(y)
print(f'Visited:{set_anu}')
print(f'Visited:{set_anu_2}')