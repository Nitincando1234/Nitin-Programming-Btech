import send2trash
baconFile = open("baconFile.txt", "a")
baconFile.write("bacon is not a Vegetable !!!")
baconFile.close()

send2trash.send2trash("baconFile.txt")