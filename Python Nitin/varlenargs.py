def vlen(course,sem,*paper):
    print("Course: ",course)
    print("sem:",sem)
    print("Papers: ")
    for p in paper:
        print(p,end="\t")

vlen("B.Tech","Fourth","101","102","103","104")