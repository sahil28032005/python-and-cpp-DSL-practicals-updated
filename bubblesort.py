marks = []
n = int(input("enter number of students:-"))
print("enter marks of students:-")
for i in range(n):
    mark = int(input())
    marks.append(mark)
print("marks of students are:-",marks)

def bubble_sort():
    for i in range(1,len(marks)):    
        for j in range(0,len(marks)-i): 
            if marks[j]>marks[j+1]:
                temp =marks[j]
                marks[j] = marks[j+1]
                marks[j+1] = temp
                print("sorted list is:-",marks)
    
bubble_sort()

