def singlesum(num):
    num=str(num)
    if(len(num)==1):
        return num
    else:
        num=sum(int(digit) for digit in num)
        return singlesum(num)
print("Enter the number: ")
x=int(input())
print("The single digit sum is: ", singlesum(x))