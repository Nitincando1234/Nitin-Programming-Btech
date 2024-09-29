a=int(input('Enter the number to find the factorial: '))
fact=1
for i in range (1,a+1):
    fact=fact*i
print("Factorial :",fact,end='\n')