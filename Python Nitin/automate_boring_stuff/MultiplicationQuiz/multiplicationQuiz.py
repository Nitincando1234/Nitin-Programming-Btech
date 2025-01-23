import pyinputplus, time, random
numberOfQuestions = 10
correctAnswers = 0
try:
    for i in range(numberOfQuestions):
        num1, num2 = random.randint(0, 9), random.randint(0, 9)
        prompt = f"#{i + 1}: {num1} * {num2} = "
        try: pyinputplus.inputStr(prompt, allowRegexes = [r"^%s$" % (num1 * num2)], blockRegexes = [r"^.*$"], limit = 3, timeout = 10)
        except pyinputplus.TimeoutException: print("The time is up.")    
        except pyinputplus.RetryLimitException: print("You have reached the maximum number of tries.")
        else: print("Correct !"); correctAnswers += 1
        time.sleep(1)
except KeyboardInterrupt: print("\nYou have pressed Ctrl + C")
else: print("ScoreBoard: %d / %d" % (correctAnswers, numberOfQuestions))