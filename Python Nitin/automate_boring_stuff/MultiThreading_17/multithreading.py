import threading, time

def takeAnap():
    time.sleep(5)
    print("Wake Up !")

threadObj = threading.Thread(target = takeAnap)
threadObj.start()
print("End of the program !")