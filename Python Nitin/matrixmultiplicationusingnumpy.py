import numpy as np
size=int(input("Enter the size of the matrix: "))
print("Input values for first matrix: ")
row=[]
i=0;j=0
matrix1=[]
matrix2=[]
for i in range(size):
    row=[]
    for j in range(size):
        print("Enter the value of a[",i+1,"][",j+1,"]")
        a=int(input())
        j+=1
        row.append(a)
    matrix1.append(row)
    i+=1
print("Input values for second matrix: ")
row=[]
i=0;j=0
for i in range(size):
    row=[]
    for j in range(size):
        print("Enter the value of a[",i+1,"][",j+1,"]")
        a=int(input())
        j+=1
        row.append(a)
    matrix2.append(row)
    i+=1
matrix1=np.array(matrix1)
matrix2=np.array(matrix2)
mul=matrix1*matrix2
print(matrix1)
print(matrix2)
print("Multiplication of matrices are as shown:\n",mul)
addition=matrix1+matrix2
print("Addition of matrices are as shown:\n",addition)
