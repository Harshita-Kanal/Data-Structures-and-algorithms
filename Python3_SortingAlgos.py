#bubble sort function

def bubblesort(list):

# Swap the elements to arrange in order
    for iter_num in range(len(list)-1,0,-1):
        for idx in range(iter_num):
            if list[idx]>list[idx+1]:
                temp = list[idx]
                list[idx] = list[idx+1]
                list[idx+1] = temp

#merge sort function

def merge_sort(unsorted_list):
    if len(unsorted_list) <= 1:
        return unsorted_list
# Find the middle point and devide it
    middle = len(unsorted_list) // 2
    left_list = unsorted_list[:middle]
    right_list = unsorted_list[middle:]

    left_list = merge_sort(left_list)
    right_list = merge_sort(right_list)
    return list(merge1(left_list, right_list))

# Merge the sorted halves

def merge1(left_half,right_half):

    res = []
    while len(left_half) != 0 and len(right_half) != 0:
        if left_half[0] < right_half[0]:
            res.append(left_half[0])
            left_half.remove(left_half[0])
        else:
            res.append(right_half[0])
            right_half.remove(right_half[0])
    if len(left_half) == 0:
        res = res + right_half
    else:
        res = res + left_half
    return res

#insertion sort function

def insertion_sort(InputList):
    for i in range(1, len(InputList)):
        j = i-1
        nxt_element = InputList[i]
# Compare the current element with next one
		
        while (InputList[j] > nxt_element) and (j >= 0):
            InputList[j+1] = InputList[j]
            j=j-1
        InputList[j+1] = nxt_element

#shell sort function

def shellSort(input_list):
    
    gap = len(input_list) // 2
    while gap > 0:

        for i in range(gap, len(input_list)):
            temp = input_list[i]
            j = i
# Sort the sub list for this gap

            while j >= gap and input_list[j - gap] > temp:
                input_list[j] = input_list[j - gap]
                j = j-gap
            input_list[j] = temp

# Reduce the gap for the next element

        gap = gap//2

#selection sort function

def selection_sort(input_list):

    for idx in range(len(input_list)):

        min_idx = idx
        for j in range( idx +1, len(input_list)):
            if input_list[min_idx] > input_list[j]:
                min_idx = j
# Swap the minimum value with the compared value

        input_list[idx], input_list[min_idx] = input_list[min_idx], input_list[idx]

#heap sort functions

def heapify(arr, n, i): 
    largest = i # Initialize largest as root 
    l = 2 * i + 1     # left = 2*i + 1 
    r = 2 * i + 2     # right = 2*i + 2 
  
    # See if left child of root exists and is 
    # greater than root 
    if l < n and arr[i] < arr[l]: 
        largest = l 
  
    # See if right child of root exists and is 
    # greater than root 
    if r < n and arr[largest] < arr[r]: 
        largest = r 
  
    # Change root, if needed 
    if largest != i: 
        arr[i],arr[largest] = arr[largest],arr[i] # swap 
  
        # Heapify the root. 
        heapify(arr, n, largest) 
  
# The main function to sort an array of given size 
def heapSort(arr): 
    n = len(arr) 
  
    # Build a maxheap. 
    for i in range(n//2 - 1, -1, -1): 
        heapify(arr, n, i) 
  
    # One by one extract elements 
    for i in range(n-1, 0, -1): 
        arr[i], arr[0] = arr[0], arr[i] # swap 
        heapify(arr, i, 0)

#Iterative merge sort functions
def merge(left, right): 
    if not len(left) or not len(right): 
        return left or right 
  
    result = [] 
    i, j = 0, 0
    while (len(result) < len(left) + len(right)): 
        if left[i] < right[j]: 
            result.append(left[i]) 
            i+= 1
        else: 
            result.append(right[j]) 
            j+= 1
        if i == len(left) or j == len(right): 
            result.extend(left[i:] or right[j:]) 
            break 
  
    return result 
  
def mergesort_iterative(list): 
    if len(list) < 2: 
        return list
  
    middle = len(list)/2
    left = mergesort_iterative(list[:middle]) 
    right = mergesort_iterative(list[middle:]) 
  
    return merge(left, right)

#binary insertion sort functions

def binary_search(arr, val, start, end): 
    # we need to distinugish whether we should insert 
    # before or after the left boundary. 
    # imagine [0] is the last step of the binary search 
    # and we need to decide where to insert -1 
    if start == end: 
        if arr[start] > val: 
            return start 
        else: 
            return start+1
  
    # this occurs if we are moving beyond left's boundary 
    # meaning the left boundary is the least position to 
    # find a number greater than val 
    if start > end: 
        return start 
  
    mid = (start+end)/2
    if arr[mid] < val: 
        return binary_search(arr, val, mid+1, end) 
    elif arr[mid] > val: 
        return binary_search(arr, val, start, mid-1) 
    else: 
        return mid 
  
def binary_insertion_sort(arr): 
    for i in xrange(1, len(arr)): 
        val = arr[i] 
        j = binary_search(arr, val, 0, i-1) 
        arr = arr[:j] + [val] + arr[j:i] + arr[i+1:] 
    return arr 

#iterative heap sort functions
 
def buildMaxHeap(arr, n):  
  
    for i in range(n): 
          
        # if child is bigger than parent  
        if arr[i] > arr[int((i - 1) / 2)]: 
            j = i  
      
            # swap child and parent until  
            # parent is smaller  
            while arr[j] > arr[int((j - 1) / 2)]: 
                (arr[j],  
                 arr[int((j - 1) / 2)]) = (arr[int((j - 1) / 2)],  
                                           arr[j]) 
                j = int((j - 1) / 2) 
  
def iterative_heapSort(arr, n):  
  
    buildMaxHeap(arr, n)  
  
    for i in range(n - 1, 0, -1): 
          
        # swap value of first indexed  
        # with last indexed  
        arr[0], arr[i] = arr[i], arr[0] 
      
        # maintaining heap property  
        # after each swapping  
        j, index = 0, 0
          
        while True: 
            index = 2 * j + 1
              
            # if left child is smaller than  
            # right child point index variable  
            # to right child  
            if (index < (i - 1) and 
                arr[index] < arr[index + 1]):  
                index += 1
          
            # if parent is smaller than child  
            # then swapping parent with child  
            # having higher value  
            if index < i and arr[j] < arr[index]:  
                arr[j], arr[index] = arr[index], arr[j]  
          
            j = index  
            if index >= i: 
                break

#recursive bubble sort function

def recursive_bubble_sort(listt): 
    for i, num in enumerate(listt): 
        try: 
            if listt[i+1] < num: 
                listt[i] = listt[i+1] 
                listt[i+1] = num 
                recursive_bubble_sort(listt) 
        except IndexError: 
            pass
    return listt 


print("Menu of Sorting Algorithms:\n")
print("1. Bubble Sort\n")
print("2. Merge Sort\n")
print("3. Insertion Sort\n")
print("4. Shell Sort\n")
print("5. Selection Sort\n")
print("6. Heap Sort\n")
print("7. Iterative Merge Sort\n")
print("8. Binary Insertion Sort\n")
print("9. Iterative Heap Sort\n")
print("10. Recursive Bubble Sort\n")
ctr=int(input("Enter the Number of your Sorting Choice (1-10) :"))
if(ctr==10):
#recursive bubble sort driver code
  
    listt = [64, 34, 25, 12, 22, 11, 90] 
    recursive_bubble_sort(listt) 
  
    print("Sorted array:"); 
    for i in range(0, len(listt)): 
        print(listt[i], end=' ')
        
elif (ctr==9):  
# iterative heap sort driver code

    arr = [10, 20, 15, 17, 9, 21]  
    n = len(arr)  
      
    print("Given array: ") 
    for i in range(n): 
        print(arr[i], end = " ")  
          
    print()  
  
    iterative_heapSort(arr, n)  
  
# print array after sorting  
    print("Sorted array: ") 
    for i in range(n): 
        print(arr[i], end = " ") 

elif(ctr==8):
    #binary insertion sort driver code
  
    print("Sorted array:") 
    print (binary_insertion_sort([37, 23, 0, 17, 12, 72, 31, 
                        46, 100, 88, 54]))
    
elif(ctr==7):
#Iterative merge sort driver code
      
    seq = [12, 11, 13, 5, 6, 7] 
    print("Given array is") 
    print(seq);  
    print("\n") 
    print("Sorted array is") 
    print(mergesort_iterative(seq)) 
  
elif(ctr==6):  
# Heap sort driver code

    arr = [ 12, 11, 13, 5, 6, 7] 
    heapSort(arr) 
    n = len(arr) 
    print ("Sorted array is") 
    for i in range(n): 
        print (arr[i] + "\t")

elif(ctr==5):
#Selection Sort driver code

    l = [19,2,31,45,30,11,121,27]
    selection_sort(l)
    print(l)

elif(ctr==2):
#merge_sort driver code

    unsorted_list = [64, 34, 25, 12, 22, 11, 90]

    print(merge_sort(unsorted_list))

elif (ctr==3):
#insertion sort  driver code

    list = [19,2,31,45,30,11,121,27]
    insertion_sort(list)
    print(list)

elif(ctr==4):
#shell sort  driver code

    list = [19,2,31,45,30,11,121,27]

    shellSort(list)
    print(list)

elif (ctr==1):
#bubble sort  driver code

    list = [19,2,31,45,6,11,121,27]
    bubblesort(list)
    print(list)

else:
    print("\n Wrong Choice Entered")
