def cnt(msg):
    lc={}
    for i in msg:
        lc[i]=lc.get(i,0)+1
    print(lc)
msg=input("Enter your message: ")
cnt(msg)