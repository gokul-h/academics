"""
Compute Simple interest for given principle(P),
number of years(N) and rate of interest(R).
If R value is not given then consider R value as 10.5%.
Use keyword arguments for the same.
"""


def intrest(P, N, R=10.5):
    simple_intrest = (P * R * N)/100
    return simple_intrest


input_var_1 = int(input("Principal amount:"))
input_var_2 = int(input("No of years:"))
input_var_3 = int(input("Intrest rate:"))

print(intrest(input_var_1, input_var_2, input_var_3))
