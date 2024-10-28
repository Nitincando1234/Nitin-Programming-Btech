matrix1=[]
matrix2=[]
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
result = [[0 for _ in range(size)] for _ in range(size)]
print(result)
def multiply():
    for i in range(0,len(matrix1)):
        for j in range(0,len(matrix1[0])):
            for k in range(0,len(matrix1)):
                result[i][j]+=(matrix1[i][k]*matrix2[k][j])
            print(result[i][j])
    return result
def printer():
    for i in range(0,len(result)):
        print(result[i],end=",\n")
matrix1=input_matrix()
matrix2=input_matrix()
result=multiply()
printer()
print(matrix1)
print(matrix2)

