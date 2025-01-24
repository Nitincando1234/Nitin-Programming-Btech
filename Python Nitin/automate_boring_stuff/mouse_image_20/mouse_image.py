import pyautogui, time 
time.sleep(5)
distance = 300
change = 20

try:   
    while distance > 0:
        pyautogui.drag(distance, 0, duration = 0.25)
        distance = distance - change
        pyautogui.drag(0, distance, duration = 0.25)
        pyautogui.drag(-distance, 0, duration = 0.25)
        distance = distance - change
        pyautogui.drag(0, -distance, duration = 0.25)
except pyautogui.FailSafeException:
    print("Ok! aborting\nDone.")