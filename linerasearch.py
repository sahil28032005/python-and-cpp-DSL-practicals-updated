#program to demonstrate linear search
#this program demonstartes use of linear search using linear fashion

array=list()#declaration of an list
length=int(input("enter th length of the array"))#inputing length of the array from user

for i in range(length):#loop through elements count as taking elements as an input
    data=int(input("enter the element"))
    array.append(data)#appending data of each loop call

key=int(input("enter the value f key you want to search..."))#taking search element and key as am user input


def linearSearch(array,key):#function that performs actual liner search and return element index at ewhich element was found
    for i in range(len(array)):
        if array[i]==key:
            print("element found")
            return i
            break
    print("element not found")
       

index=linearSearch(array,key)