# Python 3 program for recursive binary search.
# Modifications needed for the older Python 2 are found in comments.

# Returns index of x in arr if present, else -1
def binary_search(arr, low, high, x):
    # Check base case
    if high >= low:

        mid = (high + low) // 2

        # If element is present at the middle itself
        if arr[mid] == x:
            return mid

        # If element is smaller than mid, then it can only
        # be present in left subarray
        elif arr[mid] > x:
            return binary_search(arr, low, mid - 1, x)

        # Else the element can only be present in right subarray
        else:
            return binary_search(arr, mid + 1, high, x)

    else:
        # Element is not present in the array
        return -1


# Test array
arr = [2, 3, 4, 10, 40]
x = 10

# Function call
result = binary_search(arr, 0, len(arr) - 1, x)

if result != -1:
    print("Element is present at index", str(result))
else:
    print("Element is not present in array")

# def gokul(andru_list):
#     count = len(andru_list)
#     if count % 2 == 0:
#         if andru_list[int(count / 2)] == find or andru_list[int((count / 2) + 1)] == find:
#             print("Element found")
#         elif andru_list[int((count / 2) + 1)] > find:
#             new_list = andru_list[int((count / 2) + 1):]
#             gokul(new_list)
#         elif andru_list[int(count / 2)] < find:
#             new_list = andru_list[:int(count / 2)]
#             gokul(new_list)
#     else:
#         if andru_list[int((count + 1) / 2)] == find:
#             print("Element Founbd")
#         elif andru_list[int((count + 1) / 2)] > find:
#             new_list = andru_list[int((count + 1) / 2):]
#             gokul(new_list)
#         elif andru_list[int((count + 1) / 2)] < find:
#             new_list = andru_list[:int((count + 1) / 2)]
#             gokul(new_list)
#
#
# andru_list = [1, 5, 3, 4, 5, 5, 7, 8, 6, 10]
# find = int(input("ENter the :::::"))
# andru_list.sort()
# gokul(andru_list)
