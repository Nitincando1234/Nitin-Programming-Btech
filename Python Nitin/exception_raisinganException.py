try:
    x=int(input("Enter the value of x:"))
    if x>10:
        raise ValueError(x)

except:
    print(x,"'s Value is greater than 10")
else:
    print("Executed Successfully!")
