matrix=[]
print("Enter the size of the Matrix: ")
size=int(input())
def transpose(matrix):
	tra=[] 
	for i in range(len(matrix)):
		t=[]
		for j in range(len(matrix[0])):
			t.append(matrix[j][i])
		tra.append(t)
	return tra
def minor(matrix,i,j):
	return [row[:j] + row[j+1:] for row in (matrix[:i] + matrix[i+1:])]
def determinant(matrix):
	if len(matrix[0])==1:
		return matrix[0][0]
	elif len(matrix)==2:
		return ((matrix[0][0]*matrix[1][1])-(matrix[1][0]*matrix[0][1]))
	else:
			det=0
			for j in range(len(matrix)):
				det+=((-1)**j*determinant(minor(matrix,0,j)))
	return det
def inverse(matrix):
	det=determinant(matrix)
	adjugate=[]
	if det==0:
		print("det can't be zero !")
	for i in range(len(matrix)):
		adjugate_row=[]
		for j in range(len(matrix)):
			minor_det=determinant(minor(matrix,i,j))
			adjugate_row.append((-1)**(i+j)*minor_det)
		adjugate.append(adjugate_row)
	adjugate=transpose(adjugate)
	inversemat=[[element / det for element in row] for row in adjugate]
	return inversemat
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
print(transpose(matrix))
print("Original Matrix: ",matrix)
print("Inversed Matrix: ",inverse(list(matrix)))