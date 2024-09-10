with open("new.txt","r") as file:
    for ln in file:
        print(ln)
print("File Close Status: ",file.closed)