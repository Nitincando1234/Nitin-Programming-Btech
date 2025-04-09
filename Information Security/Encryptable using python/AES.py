from Crypto.Cipher import AES 
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad, unpad
import base64

def encryptText(msg, key = None):
    msg_enc = msg.encode("utf-8")
    if not key: key = get_random_bytes(32)
    iv = get_random_bytes(16)   # initialization vector
    cipher = AES.new(key, AES.MODE_CBC, iv)
    padded_text = pad(msg_enc, AES.block_size)
    cipher_text = cipher.encrypt(padded_text)
    msg_enc = iv + cipher_text
    msg_enc = base64.b64encode(msg_enc).decode("utf-8")
    return msg_enc, key

def decryptText(msg_enc, key):
    msg_enc = base64.b64decode(msg_enc)
    iv = msg_enc[: 16]
    cipher_text = msg_enc[16: ]
    cipher = AES.new(key, AES.MODE_CBC, iv)
    padded_text = cipher.decrypt(cipher_text)
    plain_text = unpad(padded_text, AES.block_size)
    return plain_text

inputStr = input("Enter the input message: ")
msg_enc, key = encryptText(inputStr)
key_decoded = base64.b64encode(key).decode("utf-8")
decryptText = decryptText(msg_enc, key)
print(f"Encrypted Message: {msg_enc} \n with key: {key_decoded}")
print(f"Decrypted Message: {decryptText.decode("utf-8")}")