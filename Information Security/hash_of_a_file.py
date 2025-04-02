import hashlib, time

try:
    with open("my.txt", "r") as file:
        file_contents = file.read()
        print("\033c")
        print(f"Original File Contents: {file_contents}")
        time.sleep(5)
        print("\033c", "\r")
        algos = ["md5", "sha1", "sha256"]
        for algo in algos:
            if algo == algos[0]:
                md5_obj = hashlib.md5(str.encode(file_contents))
                print(f"Hex of Hash using md5: {md5_obj.hexdigest()}")
                time.sleep(5)
                print("\033c", "\r")
            elif algo == algos[1]:
                sha1_obj = hashlib.sha1(str.encode(file_contents))
                print(f"Hex of Hash using sha1: {sha1_obj.hexdigest()}")
                time.sleep(5)
                print("\033c", "\r")
            elif algo == algos[2]:
                sha256_obj = hashlib.sha256(str.encode(file_contents))
                print(f"Hex of Hash using sha256: {sha256_obj.hexdigest()}")
                time.sleep(5)
                print("\033c", "\r")
        else: print("Completed !")

except KeyboardInterrupt:
    print("\033c", "\r", "Interrupted !")
    time.sleep(2)
    print("\033c")