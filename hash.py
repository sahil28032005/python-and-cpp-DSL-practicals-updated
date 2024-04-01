size=int(input("enter size"))
hashT=[-1]*size
def linear_prob(tele_no):
    count=0
    for i in range(size):
      index=((tele_no%size)+i)%size
      if(hashT[index]==-1):
        hashT[index]=tele_no
        print("inserted..")
        count+=1
        return
    
    print("no place to insert")

def quadratic_prob(tele_no):
    count=0
    for i in range(size):
      index=((tele_no%size)+i*i)%size
      if(hashT[index]==-1):
        hashT[index]=tele_no
        print("inserted..")
        count+=1
        return
      else:
        i+=1
        if(i==size):
         print("element cannot be inserted")
 
def search(tele_no):
     for i in range(size):
         if(hashT[((tele_no%size)+i)%size]==tele_no):
           if(i==0):
              print("fount at O(1)")
              return
           else:
             print("found at ",i+1,"comparison")
             return
           
         else:
           continue
         
     print("not found")
def printHashTable():
   print("INDEX   DATA ")
        for i in range(size):
           print(
                    "{:<7d} {:<7d}".format(
                        i, hashT[i]
                  )
                )
  

while(1):
  choise=int(input("Enter 1 for insert data using linear probing\nEnter 2 for insert data using quadratic quadratic probing\nEnter 3 for search record\nEnter 4 for exit\n"))   
  if(choise==1):
    for i in range(size):
      val=int(input("entered your value"))
      linear_prob(val)
  if(choise==2):
    for i in range(size):
      val=int(input("entered your value"))
      quadratic_prob(val)
  if(choise==3):
    data=int(input("Enter telephone number to search"))
    search(data)
  if(choise==4):
    break





