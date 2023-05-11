list_1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
# print(list(set(list_1)-{5}))
# for i in list_1:
#     if i == 5:
#         continue
#     else:
#         print(i)
# for x in range(0, len(list_1)):
#     if list_1[x] == 5:
#         continue
#     else:
#         print(list_1[x])
y = 0
while y < len(list_1):
    if list_1[y]==5:
        y = y + 1
        continue
    else:
        print(list_1[y])
        y = y+1
