# Linear Search
# ***************
# 
# This search technic works by searching linearly one by one.
# Generally linear search is performed on array.
# 
# Time Complexity: O(n)
# Space Complexity: O(n)
# 
# Algorithm: LinearSearch(Array, SearchValue)
#     Step1 - START
#     Step2 - for each item in the array
#     Step3 -     if item == SearchValue
#     Step4 -         return it's index
#     Step5 - return -1
#     Step1 - END
# 

def linearSearch(arr, searchValue):
    for i in range(0, len(arr)):
        if arr[i] == searchValue:
            return i
    return -1 
    # return arr.index(searchValue)

arr = [2, 5, 8, 2, 0, 3, 56, 6, 34, 546, 23, 76]
searchItem = 5
searchIndex = linearSearch(arr, searchItem)
if searchIndex == -1:
    print("Search Item ", searchItem, " not found")
else:
    print("Search Item ", searchItem, " found at Array Index ", searchIndex)
