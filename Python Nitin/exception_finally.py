try: 
    file=open("temp.txt","r")
    try:
        f.write("How are you ?")
    finally:
        f.close()
        print("File closed successfully!")
except:
    print("File Errors?????Don't Know")
