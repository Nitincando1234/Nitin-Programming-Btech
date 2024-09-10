class Speaker:
    def __init__(self,color,sound):
        self.color=color
        self.sound=sound
    def sounder(self):
        print(f"Sound is: {self.sound}")
    def colorprint(self):
        print(f"Color of the speaker: {self.color}")
class BluetoothSpeaker(Speaker):
    def __init__(self,color,sound,b_ver):
        super().__init__(color,sound)
        self.b_ver=b_ver
    def bverPrint(self):
        print(f"Bluetooth Version of the speaker: {self.b_ver}")
sound=input("Enter the song of the speaker: ")
color=input("Color of the speaker is: ")
b_ver=input("Bluetooth version of the speaker: ")
bs=BluetoothSpeaker(color=color,sound=sound,b_ver=b_ver)
bs.sounder()
bs.colorprint()
bs.bverPrint()
