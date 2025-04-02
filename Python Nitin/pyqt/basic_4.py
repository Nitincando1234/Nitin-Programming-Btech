from PyQt6.QtCore import QSize, Qt
from PyQt6.QtWidgets import QApplication, QMainWindow, QPushButton
import sys

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("My Window")
        button = QPushButton("Press Me !")
        self.setCentralWidget(button)
        self.setFixedSize(QSize(400, 300))
        
app = QApplication(sys.argv)
window = MainWindow()
# window.setMinimumSize(400, 400)
window.show()
app.exec()
