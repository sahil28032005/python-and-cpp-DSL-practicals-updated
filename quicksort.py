#program to perform quicksort
#problem statement:3. Write Python program to store first year percentage of students in array. Write function for
# sorting array of floating point numbers in ascending order using quick sort and display top five
# scores.
def partition(arr, s, e):#function used to partition arrys in the form of placing pivot at its right position
    pivot = arr[s]
    cnt = 0
    for i in range(s + 1, e + 1):
        if arr[i] <= pivot:
            cnt += 1

    pivotIndex = s + cnt
    arr[pivotIndex], arr[s] = arr[s], arr[pivotIndex]

    i, j = s, e
    while i < pivotIndex and j > pivotIndex:
        while arr[i] <= pivot:
            i += 1
        while arr[j] > pivot:
            j -= 1
        if i < pivotIndex and j > pivotIndex:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            j -= 1

    return pivotIndex

def quickSort(arr, s, e):
    if s >= e:
        return

    p = partition(arr, s, e)
    quickSort(arr, s, p - 1)#sorts left subArrays
    quickSort(arr, p + 1, e)#sorts right subarrays

arr = [12.67,56.3,1.2,99.45,455.3,23.3]#array which is going to be sorted
n = len(arr)

quickSort(arr, 0, n - 1)

for i in range(n):
    print(arr[i], end=" ")
print()
