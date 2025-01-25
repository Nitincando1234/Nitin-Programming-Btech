# countDown.py
import time, subprocess
count_time = int(input("Enter the seconds from which to start the count down: "))
while count_time > 0:
    print(f"Time Left: {count_time}", end = "\r", flush = True)
    time.sleep(1)
    count_time = count_time - 1

subprocess.Popen(["start", "alarm.wav"], shell = True)