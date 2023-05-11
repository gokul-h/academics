# import re
#
# txt = " simply dummy text of the cold printing Do^g and typesetting dear industry."
# a = txt.split()
# for i in a:
#     x = []
#     x = re.findall("\A[cd]\w", i)
#     if x:
#         print(i)

# import re
#
# m = "Hey cool is the doggy cu*j"
# n = m.split()
# for i in n:
#     x = re.match('^[\w-]+$', i)  # To check alpha numeric
#     if x:
#         y = re.match("\A[cd]", i)  # to check whether it start with c or d
#         if y:
#             print(i)

# Siddarth
#
# def func(a, b):
#     a = a * 10
#     c = a + b
#     return c
#
#
# a = int(input())
# b = int(input())
# c = 0
# print(func(a, b))

def add(*args):
    c = len(args)
    if c == 2:
        return a + b
    else:
        return 'Excess ' + str(c)



