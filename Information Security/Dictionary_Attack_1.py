import hashlib, pyinputplus

passwords = ["password", "password123", "letmein", "qwerty", "123456", "abc123", "admin", "welcome", "monkey", "sunshine"]
variations = ["", "123", "1234", "12345", "123456", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "-", "_", "+", "=", "/", "\\", "|", "[", "]", "{", "}", "<", ">"]
mypassword = pyinputplus.inputPassword("Enter the password want to break: ")
mypassword_hashed = hashlib.sha256(mypassword.encode()).hexdigest()
found = 0 
for password in passwords:
    for variation in variations:
        password_combination = password + variation
        hashed_password_combination = hashlib.sha256(password_combination.encode()).hexdigest()
        if (hashed_password_combination == mypassword_hashed): print(f"Password Found and was '{password_combination}'!"); found = 1; break
else: 
    if found == 0: print("Password not found !")
