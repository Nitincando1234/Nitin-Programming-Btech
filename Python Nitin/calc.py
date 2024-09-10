def calc(a,b):
    add=a+b
    sub=a-b
    mul=a*b
    div=round((a/b),2)
    rem=a%b
    list=[add,sub,mul,div,rem]
    return list
print("Enter any two numbers: ")
x=int(input())
y=int(input())
print(calc(x,y))
