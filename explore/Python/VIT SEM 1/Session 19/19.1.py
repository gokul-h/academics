# Exercise 1
"""
While John got ready for the office a shopping list was given by his son and daughter.
While returning home John decides to buy the items from a shop.
He decides to buy the items common in both the list,
then the items listed only by his son and at last the items listed only by his daughter.
Write a program to help him in achieving the task.
"""

son_list = {"soap", "biscuit", "toilet paper", "cup"}
daughter_list = {"cup", "biscuit", "mobile"}
combined_list = son_list & daughter_list
son_only_set = son_list - combined_list
daughter_only_list = daughter_list - combined_list
print(combined_list)
print(son_only_set)
print(daughter_only_list)
print(list(combined_list)+list(son_only_set)+list(daughter_only_list))

# # Elements can be replaced with items or can be customised for user input
# son_list = [1, 2, 3, 4]
# daughter_list = [3, 4, 5, 6, 7]
# # Finding common elements
# common_list = tuple(set(son_list).intersection(set(daughter_list)))
# final_list = list(common_list)
# # Find items exclusively for son
# temp_son_list = list(set(son_list) ^ set(common_list))
# final_list += temp_son_list
# # Find items exclusively for daughter
# temp_daughter_list = list(set(daughter_list) ^ set(common_list))
# final_list += temp_daughter_list
# # Print final shopping list
# print(final_list)
