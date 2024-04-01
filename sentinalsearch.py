#problem statement
#program to perform linear sentinal search by performing different method
k = 0  # Initialize k in the global scope
array = []
length = int(input("Enter the length of the array: "))

for i in range(length):
    data = int(input("Enter the element: "))#taking input array elements from the user
    array.append(data)

key = int(input("Enter the value of the key you want to search: "))#taken element as an key to append it to ann last element of anarray as an rule of sentinal search

last = array[-1]#the index -1 denotes last that is n-1th element of the arrya this position is ,ostly used in the sentinal search
array[-1] = key#we have appended key as am last element of the array
# print(array)

#method used to perform sentinal search whic finds index of the elment and returns it to caller
def sentinalsearch(array, key):#function taking array and key as an parameter
    global k  # Use global since k is a global variable
    while array[k] != key:#incrementing counter till we not find element inside iteration
        k += 1

    # Restore the last element of the array
    array[-1] = last

    if k < (len(array) - 1) or key == array[len(array) - 1]:
        return k  # Return the index where the key is found
    else:
        return -1  # Key not found

index = sentinalsearch(array, key)#actual function call is done here followwd by an two argumments which are array and key
if index != -1:
    print(f"Key found at index {index}")
else:
    print("Key not found")
