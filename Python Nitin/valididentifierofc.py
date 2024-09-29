import re
import keyword
def check_identifier(identifier):
    if not re.match(r'^[a-zA-Z_]',identifier):
        return False;
    if not re.match(r'^[a-zA-Z0-9_]*$',identifier):
        return False
    if keyword.iskeyword(identifier):
        return False
    return True
identifier=input("Enter the identifier: ")
if (check_identifier(identifier)):
    print(identifier," is a Valid Identifier !")
else:
    print(identifier," is not a Valid Identifier !")