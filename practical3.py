# problem statement:In Second year Computer Engineering class of M students, set A of students play cricket and set B
# of students play badminton. Write python program to find and display-
# A. Set of students who play either cricket or badminton or both
# B. Set of students who play both cricket and badminton
# C. Set of students who play only cricket
# D. Set of students who play only badminton
# E. Number of students who play neither cricket nor badminton

#custom list length finding function to calculate length of list or an array
def custom_len(arr):
    length = 0
    while True:
        try:#here we have performed exception handeling for certain amout of inputs it gets out of index so we have habdeled it via exception handeling code
            _ = arr[length]
            length += 1
        except IndexError:#this block is useed to catch exception and prevents interpreter to throw error
            break
    return length
# Input for cricket
num_elements_cricket = int(input("Enter the number of students who play cricket: "))
cricket = [""] * num_elements_cricket
i = 0
while i < num_elements_cricket:#loop works till user enter her choise of wanted number of elements here we have used as an iterator for taking multiple inputs from the user
    element = input(f"Enter element {i + 1}: ")
    cricket[i]=element #appends elements whose satisfied condition via loop variable in the particular list
    i += 1

# Input for badminton
num_elements_badminton = int(input("Enter the number of students who play badminton: "))
badminton = [""] *num_elements_badminton
i = 0
while i < num_elements_badminton:#loop for taking input of students who play badminton as their game iteerated using loop variable i
    element = input(f"Enter element {i + 1}: ")
    badminton[i]=element #appends elements whose satisfied condition via loop variable in the particular list
    i += 1

# Input for football
num_elements_football = int(input("Enter the number of students who play football: "))
football = [""] * num_elements_football
i = 0
while i < num_elements_football:#loop for taking input of students who play football as their game iteerated using loop variable i
    element = input(f"Enter element {i + 1}: ")
    football[i]=element #appends elements whose satisfied condition via loop variable in the particular list
    i += 1

#intersects two arrays by finding common elements in them
def intersection(l1, l2):#this is user defined function made for making intersection of two sets(int the form of python lists)
    result = []#used array to store result obtained from the intersection of two lists in the form of intersected sets
    index = 0#index variable used to loop through nested while loops

    while index < custom_len(l1): #loop runs until satisfied length get come and stops after unsatisfying the oarticular condition
        index2 = 0 
        while index2 < custom_len(l2): #this is an inner loop which iterates second list which has been comes as an parameter to a function
            if l1[index] == l2[index2]:
                result.append(l2[index2])
            index2 += 1
        index += 1

    return result

# unions two lists by collaborating lists with each others by removing duplicates
def union(l1, l2):
    result = l2.copy()
    index = 0

    while index < custom_len(l1):#outer loop to iterate over the parameterized list
        index2 = 0
        found = False

        while index2 < custom_len(l2):#this is an inner loop which iterates second list which has been comes as an parameter to a function
            if l1[index] == l2[index2]:
                found = True
                break
            index2 += 1

        if not found:
            result.append(l1[index])

        index += 1

    return result

   
# states difference between two sets by taking elements in such a way that they cant arrive in another specified set
def difference(l1, l2):
    index = 0
    result = []

    while index < custom_len(l1):#outer loop to iterate over the parameterized list
        index2 = 0
        found = False  
        while index2 < custom_len(l2):#this is an inner loop which iterates second list which has been comes as an parameter to a function
            if l1[index] == l2[index2]:
                found = True
                break  
            index2 += 1

        if not found:
            result.append(l1[index])

        index += 1

    return result



# a = union(cricket, badminton)
# print(intersection(badminton, cricket))
# print(difference(cricket,badminton))
print("students who play both cricket and badminton");
print(intersection(cricket,badminton));
print("students who play either cricket or badminton");
# print(difference(cricket,badminton),difference(badminton,cricket));
print(difference(union(cricket,badminton),intersection(cricket,badminton)));
print("student who play cricket and football but not badminton");
print(difference(union(cricket,football),badminton));
print("students who play neither cricket or badminton");
print(difference(football,union(cricket,badminton)));
