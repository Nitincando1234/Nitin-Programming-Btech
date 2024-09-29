try:
    x=int(input("Enter the positive value for x: "))
    if (x<0):
        raise ValueError("Negative values are not allowed!")
except ValueError as e:
    print(e)
