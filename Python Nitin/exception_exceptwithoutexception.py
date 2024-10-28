try: 
    file=open("temp.txt","r")
except (IOError,ValueError):
    print("Known Error is occured ! ")
except:
    print("Error Occured !")
