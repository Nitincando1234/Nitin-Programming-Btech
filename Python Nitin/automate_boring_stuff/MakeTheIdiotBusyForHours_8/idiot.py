import pyinputplus as pyip
prompt = "Do you want to know how to keep an idiot busy for hours?\n"
while True:
    response = pyip.inputYesNo(prompt, yesVal = "yes", noVal = "no")
    if response == "no": break
print("Thank you. You were the idiot.")