def sort(a_list, no_of_elements):
    for i in range(0, no_of_elements):
        for j in range(i + 1, no_of_elements):
            if a_list[j] < a_list[i]:
                small = a_list[j]
        index = a_list.index(small)
        a_list[i], a_list[index] = a_list[index], a_list[i]
    return a_list


g_list = []
no_of_elements = int(input("enter the number of elemts in list::::"))
for i in range(0, no_of_elements):
    g_list.append(int(input()))

alist = sort(g_list, no_of_elements)
sorted(alist, reverse=True)
for i in alist:
    print(i)
