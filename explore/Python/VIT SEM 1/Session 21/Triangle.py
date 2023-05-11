# Triangle Formation Problem
"""
Given three points, write an algorithm and the subsequent Python code to check if they can form a triangle.
Three points can form a triangle, if they do not fall in a straight line and length of a side of triangle
is less than the sum of length of other two sides of the triangle.

"""
# Here i have used determinant to find where three points are in straight line or not
# or check if ay two rows are proportional
# Different mathematical approaches can be followed
import math
import numpy as np


def tri(a, b, c):
    # Calculate determinant
    var = np.array([a, b, c])
    det_value_tri = np.linalg.det(var)
    # Calculate length of sides
    ls1 = math.sqrt((b[0] - a[0]) ** 2 + (b[1] - a[1]) ** 2 + (b[2] - a[2]) ** 2)
    ls2 = math.sqrt((b[0] - c[0]) ** 2 + (b[1] - c[1]) ** 2 + (b[2] - c[2]) ** 2)
    ls3 = math.sqrt((c[0] - a[0]) ** 2 + (c[1] - a[1]) ** 2 + (c[2] - a[2]) ** 2)
    if ls1 + ls2 > ls3 and ls1 + ls3 > ls2 and ls2 + ls3 > ls1:
        triangle = True
    else:
        triangle = False
    return det_value_tri, triangle


x = (1, 5, 3)
y = (3, 4, 5)
z = (3, 2, 1)
det_value = tri(x, y, z)
print()
if det_value[0] == 0 or det_value[1] == False:
    print("No triangle")
else:
    print(f"Yes Area of triangle will be {det_value[0] / 2}sq units")
