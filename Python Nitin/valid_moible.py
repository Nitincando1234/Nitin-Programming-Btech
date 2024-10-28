import re
mobile=(input("Enter the mobile number (with 91 or 0): "))
valid=r'^(0|\+91)?(([6-9][6-9][6-9])([0-9]{7}))$'
def isvalid(mobile):
    if(re.match(valid,mobile)):
        return True
    else:
        return False
if(isvalid(mobile)):
    print("Entered number is valid in India !")
else:
    print("Entered number is not valid in India !")