#problem statement:
# 1. Write Python program to store marks scored for first test of subject ‘Data Structures and
# Algorithms&#39; for N students. Compute
# A. The average score of class
# B. Highest score and lowest score of class
# C. Marks scored by most of the students
# D. list of students who were absent for the test
#this function is made for simplicity to fin length of any specified list instead of using predefined python functions
def custom_len(arr):
    length = 0
    while True:
        try:  # here we have performed exception handeling for certain amout of inputs it gets out of index so we have habdeled it via exception handeling code
            _ = arr[length]
            length += 1
        except (
            IndexError
        ):  # this block is useed to catch exception and prevents interpreter to throw error
            break
    return length

#function defined to remove duplicate frequency count get occured during sorting marks counts
def remove_duplicates(input_list):
    # Create an empty list to store unique elements
    unique_list = []

    # Iterate through the input_list using a while loop
    i = 0
    while i < len(input_list):
        current_element = input_list[i]
        is_duplicate = False

        # Check if the current element is already in the unique_list
        j = 0
        while j < len(unique_list):
            if current_element == unique_list[j]:
                is_duplicate = True
                break
            j += 1

        # If the current element is not a duplicate, add it to the unique_list
        if not is_duplicate:
            unique_list.append(current_element)

        i += 1

    return unique_list

#function defined for calculating averge score of marks list which comes as an parameter to this function
def calculate_average(marks):
    total = 0
    count = 0
    i = 0
    while i < custom_len(marks):#loop to iterate averge count
        total += marks[i]
        count += 1
        i += 1
    if count == 0:
        return 0
    return total / count#by dividing total by elements counts inside list we get appropritae average if marks scored by students

#this function defined to find the maximun number of score scored by an students from an marks array
def find_highest_lowest(marks):
    highest = lowest = marks[0]
    i = 0
    while i < custom_len(marks):#highest and lowest calculating  loop through iterating elements from marks array
        mark = marks[i]
        if mark > highest:#conditions which checks wheather particular mark is greater than or less than its previous and further values according to them they are selected as an highest and lowest element in the lists
            highest = mark
        elif mark < lowest:
            lowest = mark
        i += 1
    return highest, lowest

#function defined for taking students who are absent for an exam and make record of them by counting them seperately
def count_absent_students(marks):
    count = 0
    i = 0
    while i < custom_len(marks):
        if marks[i] == -1:  # Assuming -1 represents an absent student
            count += 1
        i += 1
    return count

#function used to calculate of partular scoe scored by an student in the form of mark and its frequency count
def find_most_frequent(marks):
    freqn_list = []
    key = 0
    counter = 0
    i = 0
    while i < custom_len(marks):#frequency calculating outer loop
        counter = 0
        j = 0
        while j < custom_len(marks):#frequency calculating inner loop
            if marks[i] == marks[j]:
                counter += 1
            j += 1
        freqn_list.append(str(marks[i]) + " " + str(counter))
        i += 1
    freqn_list = remove_duplicates(freqn_list)
    return freqn_list


# Input: List of marks for N students
N = int(input("Enter the number of students: "))#taking n numbers of inputs choices from user
marks = [0] * N#declaring an array as an initial 0 as subscript value to handle index out of ounds exception while access through an index
i = 0

while i < N:
    mark = int(input(f"Enter the mark for student {i + 1}: "))
    marks[i] = mark
    i += 1

#this is an driver code which actually calls the functions in the form of passing arguments via function call and
#appropriate result is returned from that function gets stored in returned function call variable
average = calculate_average(marks)#takes average as an returning value and displays it further
highest, lowest = find_highest_lowest(marks)#takes value of highest and lowest score and displays it further
absent_count = count_absent_students(marks)#takes count of absent students and stores it inside a storage unit
most_frequent_mark = find_most_frequent(marks)#actual frequency array is get as an return value from abover frequency calculating function

print(f"Average score of the class: {average}")
print(f"Highest score of the class: {highest}")
print(f"Lowest score of the class: {lowest}")
print(f"Count of absent students: {absent_count}")
print(f"Mark with the highest frequency: {most_frequent_mark}")
