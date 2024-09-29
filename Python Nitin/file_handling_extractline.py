lines=[]
with open("temp.txt","r") as file:
	for i,line in enumerate(file):
		if i in [4,7]:
			lines.append(line.strip())
		elif i>7:
			break
print(lines)


