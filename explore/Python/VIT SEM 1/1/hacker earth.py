def main_func():
    k = int(input())
    ka = input().split(" ")
    for i in range(k):
        ka[i] = int(ka[i])
    f_max = abs(ka[0] - ka[1])
    s_max = 0
    for i in range(0, k):
        for j in range(i, k):
            if abs(ka[i] - ka[j]) > f_max:
                s_max = f_max
                f_max = abs(ka[i] - ka[j])
    return s_max


n = int(input())
for i in range(0, n):
    print(main_func())
