# chaining using open hashing without replacement
size = int(input("enter size of your database"))

class Record:
    def __init__(self, data, value, chain=-1):
        self.data = data
        self.chain = chain
        self.value = value

hashT = [Record(-1, "EMPTY") for _ in range(size)]

def linear_prob(obj):
    for i in range(size):
        index = ((obj.data % size) + i) % size
        if hashT[index].data == -1:
            hashT[index] = obj
            print("inserted..")
            if i > 0:
                for j in range(size):
                    hash = obj.data % size + j
                    if (
                        hashT[hash % size].chain == -1
                        and hashT[  # getting error here
                            (obj.data % size + j) % size
                        ].data
                        % size
                        == (hashT[index].data % size)
                        and index != hash
                    ):
                        hashT[hash % size].chain = index
                        break

            return

    print("no place to insert")

def delete(key):
    index = key % size
    for i in range(size):
        if hashT[index].data == key:
            # print("key found")
            # hashT[index].data = -1
            if hashT[index].chain != -1:
                while hashT[index].chain != -1:
                    hashT[index].data = hashT[hashT[index].chain].data
                    # hashT[index].chain = hashT[hashT[index].chain].chain
                    hashT[index].value = hashT[hashT[index].chain].value
                    index = hashT[index].chain
                hashT[index].data = -1
                hashT[index].value = "EMPTY"
                hashT[index].chain = -1
                hashT[index - 1].chain = -1
                return
            else:
                hashT[index].data = -1
                hashT[index].value = "EMPTY"
                return

        else:
            index = hashT[index].chain


while 1:
    choise = int(
        input(
            "1) for store data using chaining without replacement:\n2)Display current hash table without replacement method\n3)Delete element"
        )
    )
    if choise == 1:
        for i in range(size):
            key = int(input("Enter your key"))
            value = input("Enter value")
            p1 = Record(key, value)
            linear_prob(p1)

    if choise == 2:
        print("INDEX   DATA   VALUE         CHAIN")
        for i in range(size):
            if hashT[i] != -1:
                print(
                    "{:<7d} {:<7d} {:<13s} {:<7d}".format(
                        i, hashT[i].data, hashT[i].value, hashT[i].chain
                    )
                )
            else:
                print("{:<7d} EMPTY".format(i))

    if choise == 3:
        data = int(input("enter value which you want to delete"))
        delete(data)

    if choise == 4:
        break
