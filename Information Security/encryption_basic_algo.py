# write a program to perform encryption and decrtption using algorithms: caeser cipher, substitution cipher and hill cipher
import pyinputplus, collections, numpy

def caeser_cipher(inputStr):
    offset = pyinputplus.inputInt("Enter the offset for Encryption: ")
    modified_input = ["" for i in range(len(inputStr))]

    print("Encryption using Caeser Cipher: ")
    for i, c in enumerate(inputStr):
        base = ord("A") if c.isupper() else ord("a")
        modified_input[i] = chr((ord(c) + offset - base) % 26 + base)
    
    print("Encrypted Text: " + "".join(modified_input))
    print("Decrypted Text: ")
    for i, c in enumerate(inputStr):
        modified_input[i] = chr((ord(c) - offset - base) % 26 + base)
    
    print("Decrypted Text: " + "".join(modified_input))

def substitution_cipher(inputStr):
    replacementStr = pyinputplus.inputStr("Enter the Replacement String: ")
    mapper = collections.defaultdict(list)
    indexTracker = collections.defaultdict(int)
    encryptedText, decryptedText = [], []
    j = 0
    for i, c in enumerate(inputStr): 
        if j == len(replacementStr): j = 0
        encryptedText += replacementStr[j]
        mapper[replacementStr[j]].append(c)
        j += 1
    print("Encrypted Text: " + "".join(encryptedText))
    print(mapper)

    for c in encryptedText:
        if indexTracker[c] < len(mapper[c]):
            decryptedText += mapper[c][indexTracker[c]]
            indexTracker[c] += 1
    print("Decrypted Text: " + "".join(decryptedText))

def hill_cipher(inputStr):
    inputStr = inputStr.lower()
    n = pyinputplus.inputInt("Enter the dimension of Key Matrix: ")
    print(f"Enter the Key Matrix({n} * {n}): ")
    a = []
    row = []
    for _ in range(n):
        row = pyinputplus.inputStr()
        if len(row.split()) > n: row = row[: n].split()
        else: row = row.split()
        a.append(row)
    a = [[int(x) for x in a[i]] for i in range(n)]
    a = numpy.array(a)
    # c = numpy.array([])
    splitted_inputStr, offset = [], 0
    for i in range(0, len(inputStr), n):
        temp = list(inputStr[i: i + n])
        if len(temp) < n  and not len(inputStr) % 3 == 0: 
            offset = n - len(temp)
            for j in range(n - len(temp)): temp += "a"
        splitted_inputStr.append(temp)

    for arr in splitted_inputStr:
        temp = []
        for i, c in enumerate(arr): temp.append(c)
        arr = temp[: ]
    print(a)
    encrypted_lst = []
    for arr in splitted_inputStr:
        int_arr = numpy.array([(ord(c) - ord("a")) for c in arr])
        c = (int_arr @ a) % 26
        encrypted_lst.append(c)

    encrypted_lst_chr, temp = [], []
    for arr in encrypted_lst:
        temp = [] 
        for i in range(len(arr)):
            temp.append(chr(arr[i] + ord("a")))
        encrypted_lst_chr.append(temp)
    encrypedText, encrypedText_v = "", ""
    for i, arr in enumerate(encrypted_lst_chr): 
        temp = arr[: ]
        t = temp[-1]
        flag = 0
        if i == len(encrypted_lst_chr) - 1: temp = arr[: n - offset]; flag = 1
        encrypedText += "".join(temp)
        if flag: temp.append(t); encrypedText_v += "".join(temp)
        else: encrypedText_v += "".join(temp)
    
    print("Encrypted Text: " + encrypedText)
    # Decryption
    splitted_inputStr = []
    print(encrypedText_v)
    # encrypedText_v = encrypedText_v if len(inputStr) % 3 == 0 else encrypedText
    for i in range(0, len(encrypedText_v), n):
        temp = list(encrypedText_v[i: i + n])
        if len(temp) < n: 
            offset = n - len(temp)
            # for j in range(n - len(temp)): temp += "a"
        splitted_inputStr.append(temp)    
    decrypted_lst = []
    for arr in splitted_inputStr:
        int_arr = numpy.array([(ord(c) - ord("a")) for c in arr])
        c = (int_arr @ matrix_mod_inv(a, 26)) % 26
        decrypted_lst.append(c)
    decrypted_lst_chr, temp = [], []
    for arr in decrypted_lst:
        temp = [] 
        for i in range(len(arr)):
            temp.append(chr(arr[i] + ord("a")))
        decrypted_lst_chr.append(temp)
    decryptedText = ""
    for i, arr in enumerate(decrypted_lst_chr): 
        temp = arr[: ]
        if i == len(decrypted_lst_chr) - 1: temp = arr[: n - offset]
        decryptedText += "".join(temp)
    print("Decrypted Text: " + decryptedText)

def mod_inv(det, mod):
    for x in range(mod): 
        if (det * x) % mod == 1: return x
    raise ValueError("Modular Inverse not exists !")

def matrix_mod_inv(a, mod):
    n = a.shape[0]
    det = int(round(numpy.linalg.det(a)))  # Get integer determinant
    det = det % mod
    det_inv = mod_inv(det, mod)  # Modular inverse of determinant

    # Calculate matrix of cofactors
    cofactors = numpy.zeros_like(a)
    for r in range(n):
        for c in range(n):
            minor = numpy.delete(numpy.delete(a, r, axis=0), c, axis=1)
            cofactors[r][c] = ((-1) ** (r + c)) * int(round(numpy.linalg.det(minor)))

    adjugate = numpy.transpose(cofactors) % mod
    return (det_inv * adjugate) % mod



inputStr = pyinputplus.inputStr("Enter the Input String to Perform the cipher: ")
choice = pyinputplus.inputInt("Choose Algo for Encryption and Decryption: \n1. Caeser Cipher\n2. Substitution Cipher\n3. Hill Cipher: ")
if choice == 1: caeser_cipher(inputStr)
elif choice == 2: substitution_cipher(inputStr)
elif choice == 3: hill_cipher(inputStr)
else: print("Wrong Choice Made !")
