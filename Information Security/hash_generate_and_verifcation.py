import hashlib

def generate_hash_sha256(input_string):
    sha256_hash = hashlib.sha256(input_string.encode()).hexdigest()
    return sha256_hash
def generate_hash_md5(input_string):
    md5_hash = hashlib.md5(input_string.encode()).hexdigest()
    return md5_hash

def verify_hash(input_string, hash_given):
    hash = generate_hash_md5(input_string) if len(hash_given) == 32 else generate_hash_sha256(input_string)
    if(hash == hash_given): print("Hash is correct !")
    else: print("Hash is incorrect !")

inputStr = input("Enter the message: ")
choice = int(input("Want to generate hash:\n1.MD5\n2.SHA256: "))
hash = generate_hash_md5(inputStr) if choice == 1 else generate_hash_sha256(inputStr)
print("Hash value of the message is: " + hash)
print("Verification of the message: ", end = "")
verify_hash(inputStr, hash)