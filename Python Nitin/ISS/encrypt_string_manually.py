from pyinputplus import inputStr

stringInput = inputStr("Enter the String to be encrypted: ")
encString = [""]
offset = 4

for i in range(len(stringInput)):
    firstletter ="a" if (stringInput[i].islower()) else "A"
    newAlphaoffset = ord(stringInput[i]) - ord(firstletter) + 4
    encString += chr((ord(stringInput[i]) + newAlphaoffset) % 26 + ord(firstletter))

print("Original String: ", stringInput)
print("The Encrypted String: ", "".join(encString))