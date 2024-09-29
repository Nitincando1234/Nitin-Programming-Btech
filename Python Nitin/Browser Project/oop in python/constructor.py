class Speaker:
    def __init__(self,color,sound):
        try:
            if color in ['red','green','yellow','blue']:
                self.color=color    #private attributes
            else :
                raise Exception("Invalid Color !")
        except:
            print(Exception)
        self.sound=sound
speaker=Speaker("blue","rockstar")
print(f"color of speaker {speaker.color}\nsound {speaker.sound}")