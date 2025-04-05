from cryptography.hazmat.primitives.asymmetric import padding, rsa      # hazmat = hazardous materials, primitives = elemental components in cryptography
from cryptography.hazmat.primitives import serialization, hashes
from cryptography.exceptions import InvalidSignature
from pyinputplus import inputStr

def load_private_key(fileName: str):
    with open(fileName, "rb") as file:
        deserialized = serialization.load_pem_private_key(
            file.read(),
            None
        )
        return deserialized

def load_public_key(fileName: str):
    with open(fileName, "rb") as file:
        deserialized = serialization.load_pem_public_key(
            file.read()
        )
        return deserialized

def sign_message(message: str, private_key):
    signature = private_key.sign(
        message.encode(),
        padding.PSS(
            mgf = padding.MGF1(hashes.SHA256()),
            salt_length = padding.PSS.MAX_LENGTH
        ),
        hashes.SHA256()
    )
    return signature

def verify_signature(message, signature, public_key)-> int:
    try:
        public_key.verify(
            signature, 
            message.encode(),
            padding.PSS(
                mgf = padding.MGF1(hashes.SHA256()),
                salt_length = padding.PSS.MAX_LENGTH
            ),
            hashes.SHA256()
        ); return 1
    except InvalidSignature: print("Verification of Signature Failed !")
    return 0

private_key = load_private_key("private_key.pem")
public_key = load_public_key("public_key.pem")
message = inputStr("Enter the message to be Digitally Signed: ")

signature = sign_message(message, private_key)

print("The Message(in Bytes): ", message.encode())
print("Signature: ", signature.hex())

print("Message in bytes: ", message.encode())
sign_message(message, private_key)

if verify_signature(message, signature, public_key): print("Verified the signature !")
else: print("Not a valid signature !")
