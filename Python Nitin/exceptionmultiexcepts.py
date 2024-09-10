try:
    x=int(input("Enter the number: "))
    y=x+2
    print("y=",y)
except KeyboardInterrupt:
    print("Enter the value ! ")
except ValueError:
    print("Check Values !")
