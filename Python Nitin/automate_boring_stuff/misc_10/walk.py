import os
for folder, subfolders, filenames in os.walk("."):
    print("Folder Name: ",folder)
    for subfolder in subfolders:
        print("SubFolder of ", folder, ": ",subfolder)
    for filename in filenames:
        print("File inside ", folder, ": ",filename)
    print(" ")