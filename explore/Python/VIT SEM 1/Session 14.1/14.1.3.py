"""
A scientific report is been generated in US English and it has to be converted to Indian English.
Some words have to be changed as per the given format
Color -> colour
In some words the letter “z” have to be replaced with “s” like synchronize to synchronise
Read the document and convert it to Indian English

"""
import math
def main_func():
    k = int(input())
    k_a = list()
    for i in range(k):
        k_a[i]=int(input())
    first_max = abs(k_a[0]-k_a[1])
    second_max = 0
    for i in range(0,len(k_a):
            for j in range(i,len(k_a)):
                if (abs(k_a[i]-k_a[j])>first_max):
                        first_max = abs(k_a[i]-k_a[j])
                        second_max = first_max
    print(second_max)


n = int(input())    
for i in range(n):
    main_func()