"""
Compute area of circle using all possible function prototypes.
"""
import math


def area_circle(r):
    area = math.pi * r ** 2
    return area


input_radius = float(input())
print(area_circle(input_radius))