import os
import send2trash
import shutil
import pathlib
from zipfile import ZipFile
from zipfile import ZIP_DEFLATED
path = pathlib.Path.cwd()
exampleZip = ZipFile(path / "automate_boring_stuff" / "mockZip.zip")
print(exampleZip.namelist())
fileInfo = exampleZip.getinfo("mockZip/catnames_file.txt")
print(fileInfo.file_size)
print(fileInfo.filename)
print(fileInfo.compress_size)
print(fileInfo.compress_type)
print(f"File : {fileInfo.filename} after compression is {round(fileInfo.file_size / fileInfo.compress_size)}* Smaller !!!")

#to extract files
#exampleZip.extractall("mockZip")
#shutil.move("/automate_boring_stuff/mockZip","./")
exampleZip.close()
#for folders, subfolders, filenames in os.walk("./automate_boring_stuff/mockZip"):
#   for filename in filenames:
#       send2trash.send2trash(filename)
newZip = ZipFile("new.zip", "w")
newZip.write("mockZip/MOCK_DATA.csv", compress_type=ZIP_DEFLATED)
newZip.close()
os.unlink("new.zip")