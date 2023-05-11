# Exercise 2
"""
A marketing company has branch in a set of cities ‘S’.
The company sends three of their sales man to various cities in set ‘S’.
In the middle of the year, help the manager to find out the cities
that are already visited by the sales men and the cities that are yet to be visited.
"""
# Add name of cities as key and status of visit as value
cities = {"Delhi": "N_V", "Mumbai": "N_V", "Kochi": "N_V", 'Banglore': "N_V",
          "Hyderabad": "N_V", "Ahmedabad": "N_V", "Chennai": "N_V", "Bhopal": "N_V"}

# Change status of places visited
salesman_1_visited_cities = {"Kochi"}
salesman_2_visited_cities = {"Mumbai"}
salesman_3_visited_cities = {"Delhi", "Bhopal"}
for i in salesman_1_visited_cities:
    cities[i] = "V"
for i in salesman_2_visited_cities:
    cities[i] = "V"
for i in salesman_3_visited_cities:
    cities[i] = "V"
# list out cities that have status not visited
print("Cities Visited:")
for x, y in cities.items():
    if y == "V":
        print(x, end=" ")
print()
# list out cities that have status not visited
print("Cities NOT_Visited:")
for x, y in cities.items():
    if y == "N_V":
        print(x, end=" ")
