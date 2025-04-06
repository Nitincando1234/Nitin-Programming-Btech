import itertools, string, pyinputplus

password_to_crack = pyinputplus.inputPassword("Enter the password to crack: ")
chars_collection = string.printable.strip()
attempts: int = 0
for len in range(1, len(password_to_crack) + 1):
    for guess in itertools.product(chars_collection, repeat = len):
        attempts += 1
        guess = "".join(guess)
        if guess == password_to_crack:
<<<<<<< HEAD
            print(f"Found the password: {guess} ({attempts} attempts)")
=======
            print(f"Found the password: {guess} ('{attempts}'attempts)")
>>>>>>> 542465eb118369df330e16a721424d9b7dac71e4
            break
    else: continue
    break
else:
    print("Not found !")