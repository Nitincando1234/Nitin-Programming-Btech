# stopwatch - A simple stopwatch program.
import time
print("Press \"Enter\" to start the stopwatch. Afterward \"Enter\" to add laps. Press Ctrl + C to quit.")
input()
print("Started.")
startTime = time.time()
lastTime = startTime
numLaps = 1

try:
    while True:
        input()
        lapTime = round(time.time() - lastTime, 2)
        totalTime = round(time.time() - startTime, 2)
        numLaps += 1
        print("Lap #%s: %s (%s)" % (numLaps, totalTime, lapTime), end = "")
        lastTime = time.time()
except (KeyboardInterrupt):
    print("\nDone.")
