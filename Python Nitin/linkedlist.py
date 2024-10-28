class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
class linkedlist:
    size=5
    x=0
    def __init__(self):
        self.head=None
    print("Size of the list is taken to be 5")
    def creation(self):
        i=0
        while i<5:
            print("Enter the ",i+1," Element: ",end="")
            x=int(input())
            newnode=Node(x)
            if(self.head==None):
                self.head=newnode
            else:
                last=self.head
                while last.next:
                    last=last.next
                last.next=newnode
            i+=1
    def printer(self):
        last=self.head
        i=0
        while i<self.size:
            print(last.data)
            last=last.next
            i+=1
    def insertionatbegin(self,x):
        newnode=Node(x)
        newnode.next=self.head
        self.head=newnode
        self.size+=1
    def deleteatspecified(self,index):
        last=self.head
        if(index-1==0):
            self.head=last.next
        for _ in range(index-2):
            last=last.next
        last.next=last.next.next
        self.size-=1
    def find(self,num):
        i=1
        last=self.head
        test=0
        while last:
            if(last.data==num):
                print("Found at: ",i)
                test=0
                return
            i+=1
            last=last.next
        if test==1:
            print("Not found")
l=linkedlist()
l.creation()
l.printer()
print("Operation to perform:","\n","1.Insertion at the begining \n2.Delete at specified position\n3.Search an element: ")
choice=int(input())
if choice==1:
    x=int(input("Enter the data: "))
    l.insertionatbegin(x)
    l.printer()
elif choice==2:
   index=int(input("Enter the index at which to delete: "))
   l.deleteatspecified(index)
   l.printer()
elif choice==3:
    x=int(input("Enter the number: "))
    l.find(x) 
else:
    print("Wrong choice !")