class node:
    def __init__(self,data):
        self.data=data
        self.next=None
size = 5
class list:
    def __init__(self):
        self.start=None
    def creation(self):
        print("size of the linkedlist is taken to be 5:")
        data = int(input("Enter the data: "))
        i = 0
        while i < 5:
            node = node(data)
            if (self.start == None):
                self.start = node
                self.start.next = None
            else: 
                last = self.start
                while last.next:
                    last = last.next
                last.next = node
                last = last.next
            i+=1
    def printer(self):
        i = 0
        last = self.start
        while last.next:
            print(last.data)
            if last.next: break
            print('->')
l=list()
l.creation()
l.printer()
