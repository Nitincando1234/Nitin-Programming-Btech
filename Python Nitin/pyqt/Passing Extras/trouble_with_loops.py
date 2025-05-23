from PyQt6.QtWidgets import QApplication, QPushButton, QWidget, QLabel, QVBoxLayout, QHBoxLayout
import sys

class Window(QWidget):

    def __init__(self):
        super().__init__()

        v = QVBoxLayout()
        h = QHBoxLayout()

        for a in range(10):
            button = QPushButton(str(a))
            button.pressed.connect(
                lambda val = a: self.button_pressed(val)
            )
            h.addWidget(button)
        
        v.addLayout(h)
        self.label = QLabel("")
        v.addWidget(self.label)
        self.setLayout(v)
    
    def button_pressed(self, n):
        self.label.setText(str(n))

app = QApplication(sys.argv)
window = Window()
window.show()
app.exec()