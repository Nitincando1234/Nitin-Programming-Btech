try:
    x=open("temp.txt","r")
    print(x.read())
except (IOError):
    print("Input /OutPut Error! ")
else:
    print("Executed Successfully !")

