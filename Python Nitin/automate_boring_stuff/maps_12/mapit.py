# mapit.py - launches the maps in the browser using the address from the command line or clipboard
# Usage: python mapit.py <address> or python mapit.py
import webbrowser, sys, pyperclip
if len(sys.argv) > 1: address = " ".join(sys.argv[1:])
else: address = pyperclip.paste()
webbrowser.open("https://www.google.com/maps/place/" + address)