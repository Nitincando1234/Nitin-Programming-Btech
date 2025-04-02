import time
import sys
from PyQt6.QtWidgets import (QApplication, QMainWindow, QPushButton, QPlainTextEdit, QVBoxLayout, QWidget)
from PyQt6.QtCore import QProcess

class MainWindow(QMainWindow):

    def __init__(self):
        super().__init__()
        self.p = None

        self.button = QPushButton("Execute")
        self.button.pressed.connect(self.start_process)
        self.text = QPlainTextEdit()
        self.text.setReadOnly(True)

        layout = QVBoxLayout()
        layout.addWidget(self.button)
        layout.addWidget(self.text)

        w = QWidget()
        w.setLayout(layout)

        self.setCentralWidget(w)

    def add_message(self, s: str): self.text.appendPlainText(s)

    def start_process(self): 
        if self.p is None:
            self.process_name = "python"
            self.p = QProcess()
            self.add_message("Executing the process " + self.process_name)
            self.p.finished.connect(self.process_finished)
            self.p.start("python", ["dummpy.py"])
    
    def process_finished(self): 
        self.add_message("Process " + self.process_name + " finished")
        self.p = None

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()