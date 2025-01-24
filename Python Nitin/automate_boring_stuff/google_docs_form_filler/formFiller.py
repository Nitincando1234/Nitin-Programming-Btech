# formFiller.py - auto fills the google form for you.
import pyautogui, time

formData = [{'name': 'Alice', 'fear': 'eavesdroppers', 'source': 'Wandb', 
            'robocop': 4, 'comments': 'Tell Bob I said hi.'},
            {'name': 'Bob', 'fear': 'bees', 'source': 'Orb', 'robocop': 4, 
            'comments': 'n/a'},
            {'name': 'Carol', 'fear': 'puppets', 'source': 'Staff', 
            'robocop': 1, 'comments': 'Please take the puppets out of the break room.'},
            {'name': 'Alex Murphy', 'fear': 'ED-209', 'source': 'Others', 
            'robocop': 5, 'comments': 'Protect the innocent. Serve the public trust. Uphold the law.'},
            ]
pyautogui.PAUSE = 0.5 # secs
print("Please make the screen active of the browser")
time.sleep(2)
for person in formData:
    print("\r>>> 5-SECOND pause is given you to Quit using CTRL-C", flush = True)
    time.sleep(5)
    print("Enterting info for %s" % (person["name"]))
    pyautogui.click(537,436)
    pyautogui.write(person["name"] + "\t")
    pyautogui.write(person["fear"] + "\t")
    pyautogui.write(["enter"], 0.5)
    if (person["source"] == "Wandb"): pyautogui.write(["Down", "enter", "\t"], 0.5)
    elif (person["source"] == "Orb"): pyautogui.write(["Down", "Down", "enter", "\t"], 0.5)
    elif (person["source"] == "Staff"): pyautogui.write(["Down", "Down", "Down", "enter", "\t"], 0.5)
    elif (person["source"] == "Others"): pyautogui.write(["Down", "Down", "Down", "Down", "enter", "\t"], 0.5)
    if person['robocop'] == 1: pyautogui.write([' ', '\t'] , 0.5)
    elif person['robocop'] == 2: pyautogui.write(['right', '\t'] , 0.5)
    elif person['robocop'] == 3: pyautogui.write(['right', 'right', '\t'] , 0.5)
    elif person['robocop'] == 4: pyautogui.write(['right', 'right', 'right', '\t'] , 0.5)
    elif person['robocop'] == 5: pyautogui.write(['right', 'right', 'right', 'right', '\t'] , 0.5)

    pyautogui.write(person["comments"] + "\t")
    pyautogui.sleep(1)
    pyautogui.write(["enter"])
    print("Submitted !")
    pyautogui.sleep(5)
    pyautogui.click(530,241)

print("Done !")

