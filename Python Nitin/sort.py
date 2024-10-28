l=[1,2,3,4,5,0,2]
choice=int((input("Enter the choice:\n1. Ascending\n2. Descending\n:")))
if(choice==1):
    l.sort()
    print(l)
elif(choice==2):
    l.sort()
    l.reverse()
    print(l)
else:
    print("Incorrect choice !")