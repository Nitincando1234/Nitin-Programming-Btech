import re
def validation(email):
    pattern=r'^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$'
    if(re.match(pattern,email)):
        return True
    else:
        return False
email=input("Enter the Email: ")
if(validation(email)==True):
    print(email," : A valid email !")
else:
    print(email," : Not a valid email !")