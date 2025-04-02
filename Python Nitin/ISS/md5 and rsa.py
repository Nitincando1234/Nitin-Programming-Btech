import hashlib

def md5_hash(inputStr: str):
    hash = hashlib.md5(inputStr.encode())
    return hash.hexdigest()

def sha_hash(inputStr: str):
    hash = hashlib.sha256(inputStr.encode())
    return hash.hexdigest()

def verify_hash(inputStr, hash):
    generated_hash = md5_hash(inputStr) if len(hash) == 32 else sha_hash(inputStr)
    return generated_hash == hash

inputStr = input("Enter the String: ")
choice = int(input("What to choose: \n 1. md5\n 2. sha256: "))
generated_hash = md5_hash(inputStr) if choice == 1 else sha_hash(inputStr)
print(f"The hash of the input string {inputStr}: {generated_hash}")
inputHash = input("Enter the Hash: ")
print("Verifying the hash: ...")

if verify_hash(inputStr, inputHash): print("Verified !")
else: print("Mismatch occured !")