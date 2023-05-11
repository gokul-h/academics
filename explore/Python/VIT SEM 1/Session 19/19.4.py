# Exercise 4
"""
A super market plan to conduct a surprise cum lucky winner contest in a different way.
They decide to give a prize for two customers with maximum number of items
in common in their shopping list. Write a program to identify common items from
the shopping list of two customers. Prepare the common items list as read only.
"""

# Declare List
shopping_list = [["biscuit", "mobile"],
                 ["laptop", "headphones", "toilet paper"],
                 ["soap", "biscuit", "toilet paper"],
                 ["cup", "soap", "biscuit", "mobile", "laptop", "headphones", "toilet paper"],
                 ["laptop"],
                 ["cup", "soap", "biscuit", "mobile"]]
largest_common_num = 0
for i in shopping_list:
    for j in shopping_list:
        if shopping_list.index(i) == shopping_list.index(j):
            continue
        intersec_num = len(set(i) & set(j))
        if intersec_num > largest_common_num:
            largest_common_num = intersec_num
            index_1 = shopping_list.index(i)
            index_2 = shopping_list.index(j)
common_elements = tuple(set(shopping_list[index_1]) & set(shopping_list[index_2]))
print(common_elements)



# # find the index of customer with maximum number of items list in shopping cart
# largest = 0
# for i in shopping_list:
#     if len(i) > largest:
#         largest = len(i)
#         largest_index = shopping_list.index(i)
#
# # find the index of customer with second most maximum list in shopping cart
# largest = 0
# for i in shopping_list:
#     if i == shopping_list[largest_index]:
#         continue
#     if len(i) > largest:
#         second_largest = len(i)
#         second_largest_index = shopping_list.index(i)
#
# # Print the index of customers who won
# print(f'{largest_index + 1}th customer has maximum items')
# print(f'{second_largest_index + 1}nd customer has second most maximum items')
#
# # Finding the common elements
# set_1 = set(shopping_list[largest_index])
# set_2 = set(shopping_list[second_largest_index])
# common_items = tuple(set_1.intersection(set_2))
# print(f'Common elements are {common_items}')
# for i in set
