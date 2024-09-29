a=int(input("Enter the first number:"))
b=int(input("Enter the second number: "))
try:
    print(a/0)
except ZeroDivisionError:
    print("Denominator can't be zero! ")
