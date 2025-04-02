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
            self.p.readyReadStandardOutput.connect(self.handle_stdout)
            self.p.readyReadStandardError.connect(self.handle_stderr)
            self.p.stateChanged.connect(self.handle_state)
            self.p.finished.connect(self.process_finished)

            self.add_message("Executing the process " + self.process_name)
            self.p.finished.connect(self.process_finished)
            self.p.start("python", ["dummy_script_for_qprocess.py"])    

    def handle_stdout(self):
        data = self.p.readAllStandardOutput()
        stdout = bytes(data).decode("utf8")
        self.add_message(stdout)
    
    def handle_stderr(self):
        data = self.p.readAllStandardError()
        stderr = bytes(data).decode("utf8")
        self.add_message(stderr)
    
    def handle_state(self, state):
        # will convert these states to their string representations as they are enumerations by default
        states = {
            QProcess.ProcessState.NotRunning: "Not Running",
            QProcess.ProcessState.Starting: "Starting",
            QProcess.ProcessState.Running: "Running"
        }
        state_name = states[state]
        self.add_message(f"state changed: {state_name}")
    
    def process_finished(self): 
        self.add_message("Process \'" + self.process_name + "\' finished")
        self.p = None


app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()