import sys
from PyQt6.QtWidgets import QApplication, QPushButton, QMainWindow

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("My App")
        button = QPushButton("Press Me!")
        button.setCheckable(True)
        button.clicked.connect(self.button_was_clicked)
        self.setCentralWidget(button)
    def button_was_clicked(self): print("Clicked !")
app = QApplication(sys.argv)
window = MainWindow()
window.show()

app.exec()
    