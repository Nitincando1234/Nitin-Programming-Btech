with open("input.txt","r") as file, open("output.txt","w") as dest_file:
    for line in file:
        dest_file.write(line)
    