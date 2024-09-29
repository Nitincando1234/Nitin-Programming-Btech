print("Enter the size of the Matrices: ")
size=int(input())
def input_matrix():    
    print("Enter the Elements of Matrix: ")
    matrix=[]
    for i in range(0,size):
        row=[]
        for j in range(0,size):
            print("Enter the a[",i+1,"][",j+1,"] : ")
            elem=int(input())
            row.append(elem)
            j+=1
        matrix.append(row)
        i+=1
    return matrix
matrix=input_matrix()
print("Unchanged matrix: ")
for i in range(0,len(matrix)):
    print(matrix[i])
print("Inversed matrix: ")
for i in range(0,len(matrix)):
    for j in range(0,len(matrix)):
        print(matrix[j][i],end=" ")
    print()