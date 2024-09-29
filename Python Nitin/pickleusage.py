import pickle
data = {'Name':['Nitin','Is','Greater','Always'],'Age':18}
file = open('pickle.txt','wb')
#serialize data
pickle.dump(data,file)
file.close()
#deserialize data
file = open('pickle.txt','rb')
loaded=pickle.load(file)
file.close()
print(loaded)


