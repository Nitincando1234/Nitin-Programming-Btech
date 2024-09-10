def replacer():
    data=""
    with open("temp.txt","r") as file:
        data=file.read()
    with open("temp.txt","w") as file:
        data=data.replace("*","_")
        file.write(data)
replacer()