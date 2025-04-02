import pyinputplus
import hmac
import hashlib
from time import sleep

print("\033c")
msg = input("Enter the message for generation of the digital signature: ")
# print("\033c")
shared_key = pyinputplus.inputPassword("Enter the shared-key: ", timeout = 10, limit = 3)
auth_code = hmac.new(str.encode(shared_key), str.encode(msg), hashlib.sha256)
# print("\033c")

print(f"The Generated hash in Hex: {auth_code.hexdigest()}")
sleep(2)
# print("\033c")