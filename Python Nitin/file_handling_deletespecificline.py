lines=[]
with open("temp.txt","r") as file:
	lines=file.readlines()
with open("temp.txt","w") as file:
	for i,line in enumerate(lines):
		if i not in [4,7]:
			file.write(line)

