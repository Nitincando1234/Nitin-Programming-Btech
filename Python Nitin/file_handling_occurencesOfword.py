def occur():
    count=0
    search_word=input("Enter the word to search: ")
    with open("temp.txt","r") as file:
        for data in file:
            words=data.split()
            for word in words:
                if(word==search_word):
                    count+=1
    print(search_word," fount ",count," times in file:",file)
    file.close()
occur()