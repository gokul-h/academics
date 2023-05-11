def andru(a_list,no_of_elements):
    for i in range(0, no_of_elements):
        for i in range(0, no_of_elements - 1):
            if a_list[i][2] > a_list[i + 1][2]:
                a_list[i][2], a_list[i + 1][2] = a_list[i + 1][2], a_list[i][2]
    print(a_list)


g_list = []
no_of_elements = int(input("enter the number of elemts in list::::"))
for i in range(0, no_of_elements):
    g_sub_list =[]
    for j in range(0,3):
        g_sub_list.append(input())
    g_list.append(g_sub_list)

andru(g_list,no_of_elements)
