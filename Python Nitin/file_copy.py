file=open("input.txt","r")
dest_file=open("output.txt","w")
for line in file.readlines():
    print(line)
    dest_file.write(line)
file.close()
dest_file.close()