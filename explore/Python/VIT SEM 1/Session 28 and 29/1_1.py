import string
import random


def get_random_name():
    letters = string.ascii_letters
    result_str = ''.join(random.choice(letters) for i in range(5))
    return result_str


def get_random_number():
    return random.randrange(0, 100, 1)


student_list = open("student_list_1.txt", "w")
Num = int(input("Please enter the no of students needed"))
for i in range(Num):
    student_list.write(f'{get_random_name()} {get_random_number()}\n')
student_list.close()
