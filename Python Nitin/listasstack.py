list=[]
size=5
top=-1
while(True):
    x=input("Enter the value to store in stack: ")
    if(top==size-1):
        print("Stack Overflow !")
        break
    else:
        list.append(x)
    top+=1
print(list)
print("Showing the contents of the stack: ")
while(True):
    if(top<0):
        print("Stack Underflow")
        break
    else:
        print(list.pop())
    top-=1