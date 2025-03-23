from PyQt6.QtCore import pyqtProperty, QObject

class CustomObj(QObject):

    def __init__(self):
        super().__init__()
        self._value = 0
    
    @pyqtProperty(int)
    def value(self): return self._value

    @value.setter
    def value(self, value): self._value = value

obj = CustomObj()
obj.value = 8
print(obj.value)
