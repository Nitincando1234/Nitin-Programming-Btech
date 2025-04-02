import sys
from PyQt6.QtWidgets import QApplication, QMainWindow, QPushButton, QWidget, QVBoxLayout, QLabel
from random import randint

class AnotherWindow(QWidget):
    def __init__(self):
        super().__init__()
        layout = QVBoxLayout()
        self.label = QLabel("Another Window % d" % randint(0, 100))
        layout.addWidget(self.label)
        self.setLayout(layout)

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        layout = QVBoxLayout()

        self.window1 = AnotherWindow()
        self.window2 = AnotherWindow()
        self.setWindowTitle("Main Window")

        self.setWindowTitle("New application")

        self.button1 = QPushButton("Push for New Window 1")
        self.button1.pressed.connect(self.show_new_window1)
        layout.addWidget(self.button1)
        self.button2 = QPushButton("Push for New Window 2")
        self.button2.pressed.connect(self.show_new_window2)
        layout.addWidget(self.button2)

        widget = QWidget()
        widget.setLayout(layout)
        self.setCentralWidget(widget)

    def show_new_window1(self):
        if self.window1.isVisible():
            self.window1.hide()
        else: 
            self.window1.show()

    def show_new_window2(self):
        if self.window2.isVisible():
            self.window2.hide()
        else: 
            self.window2.show()

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()