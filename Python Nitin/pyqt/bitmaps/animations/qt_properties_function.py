from PyQt6.QtCore import pyqtProperty, QObject

class CustomObj(QObject):

    def __init__(self):
        super().__init__()
        self._value = None

    def getValue(self): return self._value

    def setValue(self, value): self._value = value

    value = pyqtProperty(int, getValue, setValue)

obj = CustomObj()
obj.value = 9
print(obj.value)