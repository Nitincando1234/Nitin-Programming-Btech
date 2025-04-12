import rsa, base64

def encryptText(inputStr, keys = None):
    msg = inputStr.encode("utf-8")
    if not keys: public_key, private_key = rsa.newkeys(2048)
    msg = rsa.encrypt(msg, public_key)
    msg = base64.b64encode(msg).decode()
    return msg, public_key, private_key

def decryptText(dec_msg, key):
    msg = base64.b64decode(dec_msg)
    msg = rsa.decrypt(msg, key)
    return msg

msg = input("Enter the string to be encrypted: ")
msg_enc, pub_key, pvt_key = encryptText(msg)
pub_key = base64.b64encode(pub_key.save_pkcs1()).decode("utf-8")
pvt_key_dec = base64.b64encode(pvt_key.save_pkcs1()).decode("utf-8")
msg_dec = decryptText(msg_enc, pvt_key)
print(f"Encrypted Text: {msg_enc} \nwith Public Key: \n{pub_key}")
print(f"Decrypted Text: {msg_dec.decode("utf-8")} \nwith Private Key: \n{pvt_key_dec}")
