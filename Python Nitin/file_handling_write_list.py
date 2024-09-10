def writelist():
    file=open("temp.txt","w")
    list=['nitin','sharma','the','great']
    for data in list:
        file.write(data+"\n")
    file.close()
writelist()