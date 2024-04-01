#problem statement:
# Write Python program to store first year percentage of students in array. Write function for
# sorting array of floating point numbers in ascending order using
# A. Selection Sort
# B. Bubble sort and display top five scores.

marks_in_percentage=[];#array to store marks of student in percentage
import time #imported time library to calculate time taken by sunction to excute also for calculations related to process time and execution time taken by process

def custom_len(arr):
    length = 0
    while True:
        try:#here we have performed exception handeling for certain amout of inputs it gets out of index so we have habdeled it via exception handeling code
            _ = arr[length]
            length += 1
        except IndexError:#this block is useed to catch exception and prevents interpreter to throw error
            break
    return length

def takeInput():
    marks_counter = int(input("Enter how many students marks you want to store "))
    marks_in_percentage = [0] * marks_counter  # Create a list with n elements, initialized to 0
    i = 0 #counter variable for iterating loop

    while i < marks_counter:
        element = float(input(f"Enter marks of student  {i + 1}: "))
        marks_in_percentage[i] = element  # Assign the element at the specific index
        i += 1

    # You can print the list here or use it in other parts of your code
    return marks_in_percentage

#user defined function which simply displays top 5 marks from the total list of students percentages 
def displayTopFive():
    lastInd=custom_len(marks_in_percentage)-1
    i=0;
    print("students come inside top 5 rank as their percentage")
    while i<5:#loop iterating through the list of students
        print(marks_in_percentage[lastInd])
        lastInd-=1
        i+=1
        
#function which takes marklist as an parameter and displays that array according tp its size
def printArray(marks_in_percentage): 
    length = custom_len(marks_in_percentage)#printing all student marks in list 
    i = 0

    while i < length:
        print(marks_in_percentage[i],"%")
        i += 1
   
#function used to perform selection sort code using nested loops and no of oterations
def selectionSort():
    for i in range (custom_len(marks_in_percentage)):
     min=i;
     for j in range(i + 1, custom_len(marks_in_percentage)):
         if marks_in_percentage[j] < marks_in_percentage[min]:
          min=j
     temp=marks_in_percentage[i]
     marks_in_percentage[i]=marks_in_percentage[min]
     marks_in_percentage[min]=temp

#function which performs bubble sort and show data according to its number  of instructions and logic behind them
def bubble_sort():
    for i in range(1,custom_len(marks_in_percentage)):    
        for j in range(0,custom_len(marks_in_percentage)-i): 
            if marks_in_percentage[j]>marks_in_percentage[j+1]:
                temp =marks_in_percentage[j]
                marks_in_percentage[j] = marks_in_percentage[j+1]
                marks_in_percentage[j+1] = temp
                

#below is allover driver code which handle all user inputs and data displaying calls  
marks_in_percentage=takeInput()
print("Total entries entered as an marks of the students")
printArray(marks_in_percentage)  
start=time.time();  
process_time=time.process_time(); 
selectionSort()
end=time.time();
process_endtime=time.process_time(); 
print("Marks of students in percentages in ascending order")
printArray(marks_in_percentage)
print("total execution time for selectionsort",start-end)
print("process time for selectionsort",process_time-process_endtime)
print("same results getting from bubble sort but with with different time constraints")
start=time.time();  
process_time=time.process_time();
bubble_sort()
end=time.time();
process_endtime=time.process_time(); 
print("result after sorting using bubblesort")
printArray(marks_in_percentage)
print("total execution time for bubblesort",start-end)
print("process time for bubblesort",process_time-process_endtime)
displayTopFive()

