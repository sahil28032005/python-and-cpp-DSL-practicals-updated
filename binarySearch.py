
array = list()
length = int(input("enter th length of the array"))

for i in range(length):
    data = int(input("enter the element"))
    array.append(data)


# for i in range(length):
#     for j in range(length-1-i):
#         if array[j]>array[j+1]:
#             temp=array[j+1]
#             array[j+1]=array[j]
#             array[j]=temp
#     j+=1
# i+=1


array.sort()
# for i in range(length):
#     print(array[i])


key = int(input("enter key to search inside array"))

# [1,34,56,78,90,99,999]
# def binarySearch(array, low, high, key):
#     noOfComparisons = 0
#     found = False
#     while low <= high:
#         mid = int((low + high) / 2)
#         noOfComparisons += 1
#         if array[mid] == key:
#             found = True
#             print("element found via taking", noOfComparisons, "number of comparisons")
#             break
#         elif key > array[mid]:
#             low = mid + 1
#         else:
#             high = mid - 1
#     if not found:
#         print("element not found")


def recurSiveBinarySearch(list, low, high, key):
     if low>high:
        print("your element not found")
        return False
     mid = int((low + high) / 2)
     if list[mid] == key:
        return mid
     elif key <list[mid]:
        return recurSiveBinarySearch(list, low, mid - 1, key)
     elif key >list[mid]:
        return recurSiveBinarySearch(list, mid + 1, high, key)
     

foundIndex=recurSiveBinarySearch(array,0,length-1,key)
if(foundIndex):
   print(f"element found at index number {foundIndex}")

# print(array)
# binarySearch(array, 0, length - 1, key)
