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
        self.w = AnotherWindow()
        self.setWindowTitle("Main Window")

        self.setWindowTitle("New application")
        self.button = QPushButton("Push for New Window")
        self.button.pressed.connect(self.toggle_window)
        self.setCentralWidget(self.button)

    # def show_new_window(self):
    #     if self.w is None: self.w = AnotherWindow()
    #     self.w.show()

    def toggle_window(self):
        if self.w.isVisible(): self.w.hide()
        else: self.w.show()

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()