# textMyself.py - Defines the textmyself() function that texts a message 
# passed to it as a string.
from twilio.rest import Client

accountSID = str(input("Enter the accoundSID: ")) 
authToken = str(input("Enter the authToken: "))
twilioNumber = str(input("Enter the twilio number: "))
myNumber = "+91" + str(input("Enter the number to send message(excluding +91): "))
client = Client(accountSID, authToken)
def textMySelf(msg):
    client.messages.create(body = msg, from_ = twilioNumber, to = myNumber)

message = str(input("Enter your message to send: "))
textMySelf(message)
