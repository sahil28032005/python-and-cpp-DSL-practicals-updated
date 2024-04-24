size = int(input("Enter size: "))
hashT = [-1] * size

def linear_prob(tele_no):
    count = 0
    for i in range(size):
        index = ((tele_no % size) + i) % size
        if hashT[index] == -1:
            hashT[index] = tele_no
            print("Inserted..")
            count += 1
            return
    print("No place to insert")

def quadratic_prob(tele_no):
    count = 0
    for i in range(size):
        index = ((tele_no % size) + i * i) % size
        if hashT[index] == -1:
            hashT[index] = tele_no
            print("Inserted..")
            count += 1
            return
        else:
            i += 1
            if i == size:
                print("Element cannot be inserted")

def search(tele_no):
    for i in range(size):
        if hashT[((tele_no % size) + i) % size] == tele_no:
            if i == 0:
                print("Found at O(1)")
                return
            else:
                print("Found at", i + 1, "comparisons")
                return
    print("Not found")

def printHashTable():
    print("INDEX   DATA")
    for i in range(size):
        print("{:<7d} {:<7d}".format(i, hashT[i]))

while True:
    choice = int(input("Enter 1 for insert data using linear probing\nEnter 2 for insert data using quadratic probing\nEnter 3 for search record\nEnter 4 for exit\n"))
    if choice == 1:
        for i in range(size):
            val = int(input("Enter your value: "))
            linear_prob(val)
    elif choice == 2:
        for i in range(size):
            val = int(input("Enter your value: "))
            quadratic_prob(val)
    elif choice == 3:
        data = int(input("Enter telephone number to search: "))
        search(data)
    elif choice == 4:
        break
