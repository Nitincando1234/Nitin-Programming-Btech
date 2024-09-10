print("Enter the value of n for n*n matrix: ",end='')
size=int(input())
row=[]
matrix=[]
for i in range(size):
    row=[]
    for j in range(size):
        if i==j:
            row.append(1)
        else:
            row.append(0)
    matrix.append(row)

print(matrix)
